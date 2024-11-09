#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    //声明两个整型变量，用于存储输入的两个整数
    int x,y;
    //请在Begin-End之间添加你的代码，按要求格式输出四则运算式子
    /********** Begin *********/
    cin>>x>>y;
    cout<<setw(5)<<x<<" + "<<left<<setw(5)<<y<<" = "<<right<<setw(10)<<x+y<<endl;
    cout<<setw(5)<<x<<" - "<<left<<setw(5)<<y<<" = "<<right<<setw(10)<<x-y<<endl;
    cout<<setw(5)<<x<<" * "<<left<<setw(5)<<y<<" = "<<right<<setw(10)<<x*y<<endl;
    cout<<setw(5)<<x<<" / "<<left<<setw(5)<<y<<" = "<<right<<setw(10)<<x/y<<endl;
    /********** End **********/
    return 0;
}
