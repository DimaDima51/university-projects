#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout<<"Base-Constr";
    }
    virtual void print()
    {
        cout<<"Print!!!";
    }
};
class D1: public Base
{
public:
    D1()
    {
        cout<<"D1-Constr";
    }
    virtual void print()
    {
        cout<<"PrintD1!!!";
    }
    virtual void func()
    {
       cout<<"func-D1!!!";
    }
};
class D2: public D1
{
public:
    int b;
    D2()
    {
        cout<<"D2-Constr";
        b = 5;
    }
    virtual void print()
    {
        cout<<"PrintD2!!!";
    }
    virtual void func()
    {
       cout<<"func-D2!!!";
    }
};
Base * GetPObj()
{
    Base *p;
    int temp = rand()%3;
    switch (temp)
    {
    case 0: p = new Base();
                break;
    case 1: p = new D1();
            break;
    case 2: p = new D2();
            break;
    }
    return p;
}
int main()
{
    Base *pB;
    D1 *pd1;
    for (int i = 0; i<10; i++)
    {
        pB = GetPObj();
        pB->print();
        if (pd1 = dynamic_cast<D1*>(pB)) // Безопасное приведение типа указателя базового класса к указателю на производный класс
            pd1->func();
    }
}
