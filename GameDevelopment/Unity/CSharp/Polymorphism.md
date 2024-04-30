- Derived classes can be stored in variables of their parent type.
- Parent classes can mark methods as `virtual`, meaning that they can have their behaviour changed in derived classes using the `override` keyword

```c#
class Parent 
{
	public virtual void Foo() 
	{
		Debug.Log("Parent.Foo()");
	}
}

class Child: Parent
{
	public override void Foo() 
	{
		Debug.Log("Child.Foo()");
	}
}
```

Even if the child type is stored in a parent type variable, the modified version will be invoked:

```c#
Parent obj = new Child();
obj.Foo(); // Child.Foo()
```

