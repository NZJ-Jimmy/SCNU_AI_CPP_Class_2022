#include <cstring>
#include <iostream>
using namespace std;
class Person
{
private:
    char *Id, *Name, *Gender, *Birth, *HomeAddress;

public:
    Person(char *id, char *name, char *gender, char *birth, char *homeAddress); // 构造函数
    Person();                                                                   // 空构造函数
    Person(Person &a);                                                          // 深复制构造函数
    friend ostream &operator<<(ostream &os, Person &a);                         // 重载输出
    friend istream &operator>>(istream &is, Person &a);                         // 重载输入
    ~Person();                                                                  // 析构函数
};

void strdeepcpy(char *&dest, char *&source) // 新建一个函数，用于char*深拷贝
{
    dest = new char[strlen(source) + 1];
    strcpy(dest, source);
}

Person::Person(char *id, char *name, char *gender, char *birth, char *homeAddress)
{
    strdeepcpy(Id, id);
    strdeepcpy(Name, name);
    strdeepcpy(Gender, gender);
    strdeepcpy(Birth, birth);
    strdeepcpy(HomeAddress, homeAddress);
}

Person::Person() // 空构造函数需要new以防止指针乱指
{
    Id = new char[50];
    Name = new char[50];
    Gender = new char[5];
    Birth = new char[12];
    HomeAddress = new char[100];
}

Person::Person(Person &a)
{
    strdeepcpy(Id, a.Id);
    strdeepcpy(Name, a.Name);
    strdeepcpy(Gender, a.Gender);
    strdeepcpy(Birth, a.Birth);
    strdeepcpy(HomeAddress, a.HomeAddress);
}

istream &operator>>(istream &is, Person &a)
{
    cout << "ID: ";
    is.getline(a.Id, 50);
    cout << "Name: ";
    is.getline(a.Name, 50);
    cout << "Gender: ";
    is.getline(a.Gender, 50);
    cout << "Birthday: ";
    is.getline(a.Birth, 50);
    cout << "Home Address: ";
    is.getline(a.HomeAddress, 50);
}

ostream &operator<<(ostream &os, Person &a)
{
    os << "Id: " << a.Id << endl
       << "Name: " << a.Name << endl
       << "Gender: " << a.Gender << endl
       << "Birthday: " << a.Birth << endl
       << "Home Address: " << a.HomeAddress << endl;
}

Person::~Person() // 析构函数，delete用new开辟的空间，防止内存泄漏
{
    delete Id;
    delete Name;
    delete Gender;
    delete Birth;
    delete HomeAddress;
}
