#include <iostream>
using namespace std;

void extractNum(char * str);

int main()
{
    char s[1024];
    cin.getline(s,1024);     // 输入一行字符
    extractNum(s);     // 调用extractNum函数，选出数字
    cout<<s<<endl;     // 输出选出的数字
    return 0;
}

// 函数extractNum：选出str指向的字符串中的数字，并写回str
// 参数：str-指向字符串
void extractNum(char * str)
{
    // 请在此添加代码，实现函数extractNum
    /********** Begin *********/
    int i = 0, p = 0;
    bool minus = 0;
    while (*(str+i)!='\0')
    {
        if (*(str+i)>='0' && *(str+i)<='9' || (!minus) && *(str+i)=='-')
        {
            minus = 1;
            *(str + p) = *(str + i);
            p++;
        }
        i++;
    }
    *(str + p) = '\0';
    /********** End **********/
}