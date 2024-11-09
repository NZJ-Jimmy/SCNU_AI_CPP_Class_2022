#include <iostream>
using namespace std;

struct rationalNumber{
    int fenzi; // 分子
    int fenmu; // 分母
};

// 函数rnMean：计算n个有理数的平均数
// 参数：a-存放有理数的数组,n-有理数的个数
// 返回值：n个有理数的平均数
rationalNumber rnMean(rationalNumber a[], int n);

int main()
{
    char c;
    rationalNumber a[100],z;
    int n, i;
    cin >> n;     // 输入有理数个数
    // 输入n个有理数
    for(i = 0; i < n; i++)
        cin >> a[i].fenzi >> c >> a[i].fenmu;
    z = rnMean(a,n);     // 计算有理数平均数
    // 输出平均数
    if(z.fenmu == 1)
        cout << z.fenzi << endl;
    else
        cout << z.fenzi << "/" << z.fenmu << endl;
    return 0;
}

// 请在此添加代码，实现函数rnMean
/********** Begin *********/
rationalNumber reduction(rationalNumber n)
{
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
}
rationalNumber rnAdd(rationalNumber x, rationalNumber y)
{
	int fenmu = x.fenmu * y.fenmu; //通分
    int fenzi = x.fenzi * y.fenmu + y.fenzi * x.fenmu; //相加
    return {fenzi,fenmu};//no need to 化简
}

rationalNumber rnMean(rationalNumber a[], int n)
{
    rationalNumber s={0,1}; // set an accumulator
    for (int i=0;i<n;i++)   s=rnAdd(s,a[i]);// Sum
    s.fenmu*=n; // s div n
    return reduction(s);
}
/********** End **********/
