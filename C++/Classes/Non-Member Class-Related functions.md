A non-member class-related function is one that is not defined in a class but conceptually belongs to its interface.

```cpp
class Circle
{
	public:
	int radius;
}

ostream& print(ostream& os, const Circle &circle)
{
	os << "Circle's radius: " << circle.radius;
	return os;
}
```


