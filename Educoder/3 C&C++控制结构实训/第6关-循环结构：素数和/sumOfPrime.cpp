// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    bool a;
    // 请在此添加代码，输入n和k，并输出n以内k个素数以及它们的和
    /********** Begin *********/
    cin >> n >> k;
    int s = 0, t;
    for (int i = n, t = 1; (t <= k) && (i > 1); i--)
    {
        a = false;
        if ((i == 1) || (i == 2))
        {
            t++;
            cout << i << ' ';
            s = s + i;
            continue;
        }
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                a = true;
                break;
            }
        }
        if (a == false)
        {
            cout << i << ' ';
            s = s + i;
            t++;
        };
    }
    cout << s;
    /********** End **********/

    return 0;
}