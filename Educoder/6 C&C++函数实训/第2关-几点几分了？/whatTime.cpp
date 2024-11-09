#include <iostream>
using namespace std;

void whatTime(int secs, int &h, int &m, int &s)
{
    // 请在这里补充代码，设计并实现函数whatTime,使main函数中的函数调用正确
    /********** Begin *********/
    h = secs / 3600;
    m = (secs - h * 3600) / 60;
    s = (secs - h * 3600 - m * 60);
    /********** End **********/
}

int main()
{
    int secs;     // secs秒表上的秒数   
    int h, m, s;     // 当前时间:h-小时，m-分，s-秒
    cin >> secs;     // 输入秒表上的秒数
    whatTime(secs,h,m,s);     // 计算当前时间
    cout << h << ":" << m << ":" << s << endl;     // 输出当前时间
    return 0;
}