///@brief delegating constructors are used to reduce code duplication
/// Calling constructor from another constructor

#include <iostream>
#include <string>
using namespace std;

class Person {
private:
  string name;
  int age;
  double weight;

public:
  Person() : Person("None", 0, 0) { cout << "no arg constructor is called\n"; }

  Person(string _name, int _age) : Person(_name, _age, 0) {
    cout << "2 arg constructor is called\n";
  }

  Person(string _name, int _age, double _weight)
      : name(_name), age(_age), weight(_weight) {
    cout << "3 arg constructor is called\n";
  }
};

int main() {

  cout << "creating default Person\n";
  Person defualt_Person;

  cout << "\ncreating Person with 2 args\n";
  Person p2("p2", 2);

  cout << "\ncreating Person with 3 args\n";
  Person p3("p3", 3, 30);
}