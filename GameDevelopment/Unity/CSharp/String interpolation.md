String interpolation allows for format strings to be created by directly inserting the desired variable/value:

```c#
int age = 10;
Debug.Log($"Inserted value {age} here");
```

The `Debug.LogFormat` method allows an alternative way of interpolating values into the string:

```c#
Debug.LogFormat($"Inserted value {0} here", age);
```

