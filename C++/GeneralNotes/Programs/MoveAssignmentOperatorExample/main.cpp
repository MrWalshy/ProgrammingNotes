#include <memory>
#include <utility>
#include <iostream>

struct Subresource
{
    Subresource()
    {
        std::cout << "Creating subresource" << std::endl;
    }

    Subresource(const Subresource& src)
    {
        std::cout << "Copying subresource" << std::endl;
    }

    Subresource& operator=(const Subresource& src)
    {
        std::cout << "Copying subresource via assignment" << std::endl;
        return *this;
    }
};

struct Resource
{
    std::unique_ptr<Subresource> subresource;

    Resource(): subresource(std::make_unique<Subresource>())
    {
        std::cout << "Creating resource" << std::endl;
    }

    Resource(const Resource& src): subresource(std::make_unique<Subresource>(*src.subresource))
    {
        std::cout << "Copying resource" << std::endl;
    }

    Resource& operator=(const Resource& src)
    {
        if (this != &src)
        {
            subresource = std::make_unique<Subresource>(*src.subresource);
        }
        return *this;
    }

    Resource(Resource&& src): subresource(std::move(src.subresource))
    {
        std::cout << "Moving resource constructor" << std::endl;
    }

    Resource& operator=(Resource&& src)
    {
        if (&src != this)
        {
            std::cout << "Moving resource via assignment" << std::endl;
            subresource = std::move(subresource);
        }
        else
        {
            std::cout << "Objects are the same, no movement occurs" << std::endl;
        }

        return *this;
    }
};

int main()
{
    Resource original;

    if (original.subresource.get()) std::cout << "original still has subresource" << std::endl;

    std::cout << "Resource a" << std::endl;
    Resource a;
    a = std::move(original);

    if (original.subresource.get()) std::cout << "original no longer has subresource" << std::endl;
}