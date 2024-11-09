#include <string>
#include <iostream>
using namespace std;

/********* Begin *********/
static int sUsers = 0, sBooks = 0;
class User
{
    //在此处声明所需的成员
private:
    string Name;
    int Books;

public:
    User(string name, int books);
    ~User();
    static void GetState();
};

//在此处定义成员函数
User::User(string name, int books)
{

    Name = name;
    Books = books;
    cout << Name << ' ' << Books << " 进入" << endl;
    sUsers++, sBooks += books;
}

User::~User()
{
    cout << Name << ' ' << Books << " 离开" << endl;
    sUsers--, sBooks -= Books;
}

void User::GetState()
{
    if (sUsers > 0)
        cout << "书店人数:" << sUsers << "，书店共享书数量:" << sBooks << "，人均共享数量:" << sBooks / sUsers << endl;
}
/********* End *********/
