// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    char c;     // c-存储输入的字符
    cin >> c;     // 输入字符
    // 请在Begin-End之间添加代码，输出 c 的 8 位二进制表示
    /********** Begin *********/
	cout<< (int)(bool)(c & 128) << (int)(bool)(c & 64) << (int)(bool)(c & 32) << (int)(bool)(c & 16) << (int)(bool)(c & 8) << (int)(bool)(c & 4) << (int)(bool)(c & 2) << (int)(bool)(c & 1);
    
    
    /********** End **********/
    return 0;
}