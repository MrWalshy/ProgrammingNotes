A **namespace** is a domain for type names and form a part of the type's name:

```c#
namespace Outer.Middle.Inner
{
	class Foo {}
}
```

This is equivalent to:

```c#
namespace Outer
{
	namespace Middle
	{
		namespace Inner 
		{
			class Foo {}
		}
	}
}
```

Namespaces have no impact on their members visibility. A types *fully qualified name* is its type name and the namespaces from outermost to innermost, such as `Outer.Middle.Inner.Foo`. Types not defined in a namespace are in the *global namespace*.

## File-scoped namespaces
C#10 introduced file-scoped namespaces, this is useful when it is desired that all types in a file belong to the same namespace. Instead of:

```c#
namespace TheNamespace
{
	class Foo {}
	class Bar {}
}
```

The file-scoped variant can be used to apply to everything that follows in the file:

```c#
namespace TheNamespace;

class Foo {}
class Bar {}
```

## The `using` directive
The `using` directive imports a namespace, allowing for types to be referred to without their fully qualified names in a file:

```c#
using TheNamespace;

Foo f = new Foo();
```

The `using` directive can also be used in a namespace to limit the scope in which it applies:

```c#
namespace FooBar
{
	using TheNamespace;

	class Bar : Foo {}
}
```

### The `global using` directive
C#10 introduced prefixing the `using` directive with `global`, which then applies to all files in the project or compilation unit:

```c#
global using System;
```

- Must precede nonglobal directives
- Cannot appear inside namespace declarations
- Can be used with `using static`

### Implicit global usings
.NET 6 allows for implicit `global using` directives, this is done by setting the `ImplicitUsings` element to `true` in the project file (default for new projects) which automatically imports:

- `System`
- `System.Collections.Generic`
- `System.IO`
- `System.Linq`
- `System.Net.Http`
- `System.Threading`
- `System.Threading.Tasks`

Additional namespaces are imported based on the project SDK.

### `using static`
The `using static` directive imports a *type* instead of a namespace, all static members of the imported type can be used without qualification:

```c#
using static System.Console;

WriteLine("Hello");
```

## Aliasing types and namespaces
Sometimes, importing a namespace can result in a type-name collision. To handle this, specific types can be imported using an alias:

```c#
using PropertyInfo2 = System.Reflection.PropertyInfo;
```

Entire namespaces can also be aliased:

```c#
using R = System.Reflection;
```

## Advanced namespace features
### Extern
