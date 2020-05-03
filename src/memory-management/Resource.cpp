#include "Resource.hpp"

using std::cout;
using std::endl;

Resource::Resource(std::string name)
    : m_name(name)
{
    cout << "Resource : Constructor : " << m_name << endl;
}

Resource::~Resource()
{
    cout << "Resource : Destructor : " << m_name << endl;
}

std::string Resource::getName()
{
    return m_name;
}
