#include <iostream>
using namespace std;

struct rationalNumber{
    int fenzi; // 分子
    int fenmu; // 分母
};

// 函数rnAdd：两个有理数相加
// 参数：x,y-两个有理数
// 返回值：x+y的最简分数形式
rationalNumber rnAdd(rationalNumber x, rationalNumber y);

int main()
{
    char c;
    rationalNumber x, y, z;
    // 输入两个有理数
    cin >> x.fenzi >> c >> x.fenmu;
    cin >> y.fenzi >> c >> y.fenmu;
    z = rnAdd(x,y);     // 有理数相加
    // 输出相加的结果
    if(z.fenmu == 1)
        cout << z.fenzi << endl;
    else
        cout << z.fenzi << "/" << z.fenmu << endl;
    return 0;
}

// 请在此添加代码，实现函数rnAdd
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
    return reduction({fenzi,fenmu});//化简
}
/********** End **********/

