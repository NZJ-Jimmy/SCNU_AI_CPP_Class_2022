// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int n;

    // 请在此添加代码，输入正整数n，如果n是素数则输出“Yes”，否则输出“No”
    /********** Begin *********/
    cin>>n;
    if (n==2) {cout<<"Yes";return 0;}
    for (int i=2;i<=n/2;i++)
        if (n%i==0) {cout<<"No";return 0;}
    cout<<"Yes";
    /********** End **********/

    return 0;
}