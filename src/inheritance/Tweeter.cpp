#include "Tweeter.hpp"
#include <iostream>

using std::string;
using std::endl;
using std::cout;

Tweeter::Tweeter(std::string first, std::string last, int arbitrary, std::string handle)
    : Person(first, last, arbitrary)
    , twitterHandle(handle)
{
    cout << "Tweeter : Constructor " << this->getName() << endl;
}

Tweeter::~Tweeter()
{
    cout << "Tweeter : Destructor " << this->getName() << endl;
}

std::string Tweeter::getName() const
{
    return (Person::getName() + " " + twitterHandle);
}