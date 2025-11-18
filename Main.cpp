#include "massife.h"
#include <iostream>
using namespace std;

int main() {
    Massife m1, m2;
    
    m1.create_new_massif();
    m2.create_new_massif();
    
    m1.print_massif(1);
    m2.print_massif(2);
    
    m1.check_massif(1);
    m2.check_massif(2);
    
    Massife m3 = m1.conjunction_massif(m2);
    m3.print_massif(3);

    Massife m4 = m1;
    m4.print_massif(4);
    
    return 0;
}