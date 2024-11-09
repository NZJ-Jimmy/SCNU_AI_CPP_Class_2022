#include <iostream>
using namespace std;

/********* Begin *********/
//在此处实现一个汽车类
class Car
{
private:
    string door = "OFF", light = "OFF";
    int speed = 0;

public:
    void onLight() { light = "ON"; }
    void offLight() { light = "OFF"; }
    void openDoor() { door = "ON"; }
    void offDoor() { door = "OFF"; }
    void speedUp() { speed += 10; }
    void speedDown() { speed -= 10; }
    void printStatus()
    {
        cout << "车门 " << door << endl;
        cout << "车灯 " << light << endl;
        cout << "速度 " << speed << endl;
    }
};
/********* End *********/

int main()
{
    /********* Begin *********/
    //在此处解析执行输出汽车的整体状态
    char cmds[25];
    Car a;
    cin >> cmds;
    int i = 0;
    while (cmds[i] != '\0')
    {
        switch (cmds[i])
        {
        case '1':
            a.openDoor();
            break;
        case '2':
            a.offDoor();
            break;
        case '3':
            a.onLight();
            break;
        case '4':
            a.offLight();
            break;
        case '5':
            a.speedUp();
            break;
        case '6':
            a.speedDown();
            break;
        default:
            break;
        }
        i++;
    }
    a.printStatus();
    return 0;
    /********* End *********/
}