#include <iostream>
using namespace std;

// 函数leapYear
int leapYear(int y)
{
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;
    return 0;
}

// 函数whatDay：计算某年某月某日是星期几
// 参数：year-年，month-月
// 返回值：--7分别表示星期一到星期日
int whatDay(int year, int month)
{
    // 请在这里补充代码，实现函数whatDay
    /********** Begin *********/
    int sumdays = 0;
    for (int i = 1; i < year; i++)  //计算1~前一年一共有多少天
        sumdays += leapYear(i) ? 366 : 365;
    
    for (int i = 1; i < month; i++) //计算最后一年有多少天，不需要计算最后一个月
    {
        switch (i)
        {
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            sumdays += 31;
            break;
        case 2:
            sumdays += 28 + leapYear(year);
            break;
        default : 
            sumdays += 30;
            break;
        }
    }
    return sumdays % 7 + 1;   // 加上最后一月的第一天
    /********** End **********/
}

int main()
{
    int y, m, xq;     // 年、月、星期几
    cin >> y >> m;     // 输入年月
    xq = whatDay(y,m);     // 计算星期几
    cout << y << "年" << m << "月1日是星期";     // 输出星期
    if(xq == 7)
        cout << "日" << endl;
    else
        cout << xq << endl;
    return 0;
}