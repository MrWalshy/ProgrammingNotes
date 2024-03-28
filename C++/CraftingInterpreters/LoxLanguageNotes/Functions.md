Function call expressions look like C:

```js
doFoo(arg1, arg2);
doFoo();
```

Parentheses are mandatory for a function call, omitting them results in just a reference to its name.

Functions are defined using the `fun` keyword:

```js
fun printSum(a, b) {
	print a + b;
}
```

- **Arguments**, known as **actual parameters**, are values passed to a function when invoked.
- **Parameters**, known as **formal parameters**, are variables holding the value of an argument inside the functions body. A *function declaration* has a *parameter list*.

A functions body is always a block, a value can be returned using a `return` statement:

```js
fun returnSum(a, b) {
	return a + b;
}
```

Functions implicitly return `nil` if no `return` statement is present.

## Closures
Functions are first class, meaning they are real values that a reference to can be held, stored in variables, passed around, etc...

```js
fun addPair(a,b) { return a + b; }
fun identity(a) { return a; }

print identity(addPair)(1, 2); // 3
```

Function declarations are statements, so local functions can be declared inside other functions:

```js
fun outerFunc() {
	fun localFunc() {
		print "Local";
	}
	localFunc();
}
```

A closure can be obtained by using this behaviour, a local variable can be accessed outside of its original scope:

```js
fun getFunc() {
	var outside = "outside";

	fun inner() { print outside; }
	return inner;
}

var fn = getFunc();
fn();
```