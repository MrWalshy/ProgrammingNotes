The `break` keyword can be used to end a loop early:

```cpp
while (condition)
{
	statement;
	if (condition2) break;
}
```

The `continue` statement can be used to skip to the next iteration of a loop without executing the rest of its body in the current iteration:

```cpp
while (condition)
{
	if (condition2) continue;
	statement;
}
```

These statements can be used in both `while` loop and `for` loop variants.