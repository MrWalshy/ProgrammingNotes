An alternative selection statement which uses mutual exclusivity is the `switch` statement, it is limited to use with *constant expressions* as the predicates and is typically used when a known number of possible expressions exist:

```cpp
switch (expression)
{
	case constant1:
		statement(s);
		break;
	case constant2:
		statement(s);
		break;
	default:
		statement(s);
		break;
}
```

The expression evaluated by the `switch (expression)` line is compared against the cases, the matching case will have its statements executed. The `break` statement is important, this stops the cases *falling-through*; this is where the following cases statements are executed even if they never matched the expressions value.

The `default` case is matched if no other cases matched or allowed to run if a *fall-through* happens, this case is optional.