A variety of programming techniques exist which can be used to better architect the codes structure, allowing for adding management of functionality instead of endlessly adding needless game objects for it.

## Singletons and managers
When projects become sufficiently complex, they often have a plethora of game objects which need to be managed as they are added and removed from a scene. Commonly, one of three patterns is used to manage this:

- Single instance managers
- Singletons
- Dependency-system

A **singleton** is a script that creates a single instance of itself, there are two main ways to implement this in Unity:

- A public static parameter within a class to maintain the runtime class instance. This allows other scripts to access it from anywhere in the game, it is useful when wanting events to cause the manager to do something; this could be related to the conversion system or traps for example.
- An empty game object in the scene with a singleton pattern script attached to it, this can cause conflicts if more than one pattern is added though.

A **manager** is a central script corresponding to a specific scene for controlling and maintaining the scenes flow, for one or more items.

### The manager approach (empty game objects)
To implement a manager approach using empty game objects, add a new empty game object to the hierarchy. Its position is not always important, although it could be in the case of something like a monster spawner. If it isn't important, it can be placed anywhere in the scene. Once this is done, create the manager script and then attach it to the empty game object.

A manager script for spawning enemy objects from a collection might look like:

```c#
public class EnemySpawnManager : MonoBehaviour { 
	public float spawnTime = 5f; // The amount of time between each spawn. 
	public float spawnDelay = 3f; // The amount of time before spawning starts. 
	public GameObject[] enemies; // Array of enemy prefabs. 
	
	void Start() { 
		// Start calling the Spawn function repeatedly after a delay. 
		InvokeRepeating("Spawn", spawnDelay, spawnTime); 
	} 
	
	void Spawn() { 
		// Instantiate a random enemy. 
		int enemyIndex = Random.Range(0, enemies.Length); 
		Instantiate(enemies[enemyIndex], transform.position, transform.rotation); 
	} 
}
```

- The `InvokeRepeating(string methodName, float time, float repeatRate)` method of the `MonoBehaviour` class is used to repeatedly invoke a specified method using a specific time interval.
- The `Instantiate(Object original, Vector3 position, Quaternion rotation)` static method of the `UnityEngine.Object` class accepts an object or prefab of which to create an instance of, returning a reference to the instantiated object.

Once the manager script has been created and attached to the empty game object, the **enemies** field will be visible in the script portion of the game object. The prefabs of the enemy types to spawn need to be assigned to this array, they can be simply dragged and dropped in to the array in the Unity editor.

### The singleton approach
The manager approach works in most cases, but requires controlling each instance of the controller where it is placed. It also cannot be interacted with or triggered without more configurations added to the `Manager` class, and then either binding the manager to other objects or using the `Find()` method to locate the object it belongs to.

A manager using the singleton pattern will look relatively simple, using the following pattern:

```c#
public class MySingletonManager : MonoBehaviour { 
	// Static singleton property 
	public static MySingletonManager Instance { 
		get; 
		private set; 
	} 
	//public property for manager 
	public string MyTestProperty = "Hello World"; 
	
	void Awake() { 
		//Save our current singleton instance 
		Instance = this; 
	} 
	//public method for manager 
	public void DoSomethingAwesome() {}
}
```

The methods of this singleton can then be easily called anywhere within the project like so:

```c#
MySingletonManager.Instance.DoSomethingAwesome();
```

Another common use of the singleton pattern is for any global state needed for the project. If intending to use the class across scenes, the `DontDestroyOnLoad()` method needs to be called to prevent it being destroyed when a scene unloads:

```c#
public class MySingletonManager : MonoBehaviour { 
	// Static singleton property 
	public static MySingletonManager Instance { 
		get; 
		private set; 
	} 
	//public property for manager 
	public string MyTestProperty = "Hello World"; 
	
	void Awake() { 
		// check for other conflicting instances
		if (Instance != null && Instance != this) Destroy(gameObject);
		// Save our current singleton instance 
		Instance = this; 
		// ensure instance is not destroyed between scenes
		DontDestroyOnLoad(gameObject);
	} 
	//public method for manager 
	public void DoSomethingAwesome() {}
}
```

- `gameObject` is a reference to the `GameObject` instance of which the script is attached, this reference is provided by Unity when working with MonoBehaviour scripts

## Communicating between GameObjects
When working with game objects, there may be any number of planned interactions between them such as:

- Physics collision tests
- Reacting to being shot or shooting
- Opening and closing doors
- Triggers, switches, or traps
- Two+ characters talking

There are several ways to implement this, such as:

- Delegates
- Events
- Messaging

### Delegates
A **delegate** is a method accepting pieces of work to do on the behalf of something else. C# has a form of delegates using the `Action` and `Action<T>` methods, which is a shorthand of the implementations explored here.

Two main patterns exist, the **configurable method pattern** and the **delegation pattern**.

#### The configurable method pattern
The **configurable method pattern** is used when a piece of work or function is passed to another method to be used to complete a task. This pattern is typically used where different chunks of code can perform a common task in unique ways, like walking, running, or patrolling.

The general syntax for a delegate looks like:

```c#
public class DelegateExample {
	delegate void RobotAction(); // delegate method signature
	RobotAction robotAction; // private field for delegate use

	void Start() {
		robotAction = RobotWalk; // default method for delegate
	}

	void Update() {
		robotAction(); // run selected delegate on update
	}

	public void DoRobotWalk() {
		robotAction = RobotWalk; // set delegate method to walk function
	}

	public void DoRobotRun() {
		robotAction = RobotRun;
	}

	void RobotWalk() {
		Debug.Log("Robot walking");
	}

	void RobotRun() {
		Debug.Log("Robot running");
	}
}
```

This class is an example of a simple state machine with no conditions, the delegate invoked on each call to `Update()` can be changed using the public `DoRobotWalk()` and `DoRobotRun()` methods.
#### The delegation pattern
The **delegation pattern** is used when a method calls out to a library of helper methods, once the task has been completed, control returns to the caller of the delegate. 

An example of the syntax for this might look like:

```c#
public class DelegateExample {
	public class Worker {
		List<string> workCompletedFor = new List<string>();

		public void DoSomething(string managerName, Action aDelegate) {
			workCompletedFor.Add(managerName); // audit work done for which manager
			aDelegate(); // start work
		}
	}

	public class Manager {
		private Worker worker = new Worker();

		public void PieceOfWork1() {}
		public void PieceOfWork2() {}
		public void DoWork() {
			worker.DoSomething("Manager1", PieceOfWork1);
			worker.DoSomething("Manager2", PieceOfWork2);
		}
	}
}
```

Alternatively, C# lambdas can be used instead of separate methods for the work:

```c#
public class Manager {
	private Worker worker = new Worker();

	public void PieceOfWork1() {}
	public void PieceOfWork2() {}
	public void DoWork() {
		worker.DoSomething("Manager1", PieceOfWork1);
		worker.DoSomething("Manager1", PieceOfWork2);
	}

	public void DoWork2() {
		worker.DoSomething("Manager1", () => {});
		worker.DoSomething("Manager1", () => {});
	}
}
```

#### Compound Delegates
The configurable method pattern and delegation pattern are powerful by themselves, compounding them can increase there flexibility and potential usage. Compounding delegates allows for assigning multiple functions to a single delegate, this means when the delegate is called that all the assigned methods will be called:

```c#
public class WorkerManager {
	void DoWork() {
		DoJob1();
		DoJob2();
		DoJob3();
	}

	private void DoJob1() {}
	private void DoJob2() {}
	private void DoJob3() {}
}
```

A more flexible example would look like:

```c#
public class WorkerManager {
	delegate void DelegateHook();
	DelegateHook actions;
	public string WorkerType = "Foo";

	void Start() {
		if (WorkerType == "Foo") {
			actions += DoJob1;
			actions += DoJob2;
		} else {
			actions += DoJob3;
		}
	}

	void Update() {
		actions();
	}

	private void DoJob1() {}
	private void DoJob2() {}
	private void DoJob3() {}
}
```

### Events
An **event** can be described as an expected announcement of something occurring. It is similar to a delegate in nature, but additional information about the event that occurred can also be passed along.

The following example utilises delegates to describe how the events will communicate, the delegate defines the form of the communication and what information is passed when the event is triggered:

```c#
public delegate void ClickAction(); // delegate method definition
public static event ClickAction OnClicked; // event hook using delegate method signature
```

When an event needs to be initiated in a class, it only needs to notify any other code listening to the event to invoke the event using a method with the delegates signature. It is important to check that the `delegate` is not `null`, if it is `null` it means no-one has subscribed to the event. An example of triggering an event might look like:

```c#
void Update() {
	if (Input.GetKeyDown(KeyCode.Space)) {
		// check if there is a subscriber
		if (OnClicked != null) {
			OnClicked(); // trigger the event delegate
		}
	}
}
```

Once the event is exposed, any other class or game object which needs to respond to the event can subscribe using the `+=` syntax:

```c#
void Start() {
	// hook on to the OnClicked event
	OnClicked += Events_OnClicked;
}

void Events_OnClicked() {
	Debug.Log("Button was clicked");
}

void OnDestroy() {
	OnClicked -= Events_OnClicked; // unsubscribe from the event
}
```

Rather than repeating the code for triggering the event in different places, it can be useful to write a single method used to specifically trigger the event:

```c#
void Clicked() {
	if (OnClicked != null) OnClicked();
}
```

Another example of this could be for logging when something happens:

```c#
public delegate void LogMessage(string message);
public static event LogMessage Log;

void OnLog(string message)
{
	if (Log != null) Log(message);
}
```

### Messaging
Communication is important in gaming, colliders or physics components are commonly used to notify two components that there is something to be aware of.

Unity has its own messaging-type methods like `SendMessage` and `BroadcastMessage`, these implement event-style code without actually declaring events. They are slow and shouldn't be used extensively though.

The `SendMessage` method invokes a named method on a `GameObject` with a single optional parameter:

```c#
void OnCollisionEnter(Collision collision) {
	collision.gameObject.SendMessage("Foo");
}
```

This would call a method called `Foo` on whatever object was collided with. This does not cause an error if whatever is collided with does not have a method called `Foo`. This can be changed by supplying `SendMessageOptions` when calling `SendMessage`:

```c#
void OnCollisionEnter(Collision collision) {
	collision.gameObject.SendMessage("Foo", SendMessageOptions.RequireReceiver);
}
```

If wanting to send a value, of which there can only be one, with the invocation, add it after the method name but before the `SendMessageOptions`.

The `BroadcastMessage` method works in a similar way, but it will attempt to run the specified method on the specified game object and all of its children:

```c#
void OnCollisionEnter(Collision collision) {
	collision.gameObject.BroadcastMessage("Foo");
}
```

### A better way of messaging
Using `SendMessage` and `BroadcastMessage` tightly couples the two involved objects, requiring references during design or discovery of each other at runtime to work. To break this, an intermediary `Manager` class can be utilised.

- The `Manager` class will manage the list of game objects that are listening for messages, providing an easy way of notifying any objects that are listening.
- Three classes, using singleton behaviour, can be created for this: `MessagingManager`, `MessagingClientBroadcast`, `MessagingClientReceiver`

The `Manager` class would look like:

```c#
public class MessagingManager : MonoBehaviour {
	public static MessagingManager Instance { get; private set; }
	private List<Action> subscribers = new List<Action>();

	void Awake() {
		Debug.Log("Messaging Manager started");
		if (Instance != null && Instance != this) Destroy(gameObject);
		Instance = this;
		DontDestroyOnLoad(gameObject);
	}

	public void Subscribe(Action subscriber) {
		Debug.Log("Registered subscriber");
		subscribers.Add(subscriber);
	}

	public void Unsubscribe(Action subscriber) {
		Debug.Log("Removing subscriber");
		subscribers.Remove(subscriber);
	}

	public void ClearAllSubscribers()
	{
		subscribers.clear();
	}

	public void Broadcast() {
		Debug.Log("Broadcast requested, Number of subscribers: " + subscribers.count);
		foreach (Action sub : subscribers) sub();
	}
}
```

- The `Instance` property is the singleton instance of the manager class.
- The `subscribers` property is a list of delegates used to keep track of which objects need to be notified.
- The `Awake()` method initialises the singleton
- The `Subscribe` and `Unsubscribe` methods are for registering and unregistering subscriber
- The `Broadcast()` method tells the messaging system to tell all the subscribers that something happened, in this case by looping through and invoking their delegates

This is a simple messenger that when called, just tells anyone listening that something happened. To finish the manager off, create an empty game object in a scene and add the script to it.

The broadcasting agent class would look like:

```c#
public class MessagingClientBroadcast : MonoBehaviour {
	void OnCollisionEnter2D(Collision2D collision) {
		MessagingManager.Instance.Broadcast();
	}
}
```

This script can be attached to an object with a 2D collider, which will then trigger a broadcast on a collision occurring.

As there are no listeners currently, another script can be created for listening for an event:

```c#
public class MessagingClientReceiver : MonoBehaviour {
	void Start() {
		MessagingManager.Instance.Subscribe(PlayerIsTryingToLeave);
	}

	void PlayerIsTryingToLeave() {
		Deubg.Log("Player is trying to leave - " + tag.ToString());
	}
}
```

This script can be attached to a game object to register with the manager, telling the manager to run the specified delegate when the event occurs.

## Background tasks and coroutines
Background tasks are useful when some task needs to be run independently of the normal game update and draw cycle.

This behaviour is useful for systems which continually run such as AI, trading systems, etc... It isn't designed for main events on the screen though.

Unity provides a way of synchronising background threads with a method which pauses the operation, or returns control back to Unity, until the games next frame is drawn (`WaitForEndOfFrame`, `WaitForFixedUpdate`). The benefit of this is the ability to wait for the last update or draw cycle to finish before running a process.

### Coroutines
**Coroutines** are used to implement long-running tasks in Unity, they are a way of running code in the background. They are also useful for creating methods which trigger after a set amount of seconds.

> By default, coroutines run on the same thread as the main game loop. This needs to be remembered as it can stop the game from running properly.

### IEnumerator
The `IEnumerator` generic interface in C# is used in creating an interface, a coroutine is a method returning this type. This allows Unity to track the state of a method through several iterations (invocations). A basic coroutine would look like:

```c#
IEnumerator MyCoroutine()
{
	// do something
	yield return null;
}
```

This is a simple single-use coroutine which performs a single action, being removed once it has finished execution.

A more common pattern is through using a loop within the coroutine that doesn't finish until some condition is met:

```c#
IEnumerator MyCoroutine()
{
	bool isFinished = false;
	while (!isFinished)
	{
		// do something, set isFinished to true when done

		// return control after each iteration
		yield return null;
	}
}
```

### Yielding
The `yield` operator suspends the method, which must return `IEnumerator`, it is called in. Control is returned to the caller, the coroutine will then be automatically resumed based on some statement. The `yield return null` would pause the coroutine for 1 frame. Other yield instructions like `WaitForSeconds` and `WaitForEndOfFrame` can be used.

```c#
IEnumerator Foo()
{
	for (int i = 0; i < 5; i++)
	{
		Debug.Log("Line " + i.ToString());
		yield return new WaitForSeconds(2); // waits at least 2 seconds before resuming
	}
}
```

### Starting coroutines
There are two subtypes of coroutine, both of which use the same code:

- Those that are launched
- Those that are managed

The difference is in how they are invoked. Launching a specific coroutine makes use of the `StartCoroutine` method:

```c#
StartCoroutine(MyCoroutine());
StartCoroutine(MyCoroutine(arg));
```

Once the coroutine is called, it won't stop until it has finished or the `StopAllCoroutines()` method is called.

A managed coroutine is started in a slightly different way, the name is specified instead of an invocation and any arguments to the coroutine are passed in:

```c#
StartCoroutine("MyCoroutine");
StartCoroutine("MyCoroutine", arg);
```

This allows for the coroutine to be stopped at any time using the `StopCoroutine` method:

```c#
StopCoroutine("MyCoroutine");
```

The managed way of launching should be used sparingly, it is slower as Unity has to discover the method specified in the string.

## Serialization and scripting
Unity serializes most things within the game automatically when it saves and loads the scene, everything from the editor to the scene. Serialization can be used within a game for saving and loading levels, bits of raw game data will be needed for this. The best way to accomplish this is using the Unity type named `ScriptableObject`, this type allows saving the data within the class that uses it in a `.asset` file in the project.

### Saving and managing asset data
First, a script needs to be created with the properties that are desired to be serializable:

```c#
public class ScriptingObjects : ScriptableObject
{
	public Vector2[] playerPositions;
}
```

To use the serializable data in the editor, an option in the editor needs to be created for creating and saving the assets. For this, create a new folder called `Assets/Scripts/Editor` and then add a new script called `PositionManager` in the `Editor` folder:

```c#
using UnityEditor;

public class PositionManager : MonoBehaviour
{
	[MenuItem("Assets/Create/PositionManager")] // define context menu option
	public static void CreateAsset()
	{
		// create an instance of the scriptable object
		ScriptingObjects positionManager = 
			ScriptableObject.CreateInstance<ScriptingObjects>();

		// create .asset file for the new object and save it
		AssetDatabase.CreateAsset(positionManager, "Assets/positionManager.asset");
		AssetDatabase.SaveAssets();

		// switch the inspector to the new object
		EditorUtility.FocusProjectWindow();
		Selection.activeObject = positionManager;
	}
}
```

> Any script with `using UnityEditor` should be placed in the `Editor` folder, this is to make sure it is only packed with the editor solution and the deployed game.
>
> If creating a custom class that should be serializable, the class must be tagged with the `[System.Serializable]` attribute for Unity to be aware of it.

Once this script has been added, right-clicking on the `Asset` folder and looking under the `Create` menu will show the new `PositionManager` menu option. Clicking it will create a new asset, visible in the **Project** view, which when selected will be visible in the **Inspector** view. Any data assigned to this new asset will be serialized as YAML data in the `.asset` file.

### Using serialized files in the editor
To use a serialized file in the editor, create a property in any script using the type of the serialized asset:

```c#
public ScriptingObjects MyWaypoints;
```

Once this has been done, select the script this property is in. In the **Inspector** pane, the properties will be visible.

The contents of a serialized file in the property cannot be edited by default, this requires a custom property inspector. It will still be editable in the editor by opening the `Asset` folder though.

### Accessing .asset files in code
If wanting to assign assets through code instead, `.asset` files can be directly loaded using code.

To do so, first the `.asset` files in a folder called `Asset/Resources`. Then read them from there using Unity's own resource functions. For example, the following could be added to the `PositionManager` script:

```c#
public static PositionManager ReadPositionsFromAsset(string name)
{
	string path = "/";
	object o = Resources.Load(path + name);
	PositionManager retrievedPositions = (PositionManager)o;
	return retrievedPositions;
}
```

This function reads the `.asset` file from the root of the `Resources` folder, converts the retrieved file to the correct type, then returns the deserialized object to the caller.

> This same pattern can be used for downloading `.asset` files from the web, they do required to be packaged as asset bundles for use in a scene though.


