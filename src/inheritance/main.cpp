#include "Tweeter.hpp"
#include <iostream>

using std::cout;
using std::endl;


void variedAccessors()
{
    Person prasanna("Prasanna", "Bhat", 38);
    Person& rP_Person = prasanna;
    Person* pP_Person = &prasanna;

    Tweeter prasannaBhat("Prasanna", "Bhat", 30, "@prasanna_bhat");
    Person& rP_tweeter = prasannaBhat;
    Person* pP_tweeter = &prasannaBhat;
    Tweeter& rT_tweeter = prasannaBhat;
    Tweeter* pT_tweeter = &prasannaBhat;

    cout << rP_Person.getName() << endl;
    cout << pP_Person->getName() << endl;

    cout << prasannaBhat.getName() << endl;
    cout << rP_tweeter.getName() << endl;
    cout << pP_tweeter->getName() << endl;
    cout << rT_tweeter.getName() << endl;
    cout << pT_tweeter->getName() << endl;
}

void virtualDestructor()
{
    Person* person = new Tweeter("Prasanna", "Bhat", 30, "@prasanna_bhat");
    cout << person->getName() << endl;
    delete person;
}


int main(int argc, char const* argv[])
{
    // variedAccessors();
    // virtualDestructor();
    Tweeter t1 = Tweeter("Prasanna", "Bhat", 30, "@prasanna_bhat");
    return 0;
}
