#include <iostream>
#include <string>
#include <sstream>

class MyClass {
private:
    static int count;
    std::string name;
    int id;
        
public:
    MyClass(int objId) : id(objId) {
        ++count;
            
        std::stringstream ss;
        ss << "obj" << count;
        name = ss.str();
    }
        
    ~MyClass() {
        --count;
    }
        
    void display() const {
        std::cout << "Имя объекта: " << name << ", Идентификатор: " << id << std::endl;
    }
        
    static int getCount() {
        return count;
    }
};

int MyClass::count = 0;

int main() {
    MyClass obj1(1);
    MyClass obj2(2);
    MyClass obj3(3);
    
    obj1.display();
    obj2.display();
    obj3.display();
    
    std::cout << "Всего создано объектов: " << MyClass::getCount() << '\n';
    
    return 0;
}