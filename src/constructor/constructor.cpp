#include "construction-order.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Box
{
  public:
    Box()
    {
        std::cout << "default" << std::endl;
    }


    explicit Box(int size)
        : Box(size, size, size)
    {
        std::cout << "explcit constructor" << std::endl;
    }

    Box(int width, int height, int length)
        : m_width(width)
        , m_height(height)
        , m_length(length)

    {
        std::cout << "user defined" << std::endl;
        this->printVolume();
    }
    Box(Box& other)
        : m_width(other.m_width)
        , m_height(other.m_height)
        , m_length(other.m_length)
    {
        std::cout << "copy" << std::endl;
    }
    Box(Box&& other)
        : m_width(other.m_width)
        , m_height(other.m_height)
        , m_length(other.m_length)
    {
        m_contents = std::move(other.m_contents);
        std::cout << "move" << std::endl;
    }
    int Volume()
    {
        return m_width * m_height * m_length;
    }

    void printVolume()
    {
        cout << "Box volume is " << Volume() << endl;
    }
    void Add_Item(string item)
    {
        m_contents.push_back(item);
    }
    void Get_Contents()
    {
        for (const auto& item : m_contents)
        {
            cout << item << " ";
        }
        cout << endl;
    }

  private:
    int m_width{0};
    int m_height{0};
    int m_length{0};
    vector<string> m_contents;
};

Box get_Box()
{
    Box b(5, 10, 18); // "int,int,int"
    b.Add_Item("Toupee");
    b.Add_Item("Megaphone");
    b.Add_Item("Suit");

    return b;
}

static Box originalBox; // "default"

int main()
{
    Box b1{originalBox}; // "copy"
    Box b2{get_Box()};   // "move"
    cout << "b2 contents: ";
    b2.Get_Contents(); // Prove that we have all the values

    // Implicit conversion to Box. Marking the constructor as explicit results in compilation error
    // Box b = 10;
    // Uses Delegating constructor
    Box b3{10};

    // DerivedContainer d;

    return 0;
}