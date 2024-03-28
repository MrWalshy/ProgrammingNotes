Lox has dynamic typing, lexical scope, and closures. It also has classes which make it part object-oriented as well as functional.

There are two common approaches to objects in a language:
- **Prototypes**: Prototype languages merge instances and classes, there are only objects and no classes. Each individual object may contain state and methods, and can directly inherit from each other (known as delegating to in prototype systems).
- **Classes**: Came first and are more common. Two core concepts, instances and classes. An instance stores the state for each object has a reference to the instance's class. Classes contains the methods and inheritance chain, method calls involve indirection as it requires looking up the instances class.

## Lox classes
Lox uses the class based system, they are declared using the `class` keyword:

```js
class Foo {
	foo() {
		print "Method: foo()";
	}

	bar() {
		print "Method: bar()";
	}
}
```

The class body contains methods, they are function declarations without the `fun` keyword essentially. They are bound to the class. Classes are also first class in Lox:

```js
var someVar = Foo;
someFunc(someVar);
```

Lox makes each class also a *factory function*, meaning calling a class like a function creates a new instance:

```js
var foo = Foo();
print foo;
```

## Instantiation and initialisation
Lox allows for properties to be dynamically bound to objects at runtime:

```js
foo.prop1 = 10;
foo.prop2 = "Hi";
```

Assigning to a field creates it if it doesn't yet exist.

To access a field or method on an object from within a method, use the `this` keyword:

```js
class Foo {
	bar() {
		print this.foo;
	}
}
```

An initialiser can be created (a constructor) using the `init()` method, which automatically called when the object is initialised:

```js
class Foo {
	init(a, b) {
		this.a = a;
		this.b = b;
	}
}

// usage
var foo = Foo(10, 20);
print foo.a;
```

## Inheritance
Lox supports single-inheritance using the `<` operator:

```js
class Bar < Foo {
	
}
```

Every method defined in the superclass, `Foo`, is available in the subclass, `Bar`. This includes the `init` method. To call a method from a superclass in the subclass, use the `super` keyword:

```js
class Bar < Foo {
	init(a, b, c) {
		super.init(a, b);
		this.c = c;
	}
}
```