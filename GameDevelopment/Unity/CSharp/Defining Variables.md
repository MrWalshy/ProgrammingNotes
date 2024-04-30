C# variables are defined with the following syntax:

```c#
DataType Name = value;
```

Variables defined as a field on a class may also have an access specifier:

```c#
AccessModifier DataType Name = value;
```

Example:

```c#
class Foo {
	public int bar = 10;
}
```

- `public` fields will be visible in the Unity Editor when the script is attached to a game object

The `Debug.Log` method can be called to print out data to the console:

```c#
public class LearningCurve : MonoBehaviour
{
    public int CurrentAge = 30;

    // Start is called before the first frame update
    void Start()
    {
        Debug.Log(CurrentAge);
    }
}
```

## Inferred declarations
If a value is assigned to a variable at declaration, its type can be inferred and so the `var` keyword can be used:

```c#
var age = 10;
```



