#include "Person.hpp"
#include <iostream>

using std::string;
using std::endl;
using std::cout;

Person::Person(std::string first, std::string last, int arbitrary)
    : firstName(first)
    , lastName(last)
    , arbitraryNumber(arbitrary)

{
    cout << "Person : Constructor " << this->getName() << endl;
}

std::string Person::getName() const
{
    return firstName + " " + lastName;
}

Person::~Person()
{
    cout << "Person : Destructor " << this->getName() << endl;
}
