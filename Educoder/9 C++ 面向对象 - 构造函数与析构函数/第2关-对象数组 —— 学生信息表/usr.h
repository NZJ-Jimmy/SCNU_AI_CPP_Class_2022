#include <string>
#include <iostream>
using namespace std;

/********* Begin *********/
class Student
{
    //在此处声明所需的成员
private:
    int SID;
    string Name;
    float Score;

public:
    Student(){};
    Student(int sid, string name, float sco) { SID = sid, Name = name, Score = sco; }
    void print() { cout << SID << ' ' << Name << ' ' << Score << endl; }
    int getScore() { return Score; }
} a[5];
int n = 0;
/********* End *********/

void Add(int sid, string name, float sco)
{
    /********* Begin *********/
    a[n++] = Student(sid, name, sco);
    /********* End *********/
}

void PrintAll()
{
    /********* Begin *********/
    //打印出学生表中所有记录
    for (int i = 0; i < n; i++)
        a[i].print();

    /********* End *********/
}

void Average()
{
    /********* Begin *********/
    //计算并打印出学生表中的平均成绩
    float s = 0;
    for (int i = 0; i < n; i++)
        s += a[i].getScore();
    cout << "平均成绩 " << 1.0 * s / n << endl;
    /********* End *********/
}