With the battle state manager setup and attached to the `BattleManager` object, the script can be updated to make use of this.

> Mecanim uses hashes for objects rather than strings to identify states within the engine. A state's specific name can be checked for using `GetCurrentAnimatorStateInfo(0).IsName("Thingy")`.

A simple workaround for this issue is to generate and cache all the different state hashes, then use the cache when communicating with the Mecanim engine.

In the `BattleManager` script, remove the following pieces of code:

```c#
enum BattlePhase
{
	PLAYER_ATTACK,
	ENEMY_ATTACK
}

private BattlePhase battlePhase;
```

Also remove `phase = BattlePhase.PlayerAttack` from the `Start` method.

Then add an enumeration which mirrors the names of the states from the Mecanim battle state machine:

```c#
enum BattleState
{
    BEGIN_BATTLE, INTRO,
    PLAYER_MOVE, PLAYER_ATTACK,
    CHANGE_CONTROL, ENEMY_ATTACK,
    BATTLE_RESULT, BATTLE_END
}
```

Add two fields for hashing the Mecanim states and the current battle state to the `BattleManager`:

```c#
private Dictionary<int, BattleState> battleStateHash = new Dictionary<int, BattleState>();
private BattleState currentBattleState;
```

Then add a method for generating the hashes of the battle states:

```c#
void GetAnimationStates()
{
    foreach (BattleState state in (BattleState[]) System.Enum.GetValues(typeof(BattleState)))
    {
        battleStateHash.Add(Animator.StringToHash(state.ToString()), state);
    }
}
```

- The values in `BattleState` need to exactly match the names of the states in the Mecanim animator controller

Then call this method in the `Start()` method of `BattleManager`. Now update the `Update()` method to switch on the different battle states:

```c#
private void Update()
{
	if (currentBattleState == BattleState.PLAYER_ATTACK)
	{
	    buttons.alpha = 1;
	    buttons.interactable = true;
	    buttons.blocksRaycasts = true;
	}
	else
	{
	    buttons.alpha = 0;
	    buttons.interactable = false;
	    buttons.blocksRaycasts = false;
	}
	
    int hash = battleStateManager.GetCurrentAnimatorStateInfo(0).shortNameHash;
    currentBattleState = battleStateHash[hash];

    switch (currentBattleState)
    {
        case BattleState.INTRO:
            break;
        case BattleState.PLAYER_MOVE:
            break;
        case BattleState.PLAYER_ATTACK:
            break;
        case BattleState.CHANGE_CONTROL:
            break;
        case BattleState.ENEMY_ATTACK:
            break;
        case BattleState.BATTLE_RESULT:
            break;
        case BattleState.BATTLE_END:
            break;
        default:
            break;
    }
}
```

## Starting the battle
While the battle is loading, the `BEGIN_BATTLE` state is what the Mecanim animator is currently in. To transition this to the next state, the `BattleReady` property needs to be set to `true`. Do this in the `SpawnEnemies` coroutine after it has finished spawning the enemies:

```c#
battleStateManager.SetBool("BattleReady", true);
```