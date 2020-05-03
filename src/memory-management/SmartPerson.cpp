#include "SmartPerson.hpp"

using std::string;
using std::endl;
using std::cout;

SmartPerson::SmartPerson(std::string first, std::string last, int arbitrary)
    : firstName(first)
    , lastName(last)
    , arbitraryNumber(arbitrary)

{
    cout << "SmartPerson : Constructor " << this->getName() << endl;
}

std::string SmartPerson::getName() const
{
    return firstName + " " + lastName;
}

void SmartPerson::addResource()
{
    pResource.reset();
    pResource = std::make_shared<Resource>("Resource for " + getName());
}
