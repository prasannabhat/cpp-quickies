#pragma once

#include "Person.hpp"

class Tweeter : public Person
{
  private:
    std::string twitterHandle;

  public:
    Tweeter(std::string first, std::string last, int arbitrary, std::string handle);
    ~Tweeter();
    std::string getName() const override;
};