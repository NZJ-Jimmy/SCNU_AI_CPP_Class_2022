// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    // y-年，m-月,d-日，n-第几天
    int y, m, d, n;
    // 请在此添加代码，计算并输出指定日期是第几天
    /********** Begin *********/
    cin>>y>>m>>d;
    n=d;
    for(int i=1;i<=m-1;i++)
	switch (i)
    {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            n=n+31;
            break;
        case 2:
            if ( ( (y % 4 == 0) && (y % 100 != 0) ) || (y % 400 == 0)) n=n+29;
            else n=n+28;
            break;
        default:
            n=n+30;
    }
    
    /********** End **********/
    printf("%d-%d-%d是第%d天\n",y,m,d,n);
    return 0;
}