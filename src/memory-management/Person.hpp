#pragma once

#include "Resource.hpp"

class Person
{
  private:
    std::string firstName;
    std::string lastName;
    int arbitraryNumber;
    Resource* pResource;

  public:
    Person(std::string first, std::string last, int arbitrary);
    Person(Person const& p);
    Person& operator=(const Person& p);
    ~Person();

    std::string getName() const;
    int getNumber() const
    {
        return arbitraryNumber;
    }
    void setNumber(int arbitrary)
    {
        arbitraryNumber = arbitrary;
    }
    void setFirstName(std::string first)
    {
        firstName = first;
    }
    void addResourceLeak();
    void addResource();
};
