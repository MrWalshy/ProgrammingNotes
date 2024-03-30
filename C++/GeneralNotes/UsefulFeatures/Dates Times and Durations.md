C++ provides the `chrono` library for dealing with dates, times, and durations within a program. Include the `<chrono>` header file to use these features.

> [Date and time utilities - cppreference.com](https://en.cppreference.com/w/cpp/chrono)
## Chrono durations
The `std::chrono::duration` type is used to represent a period of time, the `chrono` library provides a variety of functions to express such durations. Some such functions are:

- `chrono::milliseconds(int)`
- `chrono::seconds(int)`
- `chrono::minutes(int)`
- `chrono::hours(int)`
- `chrono::days(int)`
- `chrono::weeks(int)`
- `chrono::months(int)`
- `chrono::years(int)`

The return type of these functions is `chrono::duration`, this type also has overloads for the `+=`, `-=`, `/=` and `*=` operators for combining durations and even comparison operators for comparing durations (`==`, `!=`, `<`, `<=`, `>`, `>=`).

> [std::chrono::duration - cppreference.com](https://en.cppreference.com/w/cpp/chrono/duration)

```cpp
#include <chrono>

int main()
{
	std::chrono::duration weeks1 = std::chrono::weeks(5);
	std::chrono::duration weeks2 = std::chrono::weeks(2);
	std::chrono::duration diff = weeks1 - weeks2;

	std::chrono::duration totalWeeks { weeks1 + weeks2 };
	std::chrono::duration doubleTotalWeeks { totalWeeks * 2 };

	std::chrono::duration totalWeeksAddDays { totalWeeks + std::chrono::days(3) };
}
```

### Duration literals
Literals exist for expressing durations, such as `h`, `min`, and `s`. The scope where they are expressed requires an appropriate `using` statement:

```cpp
#include <chrono>

int main()
{
	using namespace std::chrono;

	duration nHours{5h};
	duration nMinutes{5min};
	duration nSeconds{5s};
	duration nMilliseconds{5ms};
	duration nMicroseconds{5us};
	duration nNanoseconds{5ns};
}
```

### Duration `count()`
The underlying value of a `duration` object can be accessed using the `count()` method:

```cpp
#include <chrono>
#include <iostream>

int main()
{
	using namespace std::chrono;

	duration nHours{10h};
	std::cout << nHours.count() << " Hours" << std::endl; // 10 Hours
}
```

### Changing units with `duration_cast`
The `chrono` library provides a `duration_cast<T>(duration)` function for converting durations between measurements:

```cpp
#include <chrono>
#include <iostream>

int main()
{
	using namespace std::chrono;

	duration nHours{0.5h};
	duration hoursInMinutes{ duration_cast<minutes>(nHours) };
	std::cout << hoursInMinutes.count() << " Minutes" << std::endl; // 30 Minutes
}
```

### Pausing execution with `duration`s
Combining a `duration` object with the `this_thread::sleep_for(duration)` function of the `<thread>` library can allow pausing execution of the main thread for a given amount of time:

```cpp
#include <chrono>
#include <iostream>
#include <thread>

int main()
{
	using namespace std::chrono;

	duration sleepFor{10s};
	std::cout << "Starting..." << std::endl;
	std::this_thread::sleep_for(sleepFor); // sleep_for(10s) is also valid
	std::cout << "Finished." << std::endl;
}
```

## Chrono clocks
The `chrono` library offers clocks for a source of time information, 3 clocks are offered by default:

- `system_clock`: Simplest to use, uses data from the operating system's built in clock.
- `steady_clock`: Designed to not be impacted by changes to the system clock, useful to prevent users exploiting software by modifying the system clock.
- `high_resolution_clock`: Highly accurate, useful if millisecond, microsecond, or nanosecond accuracy is required. Useful for measuring performance as an example. This clock has the shortest tick period available.

Each clock is a typedef for a specific specialisation of `std::chrono::time_point`.

## Chrono time points
Each clock type definition can be used to generate values representing a specific point in time, these are represented by the `chrono::time_point` data type. On each clock, `now()` can be called to get the current time:

```cpp
#include <chrono>

int main()
{
	std::chrono::time_point currentTime { std::chrono::system_clock::now() };
}
```

Durations can also be added to and subtracted from time points:

```cpp
#include <chrono>

int main()
{
	std::chrono::time_point currentTime { std::chrono::system_clock::now() };
	std::chrono::time_point twoDaysAgo { currentTime - std::chrono::days(2) };
}
```

Durations can be created from comparing two time points:

```cpp
#include <chrono>
#include <iostream>
#include <thread>

int main()
{
	using namespace std::chrono;

	time_point startTime { system_clock::now() };
	std::this_thread::sleep_for(seconds(10));
	time_point endTime { system_clock::now() };

	duration runningTime { endTime - startTime };

	std::cout << "Time difference: " 
			  << duration_cast<milliseconds>(runningTime).count()
			  << "ms" << std::endl;
}
```

> When using `sleep_for`, a thing called *clock drift* occurs. Essentially, it will almost always sleep for slightly longer than specified. This can cause accuracy issues. If using multiple sleep calls in an iterative loop, that requires a high degree of accuracy, comparing the current time point with the previous time point will reveal the difference; auto correcting involves sleeping for the desired amount of time minus this difference.

## Using `std::time_t`
The `chrono` library is a relatively new addition to C++, the `std::time_t` type is an older way of time representation in C++ that may be used in some places.

The chrono clocks have a function available which allows for converting `chrono::time_point` objects to `std::time_t` objects. When using `system_clock`, this can be done with `system_clock::to_time_t(chrono::time_point)`:

```c++
std::chrono::time_point currentTime { std::chrono::system_clock::now() };
std::time_t currentTimeT { std::chrono::system_clock::to_time_t(currentTime) };
```

> `std::time_t` objects when printed to the console will display as an integer number, this is the number of seconds since the Unix epoch.

A `time_t` object can also be converted to a `time_point` object, the system clock has the function `from_time_t(std::time_t)` available for this:

```cpp
std::chrono::time_point currentTime { std::chrono::system_clock::now() };
std::time_t currentTimeT { std::chrono::system_clock::to_time_t(currentTime) };

std::chrono::time_point converted { 
	std::chrono::system_clock::from_time_t(currentTimeT) 
};
```

## Date and time structs
The Unix timestamp represented by `std::time_t` isn't user friendly, an alternative way to create time points is using `tm` structs; these can represent dates and times using their components.

The standard library `tm` struct has multiple member variables, like `tm_year`, `tm_hour`, `tm_min`, and more to represent the different parts of the timestamp. Two functions can be used to populate a `tm` object:

- `std::localtime_r(std::time_t*, std::tm*)`: This version is Linux friendly but may cause compilation errors on Windows. The first argument is a pointer to the `time_t` object, the second is the `tm` object which will be populated.
- `std::localtime_s(std::tm*, std::time_t*)`: This version is Windows friendly, the argument order is reversed but otherwise works the same.

If wanting to create a `time_t` object from a `tm` object, the `std::mktime(std::tm*)` function can be used. It is passed a pointer to a `tm` object and returns an object of `std::time_t`.

## Using `std::put_time` and format strings
The `std::put_time` function can be used for formatting `std::time_t` objects, this is useful for displaying dates and times in a user-friendly manner.

To use `std::put_time`, include the `<iomanip>` header file. The function can then be called with two arguments:

```cpp
std::put_time(std::tm*, std::string)
```

- The first argument is a pointer to the time container to use.
- The second is a string describing how the time should be formatted.

The function returns a string in the desired format. Some tokens that can be used in the format string include:

- `%Y`: Year as a decimal number
- `%y`: Year as a decimal number, last two digits only
- `%b`: Abbreviated name of month.
- `%B`: Full name of month.
- `%m`: Month as a decimal number between `01` and `12`
- `%e`: Day of the month as a decimal number between `01` and `31`
- `%R`: Prints a timestamp equivalent to `%H:%M`
- `%D`: Prints a timestamp equivalent to `%m/%d/%y`

> Reference: [std::put_time - cppreference.com](https://en.cppreference.com/w/cpp/io/manip/put_time)

