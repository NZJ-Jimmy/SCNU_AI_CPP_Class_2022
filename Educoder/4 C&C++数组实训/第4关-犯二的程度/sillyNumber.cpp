#include <iostream>
using namespace std;

// 函数silly：计算数值有多二
// 参数：a-存储数值的字符数组，以'\0'结束，所以不需要另一个参数告诉函数数组有多长
// 返回值：数值犯二的程度
double silly(char a[]);

int main()
{
    char s[102];     // 定义存储数值的数组
    cin >> s;     // 输入不超过位的整数
    double sy = silly(s);     // 计算犯二的程度
    cout << sy << endl;     // 输出犯二的程度
    return 0;
}

double silly(char a[])
{
    // 请在此添加代码，实现函数silly
    /********** Begin *********/
    int i=0,s=0;
    double dy;
    while (a[i]!='\0')
    {
        if (a[i]=='2') s++;
        i++;
    }
    if (a[0]=='-') dy=s*1.0/(i-1);// if it's a minus number, the number of bits = length-1
    else dy=s*1.0/i;
    if (a[0]=='-') dy*=1.5;
    if ((a[i-1]-'0')%2==0) dy*=2.0;// i-1 is the last number.
    return dy;
    /********** End **********/
}