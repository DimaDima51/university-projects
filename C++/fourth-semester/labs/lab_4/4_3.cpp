#include <iostream>
#include <string>

class MyStack {
private:
    struct Element {
        void* item;
        Element* next;
        Element(void* p_item, Element* p_next) : item(p_item), next(p_next) {}
    };

    Element* top;

public:
    MyStack() : top(nullptr) { }

    // Конструктор копирования
    MyStack(const MyStack& other) : top(nullptr) {
        if (!other.Empty()) {
            MyStack temp;
            Element* current = other.top;
            while (current != nullptr) {
                temp.push(current->item);
                current = current->next;
            }
            while (!temp.Empty()) {
                push(temp.getTop());
                temp.pop();
            }
        }
    }

    // Оператор присваивания
    MyStack& operator=(const MyStack& other) {
        if (this != &other) {
            while (!Empty()) {
                pop();
            }
            if (!other.Empty()) {
                MyStack temp;
                Element* current = other.top;
                while (current != nullptr) {
                    temp.push(current->item);
                    current = current->next;
                }
                while (!temp.Empty()) {
                    push(temp.getTop());
                    temp.pop();
                }
            }
        }
        return *this;
    }

    // Деструктор
    ~MyStack() {
        while (!Empty())
            pop();
    }

    // Проверка на пустоту
    bool Empty() const {
        return (top == nullptr);
    }

    // Добавить элемент в стек
    void push(void* value) {
        if (value == nullptr) {
            std::cout << "Пустой указатель" << '\n';
            return;
        }
        top = new Element(value, top);
    }

    // Прочитать вершину (не удаляя)
    void* getTop() const {
        if (Empty()) {
            std::cout << "Стек пустой!!!" << '\n';
            return nullptr;
        }
        return top->item;
    }

    // Удалить вершину
    void pop() {
        if (!Empty()) {
            Element *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    // Пример с int
    MyStack stInt;
    stInt.push(new int(7));
    stInt.push(new int(8));
    stInt.push(new int(70));

    stInt.pop(); // Удалится 70

    // Вывод оставшихся
    while (!stInt.Empty()) {
        int* val = static_cast<int*>(stInt.getTop());
        std::cout << *val << '\n';
        stInt.pop();
        delete val;
    }

    // Пример с string
    MyStack stStr;
    stStr.push(new std::string("Hello"));
    stStr.push(new std::string("World"));
    stStr.push(new std::string("!"));

    stStr.pop(); // Удалится "!"

    while (!stStr.Empty()) {
        std::string* str = static_cast<std::string*>(stStr.getTop());
        std::cout << *str << '\n';
        stStr.pop();
        delete str;
    }

    return 0;
}