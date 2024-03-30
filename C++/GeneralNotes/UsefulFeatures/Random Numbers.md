C++ provides functionality for generating random numbers, generating a random number requires 3 things:

1. **Seeder**: Creates an initial random number to act as a seed for randomness
2. **Engine**: This uses the seed to generate further random numbers
3. **Distributor**: Converts random numbers into a desired range

## Seeding an RNG
A random number generator (RNG) requires an unpredictable input known as a *seed* to, this has to be acquired using a special type from the standard library. This is to prevent the random numbers from being predictable given computers are deterministic machines.

The simplest way of doing this is using a variable of type `random_device` from the `<random>` header file to request the value from the OS:

```cpp
#include <random>

int main()
{
	std::random_device seeder;
}
```

The operating system will use **sources of entropy** to generate the seed.

## Random number engines
As generating a seed requires a source of entropy, it is a naturally expensive process as entropy has to build up over time.

Special algorithms exist, known as random number engines, which accept a seed and use that to generate further random numbers. The `<random>` namespace provides such algorithms, one being that of the *Mersenne Twister* through the `std::mt19937` type:

```cpp
#include <random>

int main()
{
	std::random_device seeder;
	std::mt19937 engine { seeder() };
}
```

- `std::random_device` is a functor

## Random number distributions
When generating a random number, a range of values is usually wanted in which the random number should exist.

The standard library provides the `std::uniform_int_distribution` for specifying a range, which is also a functor that when called will generate a random number in the given range when supplied with a random number engine:

```cpp
#include <random>
#include <iostream>

int main()
{
	std::random_device seeder;
	std::mt19937 engine { seeder() };
	std::uniform_int_distribution getRandomInt { 1, 10 };

	int num1 = getRandomInt(engine);
	int num2 = getRandomInt(engine);

	std::cout << "num1: " << num1 << std::endl;
	std::cout << "num2: " << num2 << std::endl;
}
```

## Uniform and Normal Distributions
A **uniform distribution** is one where each number in the given range is equally likely to be generated.

In a **normal distribution**, the numbers more likely to be generated are those closer to the centre of the range and the numbers furthest from the centre are the least likely.

## Random booleans
Sometimes, it is useful to generate a *random boolean* based on a range; example from what I'm reading uses gaming as an example, like a critical strike happening only every *x*% of the time.

```cpp
std::random_device seeder;
std::mt19937 engine { seeder() };

bool getRandomBool(float probability)
{
	std::uniform_real_distribution get { 0.0, 1.0 };
	return probability > get(engine);
}
```

In this example, `uniform_real_distribution` is used to generate a random floating-point value within a range. Comparing this to a probability, such as `0.2` for `20%`, can be used to generate a `true` boolean value only 20% of the time as an example.

## Controlling the seed
When producing a seed for use in an engine, the type is `unsigned int`. The `random_device` functor returns a value of this type:

```cpp
std::random_device seeder;
unsigned int seed { seeder() };
std::mt19937 engine { seed };
```

It's possible to also change the seed that an engine is currently using with the `seed()` method:

```cpp
std::random_device seeder;
unsigned int seed { seeder() };
std::mt19937 engine { seed };

// change the seed
seed = 12345;
engine.seed(seed);
```

