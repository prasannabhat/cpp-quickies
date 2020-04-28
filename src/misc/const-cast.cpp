#include <iostream>

using namespace std;

    struct Data
    {
        int a;
        int b;
    };

class DataProvider
{
private:
    Data data;

public:
    DataProvider(int a=1, int b=1)
    {
        data.a = a;
        data.b = b;
    }
    
    ~DataProvider()
    {

    }

    Data getData()
    {
        cout << "In Data getData() " << endl;
        data.a++;
        return data;
    }

    Data getData() const
    {
        cout << "In Data getData() const " << endl;
        return data;
    }

    Data& getDataRef() &
    {
        cout << "In Data& getData() " << endl;
        // return this->getDataRef();
        // return ((const DataProvider*) (this))->getDataRef();
        return data;
    }

    const Data& getDataRef() const&
    {
        cout << "const Data& getDataRef() const " << endl;
        // return const_cast<DataProvider*>(this)->getDataRef();
        // return getDataRef();
        return data;
    }

    Data&& getDataRef() &&
    {
        cout << "In Data&& getDataRef() && " << endl;
        return std::move(data);
    }

    const Data&& getDataRef() const&&
    {
        cout << "const Data&& getDataRef() const&& " << endl;
        return std::move(data);
    }


    void PrintData() const
    {
        cout << "a & b : " << data.a << " " << data.b << endl;
    }
};


void testgGetData()
{
    DataProvider a1;
    const DataProvider a2;
    a1.getData();
    a2.getData();

}

void testGetDataRef()
{
    DataProvider a1;
    const DataProvider a2;

    auto data1 = a1.getDataRef();
    data1.a++;
    auto data2 = a2.getDataRef();
    data2.a++;

    a1.PrintData();
    a2.PrintData();
}

void testGetDataRefRef()
{
    DataProvider a1;
    const DataProvider a2;

}

int main()
{
    testgGetData();
    testGetDataRef();
    testGetDataRefRef();

    return 1;
}

