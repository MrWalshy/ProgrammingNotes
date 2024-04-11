When creating event systems, those which give interactions during play, can be created as:

- **Fixed systems**: Places and interactions are planned in advanced, forcing the player in to events at specific times and places.
- **Randomly generated**: Using randomness to challenge the player within specific timeframes, places, occurrences or events that may or may not occur.

Fixed systems limit replayability, but random systems can be hard to balance appropriately.

## Randomness
In computing, there is no true random software but complex mathematical systems can be used to get as close as possible. The amount of randomness needs to be just enough to fool the player into believing it is random. Such systems are known as **psuedo-random** number generators, using a number based on a seed with a maths algorithm to generate random numbers.

Developers sometimes implement random behaviour through *noise generating systems* (Perlin noise, fractals, Guassian drift, etc...), amongst other techniques. Combining techniques can be used to create complex random systems.

Basic random number generation systems also have an element of predictability, this can be used in procedural generation techniques for world building. This is possible because a certain sequence of numbers may occur predictably from a specific seed.

### True Randomness
**True Random Number Generators** can be used to generate what is closer to a truly random number, these generators make use of *entropy*. Due to this, they can be unreasonably expensive (computationally and resource-wise) to use them.

### Planning for randomness
It is important to consider where and when random behaviour in a game is necessary, this process shouldn't be rushed. Some questions to consider include:

- Does the feature actually need to be random or is it configurable?
- Where is randomisation necessary in the games design?
- In each place utilising random behaviour, how frequently will a random sample be needed?
- How complex does the random sampling/generation need to be?

## Basic AI
**Artificial Intelligence** in gaming is a term used in gaming to represent machine-based learning systems, the aim in gaming is to fool the player into thinking that the system behaves like a real being. Some systems used in this include:

- **Path-finding**: Helps AI entities navigate
- **Flocking**: Orders how AI entities within an area relate to each other
- **State machines**: Basic, fixed, sensor-driven intelligence driving AI actions
- **Rule-based expert systems**: Defined logic systems for AI entities to derive actions and aid in decision making processes
- **Neural networks**: Advanced learning networks for AI entities utilising machine learning
- **AI algorithms**: Used to reinforce neural networks and decision engines for more predictable behaviour.

## State machines
**Finite State Machines** are used to represent the various states that something can be in, at a basic level they operate by indicating:

- What state something is in now (what its doing)
- What state it was previously in (what it was doing)
- What the next states could be (what can be done next)

These state machines are commonly used for menu systems, game-level transitions, and AI/behaviours. Such state machines can be implemented in a variety of ways.

### Defining states
When producing a state machine, the collection of possible states needs to be decided on. This collection of states defines what states are in the game and what happens when a change in state occurs. Each states describes:

- What can happen when a state is active
- What other states can result in action from the current state

A simple state table for a TV could look like:


| State          | Description                                      | Actions                                                                                                                                                                                 |
| -------------- | ------------------------------------------------ | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| TV off         | No activity present, nothing displayed.          | Power button turns TV on.                                                                                                                                                               |
| TV on          | TV displays image and and plays sound.           | Power button turns TV off. Up button selects previous channel. Down button selects next channel. Menu button displays menu.                                                             |
| Menu displayed | TV displays menu, overlaying the normal display. | Power button turns TV off. Menu button turns TV on (hides menu). Up button highlights the previous menu item. Down button highlights the next menu item. OK button activates menu item. |
Once the collection of states is ready, an enumeration could be used to represent the states:

```c#
enum TelevisionState
{
	OFF,
	ON,
	MENU
}
```

### Simple singular choice state systems
The simplest state system would be made from conditional statements, such as using a `switch` statement to decide on an action to take:

```c#
if (Input.GetButtonDown("Up"))
{
	switch (currentTvState)
	{
		case TelevisionState.OFF:
			break;
		case TelevisionState.ON:
			// channel up
			break;
		case TelevisionState.MENU:
			// menu selection up
			break;
	}
}
```

As can be seen, such simple state systems are used for a single result. In this case, for when the `Up` button is pressed on the remote. Such a system works for menus, but not for systems where multiple things may need to occur as a result of a choice.

### Multiple choice state systems
The simple approach to a state system doesn't work well for complex scenarios, such as a group of enemies only battling if they are in a group and running if their health is low. It would result in spaghetti code when checking for the conditions using a `switch` statement. Instead, conditional `if` blocks can be used instead:

```c#
if (enemyState == State.IDLE)
{
	// check for player
	// if player found:
	// - set enemyState to State.ATTACKING
	// - check for friendly enemies
}
if (enemyState == State.ATTACKING && playerState == State.IDLE)
{
	// Enemy performs sneak attack on player
}
if (enemyState == State.ATTACKING)
{
	// Play battle music
}
if (enemyState == State.ATTACKING && enemyHealth < 5)
{
	// Enemy runs away
}
if (enemyState == State.ATTACKING && playerState == State.RUNNING_AWAY)
{
	// enemy chases player
}
```

Using conditional logic enables for fine control over what occurs when specific states occur, including multiple different actions. The main issue is that this code can become complex quite easily.

### State managers
Unity provides a built-in state machine system using the **Mecanim** animation system. This can be taken advantage of to build a state machine which is partially graphically managed, predominantly in controlling which states are available and how they transition. The actual actions as a result of state transitions, other than animations, need to be controlled in code.

To create this, the responsibilities for what occurs within the state system need to be separated into three main parameters:

- **Inputs**: What will be given to the state system to affect change
- **The decision engine**: The core logic driving the state machine
- **Outputs**: What the game does based on the current state

```
Interaction ---->  -------  ----> Reaction
Sensor      ----> | Logic | ----> Reaction
Action      ---->  -------  ----> Reaction
```

The state machine can then be made up of components, which makes it extensible allowing individual scripts to be applied to each input. The outputs/reactions can also be made into components.

### Sensors
A Mecanim state machine is powerful, by itself scripts can be used to update the parameters based on user input. If the AI systems need to be reactive though, sensors should be considered.

Sensors are the AI's eyes, ears, and anything else used to detect actions within a scene. They are, usually, self-contained components which inform whatever they are attached to of something.

A basic sensor could be an empty game object with a trigger collider, informing that enemy state machine that the player has come into view. Alternatively, ray casting could be used to check if the target is in view.