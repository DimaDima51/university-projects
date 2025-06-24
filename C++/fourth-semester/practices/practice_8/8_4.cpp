#include <iostream>
#include "typeinfo"

using namespace std;
class Base
{
    public:
        virtual ~Base()=0;
    virtual bool Operator (Base &R)=0; // Чисто виртуальный метод
};

Base:: ~Base(){} // Виртуальный деструктор

class Derived_a: public Base
{
    public:
        virtual bool Operator (Base &R);
};

class Derived_b: public Base
{
     public:
virtual bool Operator (Base &R);
};

bool Derived_a::Operator (Base &R)
{
    // Пытаемся привести к Derived_a
    if (Derived_a *pa =dynamic_cast<Derived_a *>(&R))
    {
        cout<<"A_A"<<'\n';
        
    }
    // Иначе пытаемся привести к типу Derived_b
    else if (Derived_b *pb =dynamic_cast<Derived_b *>(&R))
    {
        cout<<"A_B"<<'\n';
    }
     return true;
}

bool Derived_b::Operator (Base &R)
{
      if (Derived_a *pa = dynamic_cast<Derived_a *>(&R))
      {
          cout<<"B_A"<<'\n';
      }
      else if (Derived_b *pb =dynamic_cast<Derived_b *>(&R))
      {
          cout<<"B_B"<<'\n';
      }
      return true;

}

class Derived_c : public Base {
    public:
        virtual bool Operator(Base &R) {
            // Сравнение типов
            if (typeid(R) == typeid(Derived_a)) {
                cout << "C_A" << '\n';
            } else if (typeid(R) == typeid(Derived_b)) {
                cout << "C_B" << '\n';
            } else if (typeid(R) == typeid(Derived_c)) {
            // Проверка на самого себя
                cout << "C_C" << '\n';
            }

            // Если ничего не подошло, возвращается true
            return true;
        }
};


int main(int argc, char *argv[])
{
    Derived_a A;
    Derived_b B;
    Derived_c C;

    cout << A.Operator(A) << '\n';
    cout << A.Operator(B) << '\n';
    cout << B.Operator(A) << '\n';
    cout << B.Operator(B) << '\n';

    cout << C.Operator(A) << '\n';
    cout << C.Operator(B) << '\n';
    cout << C.Operator(C) << '\n';

    cout << A.Operator(C) << '\n'; // true

}