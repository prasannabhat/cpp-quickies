//
// Created by apoorva on 22/12/19.
//
#pragma once

#include <iostream>

using namespace std;

class Contained1
{
  public:
    Contained1()
    {
        cout << "Contained1 ctor\n";
    }

    ~Contained1()
    {
        cout << "Contained1 dtor\n";
    }
};

class Contained2
{
  public:
    Contained2()
    {
        cout << "Contained2 ctor\n";
    }

    ~Contained2()
    {
        cout << "Contained2 dtor\n";
    }
};

class Contained3
{
  public:
    Contained3()
    {
        cout << "Contained3 ctor\n";
    }

    ~Contained3()
    {
        cout << "Contained3 dtor\n";
    }
};

class BaseContainer
{
  public:
    BaseContainer()
    {
        cout << "BaseContainer ctor\n";
    }

    ~BaseContainer()
    {
        cout << "BaseContainer dtor\n";
    }

  private:
    Contained1 c1;
    Contained2 c2;
};

class DerivedContainer : public BaseContainer
{
  public:
    DerivedContainer()
        : BaseContainer()
    {
        cout << "DerivedContainer ctor\n";
    }

    ~DerivedContainer()
    {
        cout << "DerivedContainer dtor\n";
    }

  private:
    Contained3 c3;
};
