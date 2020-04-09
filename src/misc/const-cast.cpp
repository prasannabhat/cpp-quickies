#include <iostream>

using namespace std;

class DataProvider
{
private:
    struct Data
    {
        int a;
        int b;
    };

    Data data;
public:
    DataProvider(int a, int b)
    {
        data.a = a;
        data.b = b;
    }
    
    ~DataProvider()
    {

    }

    Data getData()
    {
        
        return data;
    }

    Data getData() const
    {
        return data;
    }

    void PrintData()
    {
        cout << "a & b : " << data.a << " " << data.b << endl;
    }
};



int main()
{
    cout << "Hellor world" << endl;

    DataProvider a1(1,2);
    a1.PrintData();
}

