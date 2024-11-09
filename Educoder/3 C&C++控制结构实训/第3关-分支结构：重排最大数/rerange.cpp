// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    // n-输入的数，m-重排后的数
    int n, m;
    // 请在此添加代码，输入一个小于1000的正整数，重排出最大的数存入m中
    /********** Begin *********/
    cin>>n;
    int a1,a2,a3,c;
    a1=n/100;a2=n/10%10;a3=n%10;
    if (a1>a2) {c=a1;a1=a2;a2=c;}
    if (a1>a3) {c=a1;a1=a3;a3=c;}
    if (a2>a3) {c=a2;a2=a3;a3=c;}
    m=a3*100+a2*10+a1;
    
    /********** End **********/
    // 输出重排后的数
    cout << m << endl;
    return 0;
}