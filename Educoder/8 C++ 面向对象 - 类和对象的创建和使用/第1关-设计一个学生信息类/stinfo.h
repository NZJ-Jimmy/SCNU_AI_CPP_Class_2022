#include <iostream>
using namespace std;

class StInfo
{
    /********* Begin *********/
    //在此处声明StInfo类
private:
    int SID;
    char *Name;
    char *Class;
    char *Phone;

public:
    void SetInfo(int sid, char *name, char *cla, char *phone);
    void PrintInfo();
    /********* End *********/
};

/********* Begin *********/
//在此处定义StInfo类
void StInfo::SetInfo(int sid, char *name, char *cla, char *phone)
{
    SID = sid;
    Name = name;
    Class = cla;
    Phone = phone;
}

void StInfo::PrintInfo()
{
    cout << "学号：" << SID << endl;
    cout << "姓名：" << Name << endl;
    cout << "班级：" << Class << endl;
    cout << "手机号：" << Phone << endl;
}
/********* End *********/
