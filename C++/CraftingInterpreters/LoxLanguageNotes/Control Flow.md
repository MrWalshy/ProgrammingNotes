Control flow statements allow for some parts of code to be skipped or executed more than once, Lox uses three statements straight from C.

## If statements

An `if` executes one of two statements based on some condition:

```js
if (condition) {
	print "Yes";
} else {
	print "No"
}
```

## While statements
A `while` loop executes its body of statements repeatedly while its condition holds `true`:

```js
var a = 1;
while (a < 10) {
	print a;
	a = a + 1;
}
```

## For statements
Similar to a `while` loop, it executes its body while a condition holds true:

```js
for (var a = 1; a < 10; a++)
{
	print a;
}
```

