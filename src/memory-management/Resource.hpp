#pragma once
#include <iostream>
#include <string>

class Resource
{
  private:
    std::string m_name;

  public:
    Resource(std::string name);
    ~Resource();
    std::string getName();
};
