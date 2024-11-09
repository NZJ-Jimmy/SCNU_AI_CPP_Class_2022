#include <iostream>
using namespace std;
void strcpypart(char *p, char *q, int n = 1, int m = 1)
{
    int j = 0;
    for (int i = n; i <= m; i++)
        q[j++] = p[i]; // 逐位复制，利用j++先传值后递增简化代码
    q[j] = '\0';       // 截断字符串
}
int main()
{
    char p[100] = "abcdabcdaabbccdd";
    char q[100];
    strcpypart(p, q, 2, 5);
    cout << q << endl;
    return 0;
}