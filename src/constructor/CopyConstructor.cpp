#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

///@brief user defined overloaded constructor, copy constructor, and copy assignment operator

class Demo {
public:
  Demo() { cout << "No Arg Constructor is called\n\n"; }

  Demo(std::vector<int>) {
    cout << "Overloaded Constructor is called with one argument\n\n";
  }

  Demo(const Demo &temp) {
    cout << "Copy Cnstructor is called\n\n";
    copy_n(temp.vec.begin(), 3, this->vec.begin());
  }

  Demo &operator=(const Demo &temp);

  vector<int> vec{0, 0, 0};
};

Demo &Demo::operator=(const Demo &temp) {
  cout << "Copy Assignment operator is called\n\n";

  if (&temp == this) {
    return *this;
  }

  if (vec.size() != temp.vec.size()) {
    vec.resize(temp.vec.size());
  }

  copy(temp.vec.begin(), temp.vec.end(), vec.begin());
}

int main() {
  cout << "creating obj1 & initializing with 11 22 33\n";
  Demo obj1{{1, 2, 3}};

  cout << "creating obj2 from obj1\n";
  Demo obj2{obj1};

  cout << "\nobj2 elements are \n";
  for (auto ele : obj2.vec) {
    cout << ele << " ";
  }
  cout << endl;

  cout << "added element 44 to obj2\n\n";
  obj2.vec.push_back(44);

  cout << "creating obj3\n";
  Demo obj3;
  cout << "obj3 elements are \n";
  for (auto ele : obj3.vec) {
    cout << ele << " ";
  }
  cout << endl << endl;

  cout << "assigning obj2 to obj3\n";
  obj3 = obj2;

  cout << "obj3 elements are \n";
  for (auto ele : obj3.vec) {
    cout << ele << " ";
  }
  cout << endl;
}
