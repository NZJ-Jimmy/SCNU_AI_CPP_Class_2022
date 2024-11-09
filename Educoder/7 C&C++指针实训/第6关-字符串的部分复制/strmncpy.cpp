#include <iostream>
using namespace std;

void strmncpy(char *s, int m, int n, char *t);

int main()
{
    char s[128],t[128];
    int m,n;
    cin>>s;     // 输入源串
    cin>>m>>n;     // 输入m和n
    strmncpy(s, m, n, t);     // 字符串复制
    cout << t <<endl;     // 输出复制结果
    return 0;
}

// 函数strmncpy：字符串的部分复制，将s指向字符串从第m个字符开始的n个字符复制的t中
// 参数：s-指向源字符串，t-指向目标字符串，m-起始位置，n-字符个数
// 返回值：无
void strmncpy(char *s, int m, int n, char *t)
{
    // 请在此添加代码，实现函数strmncpy
    /********** Begin *********/
    if (*(s + m) == '\0')
        *t = '\0';
    else
    {
        s += m;
        int i;
        for (i = 0; i < n; i++)
        {
            *(t + i) = *(s + i);
            if (*(s + i) == '\0')
                break;
        }
        *(t + i) = '\0';
    }
    /********** End **********/
}