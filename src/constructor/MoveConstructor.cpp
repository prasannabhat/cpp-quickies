#include <iostream>
#include <vector>
using namespace std;

class Demo
{
public:
    int *ptr;

    Demo()=default;                   ///default constructor
    Demo(int size);                   ///overloaded constructor
    Demo(const Demo &rhs);            ///Copy Constructor
    Demo &operator=(const Demo &rhs); ///Copy assignment operator
    Demo(Demo &&rhs);                 ///Move Constructor
    Demo &operator=(Demo &&rhs);      ///Move assignment constructor
    Demo operator+(Demo &rhs);
};

Demo::Demo(int val)
{
    cout << "Overloaded Constructor is called\n";
    ptr = new int(val);
}

Demo::Demo(const Demo &rhs)
{
    cout << "Copy Constructor called\n";
    this->ptr = new int;
    *ptr = *(rhs.ptr);
}

Demo::Demo(Demo &&rhs)
{
    cout << "Move Constructor called\n";
    this->ptr = rhs.ptr;
    rhs.ptr = nullptr;
}

Demo &Demo::operator=(const Demo &rhs)
{
    cout << "Copy asssignment operator called\n";
    this->ptr = new int;
    *this->ptr = *rhs.ptr;
    return *this;
}

Demo &Demo::operator=(Demo &&rhs)
{
    cout << "Move asssignment operator called\n";
    this->ptr = nullptr;                /// release the current object's resources
    this->ptr = rhs.ptr;                /// pilfer other's resource
    rhs.ptr = nullptr;                  /// reset other
    return *this;                       /// Return *this
}

Demo Demo::operator+(Demo &rhs)
{
    Demo temp(0);
    *temp.ptr = *this->ptr + *rhs.ptr;
    return temp;
}

int main()
{
    std::vector<Demo> demoVector;
    demoVector.push_back(Demo(55));
   
   
    Demo obj1(44);                  ///Overloaded Constructor will be called
    Demo obj2(56);                  ///Overloaded Constructor will be called
    
    ///@todo check which constructor is called while creating obj3
    Demo obj3(obj1 + obj2);          
    cout << *obj3.ptr << endl;      
   
    obj2 = obj1;                    ///copy assignment operator will be called
    obj2 = obj1 + obj1;             ///move assignment operator will be called

    return 0;
}
