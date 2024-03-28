The main job of an expression is to produce a *value*, statements produce an *effect* and don't evaluate to a *value*.

```js
print "Hello world!"; // this is a statement
```

A `print` statement evaluates a single expression and displays the result to the user. An expression followed by a semicolon promotes an expression to a statement, this is known as an **expression statement**.

A series of statements can also be packed into one using a **block**:

```js
{
	print "One statement";
	print "Two statements";
}
```

Blocks also affect scoping.