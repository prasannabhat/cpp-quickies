#include <iostream>

using namespace std;

class PrintedDocument
{
  public:
    void sayHello()
    {
        cout << "Hello from PrintedDocument" << endl;
    }
};

// Book is derived from PrintedDocument.
class Book : public PrintedDocument
{
  public:
    void sayHello()
    {
        PrintedDocument::sayHello();
        cout << "Hello from Book" << endl;
    }
};

// PaperbackBook is derived from Book.
class PaperbackBook : public Book
{
};

int main(int argc, char const* argv[])
{
    PrintedDocument p;
    p.sayHello();

    Book b;
    b.sayHello();
    /* code */
    return 0;
}
