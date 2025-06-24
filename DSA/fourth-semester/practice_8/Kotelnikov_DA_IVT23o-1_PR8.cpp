#include <iostream>
#include <queue>
using namespace std;

// Узел дерева
struct Node {
    int key;        // Ключ узла
    Node* left;     // Указатель на левого потомка
    Node* right;    // Указатель на правого потомка

    Node(int k) : key(k), left(nullptr), right(nullptr) { }
};

// Бинарное дерево поиска
class BST {
private:
    Node* root;  // Корень дерева

    // Рекурсивное удаление всех узлов
    void clear(Node* p) {
        if (p == nullptr) return;
        clear(p->left);
        clear(p->right);
        delete p;
    }

    // Рекурсивная вставка узла
    Node* insertRec(Node* p, int k) {
        if (p == nullptr) {
            // Если дошли до пустого места – создаём новый узел
            return new Node(k);
        }
        if (k < p->key) {
            p->left = insertRec(p->left, k);
        } else if (k > p->key) {
            p->right = insertRec(p->right, k);
        }
        // Если k == p->key, ничего не делаем (ключи в дереве уникальны)
        return p;
    }

    // Рекурсивный поиск узла по ключу
    Node* findRec(Node* p, int k) const {
        if (p == nullptr || p->key == k)
            return p;
        if (k < p->key)
            return findRec(p->left, k);
        else
            return findRec(p->right, k);
    }

    // Находит минимальный узел в дереве p (самый левый)
    Node* findMin(Node* p) const {
        while (p->left != nullptr)
            p = p->left;
        return p;
    }

    // Рекурсивное удаление узла по ключу
    Node* removeRec(Node* p, int k) {
        if (p == nullptr) return nullptr;

        if (k < p->key) {
            // Идём в левое поддерево
            p->left = removeRec(p->left, k);
        } else if (k > p->key) {
            // Идём в правое поддерево
            p->right = removeRec(p->right, k);
        } else {
            // Найден узел для удаления
            if (p->left == nullptr && p->right == nullptr) {
                // Случай 1: лист
                delete p;
                return nullptr;
            } else if (p->left == nullptr) {
                // Случай 2: только правый ребёнок
                Node* tmp = p->right;
                delete p;
                return tmp;
            } else if (p->right == nullptr) {
                // Случай 2: только левый ребёнок
                Node* tmp = p->left;
                delete p;
                return tmp;
            } else {
                // Случай 3: два потомка
                // Находим преемника (минимальный в правом поддереве)
                Node* succ = findMin(p->right);
                p->key = succ->key;
                p->right = removeRec(p->right, succ->key);
            }
        }
        return p;
    }

    // Вывод структуры дерева: для каждого узла печатает ключ и ключи детей
    void printStructureRec(Node* p) const {
        if (p == nullptr) return;
        cout << "Node " << p->key << ": ";
        cout << "L->" << (p->left ? to_string(p->left->key) : "null") << ", ";
        cout << "R->" << (p->right ? to_string(p->right->key) : "null") << '\n';
        printStructureRec(p->left);
        printStructureRec(p->right);
    }

public:
    // Конструктор
    BST() : root(nullptr) {}

    // Деструктор - удаляем все узлы
    ~BST() {
        clear(root);
    }

    // Общая обёртка для insertRec
    void insert(int k) {
        root = insertRec(root, k);
    }

    // Общая обёртка для findRec
    Node* find(int k) const {
        return findRec(root, k);
    }

    // Общая обёртка для removeRec
    void remove(int k) {
        root = removeRec(root, k);
    }

    // Вывести информацию о каждом узле
    void printStructure() const {
        cout << "\nСтруктура дерева:\n";
        printStructureRec(root);
    }
};

int main() {
    BST tree;

    const int size = 11;
    int* initialKeys = new int[size]{50, 25, 75, 12, 37, 43, 30, 33, 87, 93, 97};

    for (int i = 0; i < size; ++i) {
        tree.insert(initialKeys[i]);
    }
    delete[] initialKeys;

    tree.printStructure();

    int keySearch, keyInsert, keyDelete;
    cout << "Введите ключ для поиска: ";
    cin >> keySearch;

    Node* found = tree.find(keySearch);
    if (found) {
        cout << "Найден узел " << found->key << ". ";
        cout << "Левый потомок: " << (found->left ? to_string(found->left->key) : "null") << ", ";
        cout << "Правый потомок: " << (found->right ? to_string(found->right->key) : "null") << "\n";
    } else {
        cout << "Узел с ключом " << keySearch << " не найден в дереве.\n";
    }

    tree.printStructure();

    cout << "Введите ключ для вставки: ";
    cin >> keyInsert;
    tree.insert(keyInsert);
    cout << "Вставлен узел с ключом " << keyInsert << ".\n";

    tree.printStructure();

    cout << "Введите ключ для удаления: ";
    cin >> keyDelete;
    tree.remove(keyDelete);
    cout << "Удалён узел с ключом " << keyDelete << '\n';

    tree.printStructure();

    return 0;
}
