#include <string>
#pragma once


class Person
{
  private:
    std::string firstName;
    std::string lastName;
    int arbitraryNumber;

  public:
    Person(std::string first, std::string last, int arbitrary);
    virtual ~Person();

    virtual std::string getName() const;
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
};
