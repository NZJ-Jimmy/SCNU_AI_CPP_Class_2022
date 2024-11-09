#include <iostream>
using namespace std;
int main()
{
    double n;
    cout << "请输入地震的里氏强度: " << endl;
    cin >> n;
    switch (int(n))  // 用switch写少几条if，观察到里氏强度与其整数部分才有关，因此利用int小数取整的特性。
    {
    case 4:
        cout << "本次地震后果：窗户晃动！" << endl;
        break;
    case 5:
        cout << "本次地震后果：墙倒塌；不结实的建筑物被破坏！" << endl;
        break;
    case 6:
        cout << "本次地震后果：烟囱倒塌；普通建筑物被破坏！" << endl;
        break;
    case 7:
        cout << "本次地震后果：地下管线破坏；结实的建筑物也被破坏！" << endl;
        break;
    default:
        if (n<4)
            cout << "本次地震后果：很小！" << endl;
        if (n>8)
            cout << "本次地震后果：地面波浪状起伏；大多数建筑物损毁！" << endl;
        if (n==8)   // 处理8这个特殊情况，8未超过8。
            cout << "本次地震后果：地下管线破坏；结实的建筑物也被破坏！" << endl;
        break;
    }
    return 0;
}