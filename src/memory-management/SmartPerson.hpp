#pragma once

#include "Resource.hpp"
#include <memory>

class SmartPerson
{
  private:
    std::string firstName;
    std::string lastName;
    int arbitraryNumber;
    std::shared_ptr<Resource> pResource;

  public:
    SmartPerson(std::string first, std::string last, int arbitrary);


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
    void addResource();
    std::string getResourceName() const
    {
        pResource ? pResource->getName() : "";
    }
};
