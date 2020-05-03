#include "Resource.hpp"

using std::cout;
using std::endl;

Resource::Resource(std::string name)
    : m_name(name)
{
    cout << "constructing : " << m_name << endl;
}

Resource::~Resource()
{
    cout << "destructing : " << m_name << endl;
}

std::string Resource::getName()
{
    return m_name;
}
