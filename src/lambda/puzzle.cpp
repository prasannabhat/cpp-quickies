#include <iostream>
#include <stdio.h>

using namespace std;

int g = 10;
auto kitten = [=]() { return g + 1; };
auto cat = []() { return g + 1; };

int main()
{
    g = 20;
    cout << kitten() << " , " << cat() << endl;
}