#include <iostream>
#include <exception>
using namespace std;

void MyTerminate() {
    cout << "MyTerminate error" << '\n';
    abort();
}

int main() {
    set_terminate(MyTerminate);
    throw 1;
  
    return 0;
}