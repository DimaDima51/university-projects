#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Структура для хранения записи накладной
struct Record {
    int invoice;     // номер накладной (ключ)
    string product;  // наименование товара
    int quantity;    // количество единиц товара
};

// Узел двоичного дерева поиска
struct BSTNode {
    Record data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(const Record& rec) : data(rec), left(nullptr), right(nullptr) {}
};

// Класс для работы с BST: вставка, поиск, удаление, вывод
class BST {
   private:
    BSTNode* root;

    // Рекурсивная очистка памяти дерева
    void clear(BSTNode* p) {
        if (!p) return;
        clear(p->left);
        clear(p->right);
        delete p;
    }

    // Рекурсивная вставка, duplicate=true, если ключ уже есть
    BSTNode* insertRec(BSTNode* p, const Record& rec, bool& duplicate) {
        if (!p) {
            duplicate = false;
            return new BSTNode(rec);
        }
        if (rec.invoice < p->data.invoice)
            p->left = insertRec(p->left, rec, duplicate);
        else if (rec.invoice > p->data.invoice)
            p->right = insertRec(p->right, rec, duplicate);
        else
            duplicate = true;  // уже есть
        return p;
    }

    // Рекурсивный поиск по ключу
    BSTNode* findRec(BSTNode* p, int key) const {
        if (!p || p->data.invoice == key) return p;
        return key < p->data.invoice ? findRec(p->left, key) : findRec(p->right, key);
    }

    // Поиск минимума в поддереве
    BSTNode* findMin(BSTNode* p) const {
        while (p && p->left) p = p->left;
        return p;
    }

    // Рекурсивное удаление узла по ключу
    BSTNode* removeRec(BSTNode* p, int key) {
        if (!p) return nullptr;
        if (key < p->data.invoice) {
            p->left = removeRec(p->left, key);
        } else if (key > p->data.invoice) {
            p->right = removeRec(p->right, key);
        } else {
            if (!p->left && !p->right) {
                delete p;
                return nullptr;
            } else if (!p->left) {
                BSTNode* tmp = p->right;
                delete p;
                return tmp;
            } else if (!p->right) {
                BSTNode* tmp = p->left;
                delete p;
                return tmp;
            } else {
                BSTNode* succ = findMin(p->right);
                p->data = succ->data;
                p->right = removeRec(p->right, succ->data.invoice);
            }
        }
        return p;
    }

    // Рекурсивный вывод содержимого
    void printRec(BSTNode* p) const {
        if (!p) return;
        cout << p->data.invoice << ", " << p->data.product << ", " << p->data.quantity << "\n";
        printRec(p->left);
        printRec(p->right);
    }

   public:
    BST() : root(nullptr) {}
    ~BST() { clear(root); }

    // Вставка: возвращает true, если элемент добавлен, false при дубликате
    bool insert(const Record& rec) {
        bool duplicate = false;
        root = insertRec(root, rec, duplicate);
        return !duplicate;
    }

    // Поиск узла по ключу
    BSTNode* find(int key) const { return findRec(root, key); }

    // Удаление по ключу
    bool remove(int key) {
        if (!find(key)) return false;
        root = removeRec(root, key);
        return true;
    }

    // Вывести всё дерево
    void printStructure() const {
        cout << "Содержимое BST:\n";
        printRec(root);
        cout << "\n";
    }
};

// Константы состояния ячейки хеш-таблицы
static const int EMPTY = -1;

// Класс хеш-таблицы с линейным пробированием без статуса DELETED
class HashTable {
private:
    vector<Record> table;
    vector<int> status;
    int m;

    // Простая хеш-функция
    int hash(int key) const { return key % m; }

public:
    HashTable(int size) : table(size), status(size, EMPTY), m(size) {}

    // Вставка: 1 - успешно, 0 - дубликат, -1 - полный
    int insert(const Record& rec) {
        int key = rec.invoice;
        int idx = hash(key);
        for (int i = 0; i < m; ++i) {
            int j = (idx + i) % m;
            if (status[j] == 1) {
                if (table[j].invoice == key) {
                    return 0;  // дубликат
                }
            } else {
                // пустая ячейка — вставляем
                table[j] = rec;
                status[j] = 1;
                return 1;
            }
        }
        return -1;  // таблица полна
    }

    // Удаление по ключу — просто отмечаем ячейку пустой
    bool remove(int key) {
        int idx = hash(key);
        for (int i = 0; i < m; ++i) {
            int j = (idx + i) % m;
            if (status[j] == EMPTY) {
                return false;  // не найдена
            }
            if (status[j] == 1 && table[j].invoice == key) {
                status[j] = EMPTY;
                return true;
            }
        }
        return false;
    }

    // Поиск записи, возвращает указатель и индекс в outIndex
    Record* search(int key, int& outIndex) {
        int idx = hash(key);
        for (int i = 0; i < m; ++i) {
            int j = (idx + i) % m;
            if (status[j] == EMPTY) break;
            if (status[j] == 1 && table[j].invoice == key) {
                outIndex = j;
                return &table[j];
            }
        }
        return nullptr;
    }

    // Вывод состояния таблицы без отметки DELETED
    void display() const {
        cout << "Содержимое хеш-таблицы:\n";
        for (int i = 0; i < m; ++i) {
            cout << setw(3) << i << ": ";
            if (status[i] == 1) {
                cout << table[i].invoice << ", " << table[i].product << ", " << table[i].quantity;
            } else {
                cout << "<пусто>";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

// Чтение записей из файла формата invoice;product;quantity
vector<Record> readRecords(const string& filename) {
    vector<Record> recs;
    ifstream in(filename);
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        Record r;
        stringstream ss(line);
        string tmp;
        getline(ss, tmp, ';');
        r.invoice = stoi(tmp);
        getline(ss, r.product, ';');
        getline(ss, tmp, ';');
        r.quantity = stoi(tmp);
        recs.push_back(r);
    }
    return recs;
}

// Поиск простого простого числа >= n
int nextPrime(int n) {
    auto isPrime = [](int x) {
        if (x < 2) return false;
        if (x % 2 == 0) return x == 2;
        for (int i = 3; i * i <= x; i += 2)
            if (x % i == 0) return false;
        return true;
    };
    while (!isPrime(n)) ++n;
    return n;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    auto recs = readRecords("text.txt");  // читаем исходные данные
    BST bst;
    for (auto& r : recs) bst.insert(r);  // заполняем дерево

    int size = nextPrime(static_cast<int>(recs.size()) * 2);
    HashTable ht(size);
    for (auto& r : recs) ht.insert(r);  // заполняем хеш-таблицу

    bool running = true;  // флаг для управления главным циклом
    while (running) {
        cout << "Выберите структуру (1=Дерево, 2=Хеш-таблица, 0=Выход): ";
        int mode;
        cin >> mode;
        switch (mode) {
            case 0:
                running = false;  // выходим из программы
                break;

            case 1: {  // операции над BST
                cout << "Операции\n"
                        "1) Поиск\n"
                        "2) Добавить\n"
                        "3) Удалить\n"
                        "4) Показать\n"
                        "Выберите операцию: ";
                int op;
                cin >> op;
                switch (op) {
                    case 1: {
                        int key;
                        cout << "Ключ: ";
                        cin >> key;
                        auto n = bst.find(key);
                        if (n)
                            cout << "Найдено: " << n->data.invoice << ", " << n->data.product << ", " << n->data.quantity << "\n";
                        else
                            cout << "Запись не найдена\n";
                        break;
                    }
                    case 2: {
                        Record r;
                        cout << "Номер: ";
                        cin >> r.invoice;
                        cin.ignore(1000, '\n');
                        cout << "Товар: ";
                        getline(cin, r.product);
                        cout << "Кол-во: ";
                        cin >> r.quantity;
                        bool addedBST = bst.insert(r);
                        int resHT = ht.insert(r);
                        if (addedBST && resHT == 1)
                            cout << "Запись добавлена\n";
                        else if (!addedBST || resHT == 0)
                            cout << "Запись существует\n";
                        else
                            cout << "Хеш-таблица заполнена\n";
                        break;
                    }
                    case 3: {
                        int key;
                        cout << "Ключ: ";
                        cin >> key;
                        bool delBST = bst.remove(key);
                        bool delHT = ht.remove(key);
                        cout << (delBST || delHT ? "Запись удалена\n" : "Запись не найдена\n");
                        break;
                    }
                    case 4:
                        bst.printStructure();
                        break;
                    default:
                        cout << "Неверный код операции\n";
                }
                break;
            }

            case 2: {  // операции над хеш-таблицей
                cout << "Операции\n"
                        "1) Поиск\n"
                        "2) Добавить\n"
                        "3) Удалить\n"
                        "4) Показать\n"
                        "Выберите операцию: ";
                int op;
                cin >> op;
                switch (op) {
                    case 1: {
                        int key, idx;
                        cout << "Ключ: ";
                        cin >> key;
                        auto r = ht.search(key, idx);
                        if (r)
                            cout << "Ячейка " << idx << ": " << r->invoice << ", " << r->product << ", " << r->quantity << "\n";
                        else
                            cout << "Запись не найдена\n";
                        break;
                    }
                    case 2: {
                        Record r;
                        cout << "Номер: ";
                        cin >> r.invoice;
                        cin.ignore(1000, '\n');
                        cout << "Товар: ";
                        getline(cin, r.product);
                        cout << "Кол-во: ";
                        cin >> r.quantity;
                        int resHT = ht.insert(r);
                        bool addedBST = bst.insert(r);
                        if (addedBST && resHT == 1)
                            cout << "Запись добавлена\n";
                        else if (!addedBST || resHT == 0)
                            cout << "Запись существует\n";
                        else
                            cout << "Хеш-таблица заполнена\n";
                        break;
                    }
                    case 3: {
                        int key;
                        cout << "Ключ: ";
                        cin >> key;
                        bool delBST = bst.remove(key);
                        bool delHT = ht.remove(key);
                        cout << (delBST || delHT ? "Запись удалена\n" : "Запись не найдена\n");
                        break;
                    }
                    case 4:
                        ht.display();
                        break;
                    default:
                        cout << "Неверный код операции\n";
                }
                break;
            }

            default:
                cout << "Неверный режим работы\n";
        }
        cout << "\n";
    }

    return 0;
}
