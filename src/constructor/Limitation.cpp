///@brief compiler generated constructor do memberwise copy, if there is raw pointer then it will simply copy 
/// memory address and not the value its pointing to, in such scenario when one of the object goes out of scope
/// its destructor will d=be called and it will release the memory 

#include <iostream>
using namespace std;

#if 1
class Demo {
public:
  int *ptr;

  ~Demo() {
    cout << "destructor is called" << endl;
    // ptr = nullptr;
    delete ptr;
  }
};

int main() {

  Demo obj1;
  obj1.ptr = new int(51);
  cout << "obj1.ptr = " << obj1.ptr << endl;
  cout << "*obj1.ptr = " << *obj1.ptr << endl;

  {
    Demo obj2(obj1);
    cout << "\nobj2.ptr = " << obj2.ptr << endl;
    cout << "*obj2.ptr = " << *obj2.ptr << endl;
  }

  cout << "\n*obj1.ptr = " << *obj1.ptr << endl;
}
#endif

/***************************************END**********************************************/

#if 0
class Demo {
public:
  int *ptr;

  Demo() {}

  Demo(const Demo &temp) {

    ptr = new int;
    *ptr = *temp.ptr;
  }
  ~Demo() {
    cout << "destructor is called" << endl;
    delete ptr;
  }
};

int main() {

  Demo obj1;
  obj1.ptr = new int(5);
  cout << "obj1.ptr = " << obj1.ptr << endl;
  cout << "*obj1.ptr = " << *obj1.ptr << endl;

  {
    Demo obj2(obj1);
    cout << "\nobj2.ptr = " << obj2.ptr << endl;
    cout << "*obj2.ptr = " << *obj2.ptr << endl;
  }

  cout << "\n*obj1.ptr = " << *obj1.ptr << endl;
}
#endif
