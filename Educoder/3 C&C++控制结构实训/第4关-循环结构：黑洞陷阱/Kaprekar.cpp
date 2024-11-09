// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    // 请在此添加代码，输出整数进入黑洞过程
    /********** Begin *********/
    cin>>n;
    int i=0;
    while (n!=495)
    {
        i++;
        int a1,a2,a3,c,max,min;
        a1=n/100;a2=n/10%10;a3=n%10;
        if (a1>a2) {c=a1;a1=a2;a2=c;}
        if (a1>a3) {c=a1;a1=a3;a3=c;}
        if (a2>a3) {c=a2;a2=a3;a3=c;}
        max=a3*100+a2*10+a1;
        min=a1*100+a2*10+a3;
        n=max-min;
        cout<<i<<':'<<max<<'-'<<min<<'='<<n<<endl;
    }
    /********** End **********/
    return 0;
}