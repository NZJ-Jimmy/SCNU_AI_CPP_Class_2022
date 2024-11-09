#include <iostream>
#include "Person.h"
using namespace std;
int main()
{
    Person a("0001","Ho Lay", "Female", "2018/7/22", "Mung Dat");
    Person b = a;
    Person c;
    cin >> c;
    cout << a << b << c;
    return 0;
}