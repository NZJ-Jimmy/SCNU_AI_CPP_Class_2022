#include <iostream>
#include <string>
using namespace std;

class Student
{
    /********* Begin *********/
private:
    int SID;
    string Name;

public:
    Student(int sid, string name);
    ~Student();
    //在此处声明所需的成员
    /********* End *********/
};

/********* Begin *********/
Student::Student(int sid=0, string name="王小明")
{
    SID = sid;
    Name = name;
}
Student::~Student()
{
    cout << SID << ' ' << Name << ' ' << "退出程序" << endl;
}
//在此处定义成员函数

/********* End *********/
