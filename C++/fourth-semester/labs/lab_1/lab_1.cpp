#include "mygauss.h"

int main() {
    MyGauss gauss;
    MyGauss gauss1 = gauss;
    
    std::cout << gauss;
    
    gauss1.SolveSystem();
    gauss1.print_result();
    
    return 0;
}
