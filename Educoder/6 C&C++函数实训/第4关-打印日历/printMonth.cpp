// 包含两种I/O库，可以使用任一种输入输出方式
#include <stdio.h>
#include <iostream>
using namespace std;

// 函数printMonth：按要求的格式打印某年某月的日历
// 参数：year-年，month-月
// 返回值：无
void printMonth(int year, int month);

// leapYear：判断闰年
// 参数：y-年
// 返回值：1-是闰年，0-不是闰年
int leapYear(int y)
{
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        return 1;
    return 0;
}

// 函数whatDay:计算某年某月的1号是星期几
// 参数：year-年，month-月
// 返回值：1到7--星期1到星期日
int whatDay(int year, int month)
{
    // 1年月日是星期一
    int w = 1;
    int i;

    // 1到year-1都是全年
    for(i = 1; i < year; i++)
    {
        if(leapYear(i))
            w += 366;
        else
            w += 365;
    }
    switch(month)
    {
    case 12: // 加月的
        w += 30;
    case 11: // 加月的
        w += 31;
    case 10: // 加月的
        w += 30;
    case 9:  // 加月的
        w += 31;
    case 8:  // 加月的
        w += 31;
    case 7:  // 加月的
        w += 30;
    case 6:  // 加月的
        w += 31;
    case 5:  // 加月的
        w += 30;
    case 4:  // 加月的
        w += 31;
    case 3:  // 加月的
        if(leapYear(year))
            w += 29;
        else
            w += 28;
    case 2:  // 加月的天
        w += 31;
    case 1:  // 1月不加了
        ;
    }

    // 得到-6，其中为星期天
    w = w % 7;

    // 调整星期天
    if(w == 0)
        w = 7;
    return w;
}

// 请在下面补充代码，实现函数printMonth
/*************** Begin **************/
void printDay(int day)
{
    cout << "  ";   //每天前都有2个空格
    if (day<10)
        cout << ' ';    //如果天数小于2位数，则需要补位
    if (day==0)
        cout << ' ';    //如果天数为0（月未开始），则再补位（总共4个空格）
    else
        cout << day;    //排除了所有特殊情况，输出天。
}
void printMonth(int year, int month)
{
    int mDays[13] = {0, 31, 28+leapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        //当月总天数
    cout << "  一  二  三  四  五  六  日" << endl; //输出星期行
    int wDay = 0, sDay = 0; // wDay记录星期几，sDay记录已输出的天
    int wStart=whatDay(year,month); //wStart为月首日的星期几

    while (sDay < mDays[month])
    {
        wDay++;
        if (wDay>=wStart)   //若月首日才开始记数
            sDay++;
        printDay(sDay);
        if (wDay%7==0)
            cout << endl;   //周末换行
    }
}
/*************** End **************/

int main()
{
    // 年、月
    int y, m;

    // 输入年月
    cin >> y >> m;

    // 输出该年月的日历
    printMonth(y,m);

    return 0;
}