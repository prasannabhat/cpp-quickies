#include <iostream>
#include <vector>

template <class T>
class Vector
{
    public:
    Vector(){}

    protected:
    std::vector<T> vec;
};

template <class T>
class ChildVector : public Vector<T>
{
public:
    ChildVector() : Vector<T>() {
        // std::cout << "Hi";
    }

    ChildVector(std::initializer_list<T> l) {
        Vector<T>::vec.reserve(l.size());
        for (auto& i : l) {
            Vector<T>::vec.emplace_back(i); // may be move here
        }
    }


};

int main()
{
    Vector<int> a;
    ChildVector<int> test{0,1,2};
}





