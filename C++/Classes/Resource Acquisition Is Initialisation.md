**Resource Acquisition Is Initialisation** (RAII) is a programming idiom used to manage a resources lifecycle automatically by binding it to the lifetime of an object.

Using the constructor and destructor of an object can achieve RAII. The constructor would be used to acquire the resource and the destructor would release it. Importantly, the constructor may throw exceptions if the resource cannot be acquired but the destructor must never throw an exception.

It is normally good practice to operate on a resource via an instance of a RAII class when its usage involves function calls similar to/like `open()`, `close()`, `lock()`, `unlock()`, `start()`, `stop()`, `init()`, `destroy()`.

As an example, making use of streams to communicate with files, a RAII compliant class might look like:

```cpp
class FileHandle
{
	private:
	ofstream& _stream;

	public:
	FileHandle(ofstream& stream, const char* filepath) : _stream(stream)
	{
		_stream.open(filepath);
	}

	~FileHandle
	{
		_stream.close();
	}
}
```

This automatically closes the file once the `FileHandle` instance goes out of scope:

```cpp
ofstream stream;

{
	FileHandle aFile(stream, "path"); // file is opened
	foo(aFile);
} // file closed
```

This is safer than relying on manually closing the file with `stream.close()`, this is because a programmer may forget to close it or allocate memory which never gets destroyed.