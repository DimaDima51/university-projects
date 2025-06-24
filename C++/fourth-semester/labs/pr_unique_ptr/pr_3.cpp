#include <iostream>
#include <memory>
using namespace std;

int main()
{
    unique_ptr<int[]> p = make_unique<int[]>(5);
    for(int i = 0; i < 5; i++)
    {
        p[i] = i*2;
        cout << p[i] << endl;
    }
    return 0;
}
