#include <iostream>
using namespace std;

class MyClass 
{
    public:
    int value;
    int data;

    void setValue(int value ,int data ) 
    {
        this->value = value;
        this->data = data;
    }
    
    void display() 
    {
        cout << "Value: " << this->value <<endl<<" Data: " << this->data << endl;
    }

};

int main() 
{
    MyClass obj;
    MyClass *ptr = &obj;

    ptr->setValue(10, 20);
    ptr->display();

    return 0;
}