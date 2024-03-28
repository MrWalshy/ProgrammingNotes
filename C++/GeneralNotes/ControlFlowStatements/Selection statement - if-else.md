The `if` keyword can be used to indicate whether some statement or block should be executed depending on the fulfilment of some condition/predicate:

```cpp
if (predicate) statement;

if (predicate)
{
	statement1;
	statement2;
	statementN;
}
```

If the condition is not true, the statement or block will not be executed. The `else` keyword can be used to indicate that some other statement or block should be executed instead:

```cpp
if (predicate) statement1 else statement2;

if (predicate)
{
	statement(s);
}
else
{
	statement(s);
}
```

Branching logic can be performed using the `else if` keywords to allow for multiple conditional checks, these should be mutually exclusive in nature (not a hard rule, but recommended):

```cpp
if (predicate1) statement1;
else if (predicate2) statement2;
else if (predicate3) statement3;
else statement4;
```

Only the statement belonging to the matching predicate will be executed, all other statements will be ignored.