A component on a game object is a type derived from `Monobehaviour`. All game objects inherit from the `GameObject` class, this provides to main ways to assign or retrieve game objects in a current scene:

1. The `GetComponent()` or `Find()` methods of the `GameObject` class, which can access both `public` and `private` variables. `GetComponent()` is more performant, `Find()` should never be called in the `Update()` method.
2. Game objects can be dragged and dropped onto variable slots in the Unity Inspector, this only works with `public` variables or `private` variables marked with the `[SerializeField]` attribute.

## Accessing components via code
The `GameObject.GetComponent<ComponentType>()` instance method will return a component if it exists on the given object and `null` otherwise:

```c#
public class LearningCurve : MonoBehaviour
{
    public Transform CameraTransform;

    void Start()
    {
        CameraTransform = GetComponent<Transform>();
    }
}
```

The `localPosition` property of the `Transform` object could then be accessed:

```c#
Debug.Log(CameraTransform.localPosition);
```

Components can only be accessed with `GetComponent` on the object it is called on, components on a different object require first finding that object:

```c#
public class LearningCurve : MonoBehaviour
{
    public Transform CameraTransform;
    public GameObject DirectionLight;

    void Start()
    {
        CameraTransform = GetComponent<Transform>();
        DirectionLight = GameObject.Find("Directional Light");
    }
}
```

The `GameObject.Find(string name)` method finds the game object using its name. Components can then be retrieved using the game object: `DirectionLight.GetComponent<Transform>()` for example.