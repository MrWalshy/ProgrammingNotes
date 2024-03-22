The `private` and `protected` members of a class are not accessible from within other functions and classes, this can be allowed by using the `friend` declaration to allow a function or class access to the private and protected members; this is known as declaring a **friend relationship**. The `friend` declaration has to be specified within the body of the class.

## Friend functions
A friend function is a non-member function with access to the private and protected members of a class. Two things are needed to allow this:

- Inside the class body, a function declaration preceded with the `friend` keyword.
- An associated function outside of the class preceded by the `friend` keyword.

```cpp
class ClassName
{
	Type1 member1;
	Type2 member2;

	public:
	friend void print(const ClassName &obj);
};

friend void print(const ClassName &obj)
{
	std::cout << obj.member1 << ", " << obj.member2 << std::endl;
}
```

## Friend classes
A friend class is possible as well by using the `friend` keyword, declaring one as such is like declaring all of its methods as friend functions.

> Friendship is not mutual. If one class is a friend of another, this is not automatically true for the opposite.

An example which demonstrates that friendship is not mutual:

```cpp
class A
{
	friend class B;
	int a = 0;
}

class B
{
	friend class C;
	int b = 0; 
}

class C
{
	int c = 0;

	void accessA(const A& object)
	{
		object.a;
		// Error! A.a is private, and C is not a friend of A
	}
}
```

Friendship is also not transitive, so members of class `C` cannot access members of class `A` just because class `C` is a friend of class `B`. In addition, `A` cannot access the private or protected members of `B` as `B` is a friend of `A` but `A` is not declared as a friend of `B`.