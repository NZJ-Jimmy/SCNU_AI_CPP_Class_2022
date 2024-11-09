#include <iostream>
using namespace std;

struct rationalNumber{
    int fenzi; // 分子
    int fenmu; // 分母
};

// 函数reduction：有理数化简，对传入的有理数n进行化简
// 参数：n-有理数
// 返回值：无化简后的有理数
rationalNumber reduction(rationalNumber n);

int main()
{
    char c;
    rationalNumber x, y;
    cin >> x.fenzi >> c >> x.fenmu;   // 输入有理数，首先读入分子，然后是/，最后是分母
    y = reduction(x);   // 有理数化简
    // 输出化简的结果
    if(y.fenmu == 1)
        cout << y.fenzi << endl;
    else
        cout << y.fenzi << "/" << y.fenmu << endl;
    return 0;
}

rationalNumber reduction(rationalNumber n)
{
    // 请在这里补充代码，实现函数reduction
    /********** Begin *********/
    int a = abs(n.fenzi), b = abs(n.fenmu); //ensure a>=0 and b>0
    if (a > 1)
        while (a != b) // to get the max factor, 辗转相减法
        {
            if (a > b)
                a = a - b;
            else
                b = b - a;
        } //the max factor = a = b
    return {n.fenzi / b, n.fenmu / b};// div the max factor.
    // if n=0, a=0, so fenzi shouldn't div 0 a, and fenmu div b = 1, so return 0/1, successfully solve n=0
    /********** End **********/
}
