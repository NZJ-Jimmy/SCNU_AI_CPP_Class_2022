#include <iostream>
using namespace std;

// 函数king：猴子选大王
// 参数：a-猴子数组n-1个猴子分别占据下标为~n-1的位置，n-数组长度
// 返回值：新猴王的下标序号
int king(int a[], int n);

int main()
{
    int n, a[1000], i;     // 定义变量及数组，n-猴子数量，a-猴子数组
    cin >> n;     // 输入猴子数量，n>0

    // 初始化猴子数组,n 个猴子分别占据 n 个位置
    a[0] = 0; // 0号位置没有猴子
    for(i = 1;i <= n; i++)
        a[i] = i;

    // 选大王啦
    i = king(a, n );
    cout << i << "号猴子是大王。" << endl;
    return 0;
}

int king(int a[], int n)
{
    // 请在此添加代码，实现函数king
    /********** Begin *********/
    int r=n,i=0,j=0; //r - rest monkeys; i - circle123; j - exact num
    while (r>1)
    {
        do
            j++;
        while (a[(j-1)%n+1/*to ensure the num in n circle*/] == 0);//find the next monkey
        i++;
        if (i % 3 == 0)
        {
            a[(j-1)%n+1] = 0;
            r--;
        }
        // if (j == n)
        //     j = 0;
        // for (int k=1;k<=n;k++) cout<<a[k]; // for testing
        // cout<<endl;
    }
    do
        j++;
    while (a[(j - 1) % n + 1] == 0);
    return (j-1)%n+1;    
    
    
    /********** End **********/
}