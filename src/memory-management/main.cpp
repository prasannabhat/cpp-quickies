#include "Person.hpp"
#include "Resource.hpp"
#include "SmartPerson.hpp"
#include <string>


using std::string;
using std::cout;
using std::endl;

/************************ Resource Related code ***************************************************************/
namespace resource
{
void resourceDeletedTooSoon()
{
    Resource* pResource = new Resource("created with new");
    pResource->getName();
    // some other operations
    int j = 3;
    // deleted too soon
    delete pResource;
    pResource->getName();
}

void duplicateDelete()
{
    Resource* pResource = new Resource("created with new");
    pResource->getName();
    int j = 3;
    pResource = nullptr;
    delete pResource;
    j++;
    delete pResource;
}

void resourcePointerCopy()
{
    Resource* p1 = new Resource("created with new");
    p1->getName();
    // some other operations
    int j = 3;

    // only pointer is copied
    Resource* p2 = p1;
    p2->getName();
    delete p1;
    // access deleted resource
    p2->getName();
}

void setToNullBeforeDelete()
{
    Resource* pResource = new Resource("created with new");
    pResource->getName();
    int j = 3;
    // accessing pResource later will result in more readable error
    // Its safe to delete nullptr, hence multiple delete operations not an issue
    pResource = nullptr;
    delete pResource;
    pResource->getName();
}

void goodCase()
{
    {
        Resource localResource("local");
        localResource.getName();
    }

    Resource* pResource = new Resource("created with new");
    pResource->getName();
    // some other operations
    int j = 3;
    delete pResource;
}
} // namespace resource

/**************************************************************************************************************/

/************************ Person related code *****************************************************************/
namespace person
{
void goodCase()
{
    Person p1("Prasanna", "Bhat", 38);
    p1.addResource();
    p1.setFirstName("Gururaj");
    p1.addResource();
}

void memoryLeak()
{
    Person p1("Prasanna", "Bhat", 38);
    p1.addResourceLeak();
    p1.setFirstName("Gururaj");
    p1.addResourceLeak();
}

void copyObject()
{
    Person p1("Prasanna", "Bhat", 38);
    p1.addResource();
    Person p2 = p1;
    cout << "Name of the copied person : " << p2.getName() << endl;
    int j = 7;
}

void assignObject()
{
    Person p1("Prasanna", "Bhat", 38);
    p1.addResource();
    Person p2("Gururaj", "Bhat", 38);
    p2.addResource();
    p2 = p1;
    cout << "Name of the assigned person : " << p2.getName() << endl;
}
} // namespace person

/**************************************************************************************************************/

/************************ SmartPerson related code ************************************************************/
namespace smartperson
{
void goodCase()
{
    SmartPerson p1("Prasanna", "Bhat", 38);
    p1.addResource();
    string s1 = p1.getResourceName();
    p1.addResource();

    SmartPerson p2 = p1;
    p2.getResourceName();
}
} // namespace smartperson

/**************************************************************************************************************/

/****************** Smart Pointers ****************************************************************************/
namespace smart_pointers
{
void sharedPointers()
{
    std::shared_ptr<Resource> p1;
    p1 = std::make_shared<Resource>(std::string("Resource for ") + "Prasanna");
    p1->getName();
    std::shared_ptr<Resource> p2;
    p2 = p1;
    p2->getName();
}

void uniquePointers()
{
    auto p1 = std::make_unique<Resource>(std::string("Resource for ") + "Prasanna");
    std::cout << "Name before moving " << p1->getName() << endl;
    auto p2 = std::move(p1);
    std::cout << "Name after moving " << p2->getName() << endl;
    // auto p2 = p1.release();
    // p2->getName();
    // delete p2;
}
} // namespace smart_pointers
/**************************************************************************************************************/

int main(int argc, char const* argv[])
{
    // resource::goodCase();
    // resource::resourceDeletedTooSoon();
    // resource::resourcePointerCopy();
    // resource::setToNullBeforeDelete();
    // resource::duplicateDelete();
    // person::goodCase();
    // person::copyObject();
    // person::assignObject();

    // smartperson::goodCase();
    smart_pointers::sharedPointers();
    smart_pointers::uniquePointers();

    return 0;
}
