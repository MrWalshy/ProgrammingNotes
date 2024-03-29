Sometimes, a function needs to be used in a method that it was defined below or a circular dependency occurs which prevents an include in one file. To resolve this, forward declarations can be used where you declare the function prototype where needed but don't define it (this doesn't breach the single definition rule):

```cpp
void bar(); // forward declared

void foo() 
{
	bar();
}

void bar() {}
```