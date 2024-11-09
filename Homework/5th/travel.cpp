#include "travel.h"
#include <iostream>
using namespace std;
int main()
{
    travel travel1(3100, "Mung Dak", "Lei Yut", 500000), travel2, travel3;
    cin >> travel2;
    travel3 = travel2;
    cout << travel1;
    cout << travel3;
    return 0;
}
