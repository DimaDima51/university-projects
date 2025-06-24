#include <iostream>
using namespace std;

class Derived_a;
class Derived_b;
class Derived_c;

// Базовый абстрактный класс
class Base {
public:
    virtual ~Base() = 0;
    
    virtual bool Operator(Base& R) = 0;
    virtual bool Operator(Derived_a& R) = 0;
    virtual bool Operator(Derived_b& R) = 0;
    virtual bool Operator(Derived_c& R) = 0;
};

Base::~Base() {} 

// Класс Derived_a
class Derived_a : public Base {
public:
    virtual bool Operator(Base& R) { 
        return R.Operator(*this); 
    }
    
    // когда аргумент - Derived_a
    virtual bool Operator(Derived_a& R) {
        cout << "A_A" << endl; 
        return true;
    }
    
    // аргумент - Derived_b
    virtual bool Operator(Derived_b& R) {
        cout << "A_B" << endl;
        return true;
    }
    
    // аргумент - Derived_c
    virtual bool Operator(Derived_c& R) {
        cout << "A_C" << endl;
        return true;
    }
};

// Класс Derived_b
class Derived_b : public Base {
public:
    // перенаправление вызова
    virtual bool Operator(Base& R) { 
        return R.Operator(*this); 
    }
    
    virtual bool Operator(Derived_a& R) {
        cout << "B_A" << endl;
        return true;
    }
    
    virtual bool Operator(Derived_b& R) {
        cout << "B_B" << endl;
        return true;
    }
    
    virtual bool Operator(Derived_c& R) {
        cout << "B_C" << endl;
        return true;
    }
};

// Новый класс Derived_c
class Derived_c : public Base {
public:
    virtual bool Operator(Base& R) { 
        return R.Operator(*this); 
    }
    
        virtual bool Operator(Derived_a& R) {
        cout << "C_A" << endl;
        return true;
    }
    
    virtual bool Operator(Derived_b& R) {
        cout << "C_B" << endl;
        return true;
    }
    
    virtual bool Operator(Derived_c& R) {
        cout << "C_C" << endl;
        return true;
    }
};

int main() {
    Derived_a A;
    Derived_b B;
    Derived_c C;
    Base &tempA = A;
    Base &tempB = B;
    Base &tempC = C;
    cout<<A.Operator(C)<<endl;
    cout<<B.Operator(C)<<endl;
    cout<<tempA.Operator(tempC)<<endl;
    cout<<tempB.Operator(tempC)<<endl;
    Base *pa = new Derived_a();
    Base *pb = new Derived_b();
    Base *pc = new Derived_c();
    cout<<pa->Operator(*pa)<<endl;
    cout<<pa->Operator(*pb)<<endl;
    cout<<pa->Operator(*pc)<<endl;
    cout<<pb->Operator(*pb)<<endl;
    cout<<pb->Operator(*pa)<<endl;
    cout<<pb->Operator(*pc)<<endl;
    cout<<pc->Operator(*pc)<<endl;
    cout<<pc->Operator(*pa)<<endl;
    cout<<pc->Operator(*pb)<<endl;


    return 0;
}