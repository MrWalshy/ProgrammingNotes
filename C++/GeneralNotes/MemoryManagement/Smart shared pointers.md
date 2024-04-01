Unlike a `std::unique_ptr`, the `std::shared_ptr` type allows for multiple pointers to share ownership of a single resource. The resource will only be destroyed when the last shared pointer to the resource is destroyed or reset.

The mechanism allowing for this to occur is known as **reference counting**, the `std::shared_ptr` keeps a count of how many other pointers are referring to the same resource; this has a performance cost though.

## Creating a shared pointer with `std::make_shared()`
The `std::make_shared()` function, from the `<memory>` header, is used to create an instance of `std::shared_ptr`:

```cpp
auto sharedPtr { std::make_shared<int>(10) };
```

Like with `std::make_unique`, any arguments passed are provided to the owned objects class constructor during instantiation of the object in dynamic memory.

## Using shared pointers
Shared pointers, for the most part, are similar in usage to unique pointers:

- They can be dereferenced using `*` and `->` operators
- The underlying raw pointer can be accessed with the `get()` member
- Ownership can be transferred using `std::move()`
- Ownership can be swapped using the `swap()` member
- Ownership can be reset using the `reset()` member, the main difference here is that the underlying resource is only deleted if no other shared pointers refer to it

## Sharing ownership
Shared pointers can be *shared* by making a copy of them using the copy constructor or copy assignment operator:

```cpp
auto ptr1 { std::make_shared<int>(10) };
auto ptr2 { ptr1 }; // copy constructor
auto ptr3 = ptr1; // copy-assignment operator
```

Unlike unique pointers, this also allows for copies to be made by passing the shared pointer by value to a function:

```cpp
void foo(std::shared_ptr<int> ptr) {}

int main()
{
	auto ptr { std::make_shared<int>(10) };
	foo(ptr);
}
```

When making a copy, the copy needs to be made from an existing shared pointer rather than a variable of the underlying type otherwise the shared pointers will not be aware that they are managing the same object.
## Getting the owner count using `use_count()`
The `use_count()` member function can be invoked to get the number of current owners of a shared pointer:

```cpp
auto ptr1 { std::make_shared<int>(10) };
auto ptr2 { ptr1 }; // copy constructor

std::cout << "Owners: " << ptr1.use_count() << std::endl; // 2
```

## Casting shared pointers
Raw pointers can be cast to other types using `dynamic_cast` and `static_cast`, shared pointers can also be cast but using `std::dynamic_pointer_cast` and `std::static_pointer_cast` instead.

- If `std::dynamic_pointer_cast` fails, it returns an empty shared pointer. Empty shared pointers evaluate to `false` when converted to a boolean like pointers when `dynamic_cast` is used.

```cpp
class Character
{
	public:
		virtual ~Character() = default;
};

class NonPlayerCharacter: public Character {};

void Downcast(shared_ptr<Character> character)
{
	auto npcPointer { std::dynamic_pointer_cast<NonPlayerCharacter>(character) };

	if (npcPointer) std::cout << "It's an NPC" << std::endl;
	else std::cout << "It's not an NPC" << std::endl;
}
```

## Owning and pointing at different objects
Shared pointers have the ability to share ownership over an object whilst pointing at different objects, this is particularly useful for pointing to a member of an owned object which then prevents the owning object of the member from being deleted until that shared pointer, and all others, are released.

To do this, the *aliasing constructor* of the `std::shared_ptr` type is used with two arguments:

1. The first argument is the object to be owned by the shared pointer, it is passed in the form of a `std::shared_ptr` to copy.
2. The second argument is a pointer to the object to be referred to by the shared pointer.

```cpp
struct Player
{
	std::string name;

	Player(std::string name): name(name) {}
};

int main()
{
	auto playerPtr { std::make_shared<Player>() };
	std::shared_ptr<std::string> playerName(playerPtr, &playerPtr->Name);

	std::cout << "Name: " << *playerName << std::endl;
	std::cout << "Owners: " << playerPtr.use_count() << std::endl;
}
```