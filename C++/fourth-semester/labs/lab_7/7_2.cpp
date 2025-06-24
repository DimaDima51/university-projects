#include <iostream>
using namespace std;

class A {
    public:
        virtual void what() const {
            cout << "A" << endl;
        }
};

class B : public A {
    public:
        void what() const override {
            cout << "B" << endl;
        }
};

int main()
{
    try {
        try {
                throw B();
            }
            catch(A& obja)
            {
                obja.what();
                throw obja; // B A
                //throw; // B B
            }
    }
    catch(A& obja)
    {
        obja.what();
    }
    
    return 0;
}