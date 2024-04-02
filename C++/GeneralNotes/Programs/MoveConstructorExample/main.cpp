#include <iostream>
#include <string>
#include <memory>
#include <utility>

struct Subresource
{
    Subresource()
    {
        std::cout << "Creating subresource" << std::endl;
    }

    Subresource(const Subresource& src)
    {
        std::cout << "Copying subresource (expensive)" << std::endl;
    }

    Subresource(Subresource&& src)
    {
        std::cout << "Moving subresource" << std::endl;
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

    Resource(Resource&& src): subresource(std::move(src.subresource))
    {
        std::cout << "Moving resource" << std::endl;
    }
};

int main()
{
    Resource original;
    Resource a{original};

    if (original.subresource.get()) std::cout << "original still has subresource" << std::endl;

    Resource b{std::move(original)};

    if (!original.subresource.get()) std::cout << "original no longer has a subresource after being moved" << std::endl;
}