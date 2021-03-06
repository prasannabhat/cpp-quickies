#include "Person.hpp"

using std::string;
using std::endl;
using std::cout;

Person::Person(std::string first, std::string last, int arbitrary)
    : firstName(first)
    , lastName(last)
    , arbitraryNumber(arbitrary)
    , pResource(nullptr)

{
    cout << "Person : Constructor " << this->getName() << endl;
}

Person::Person(Person const& p)
{
    cout << "Person : Cp Constructor " << this->getName() << endl;
    pResource = new Resource(p.pResource->getName());
}

Person& Person::operator=(const Person& p)
{
    if (this != &p)
    {
        delete pResource;
        pResource = new Resource(p.pResource->getName());
    }
    return *this;
}

std::string Person::getName() const
{
    return firstName + " " + lastName;
}

Person::~Person()
{
    cout << "Person : Destructor " << this->getName() << endl;
    delete pResource;
}

void Person::addResourceLeak()
{
    pResource = new Resource("Resource for " + getName());
}

void Person::addResource()
{
    delete pResource;
    pResource = new Resource("Resource for " + getName());
}
