# 2022级《高级语言程序设计》第5次作业

## 第1题

定义一个银行账号``bank``类，自定义类属性和输入（须至少有一个变量为指针类型）；使用有参构造函数初始化对象``bank1``，实现深拷贝构造函数，并通过深拷贝构造函数初始化对象``bank2``

### 解题思路

1. 把姓名设为``char*``类；
2. 用``new``实现深拷贝构造函数
3. 析构函数中要实现delete。
4. 为了怕有用户中途改名的情况，我们不对交易记录中的姓名进行深拷贝，只作指针的浅拷贝，这样就算用户改名，交易记录也能正确指向用户当前的名称。
5. 转账记录用结构体实现，为了节省内存，用``vector``实现动态结构体数组。

### 源代码

#### 头文件``bank.h``

```cpp
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class bank
{
private:
    char *Name;
    int Balance = 0;
    struct transaction
    {
        char *objectName; // 转账的来源或目标的Name，只存指针以应付改名
        int amount;       // 转账的金额
    };
    vector<transaction> record; //用vector实现动态数组

public:
    bank(char *name, int balance = 0); // 有参构造函数
    bank(const bank &source);          // 深拷贝构造函数
    void resetName(char *name);
    friend void transfer(bank &source, bank &target, unsigned int amount); // 用于转账
    void showStatus();
    ~bank();
    operator int() { return Balance; }
    operator char *() { return Name; }
};
inline void bank::resetName(char *name) // 重命名
{
    Name = new char[strlen(name)+1];
    strcpy(Name, name);
}

inline bank::bank(char *name, int balance)  // 实现构造函数
{
    Name = new char[strlen(name)+1];
    strcpy(Name, name);
    Balance = balance;
}

inline bank::bank(const bank &source)   //实现拷贝构造函数
{
    Balance = source.Balance;
    Name = new char[strlen(source.Name)+1];
    strcpy(Name, source.Name);
    for (int i = 0; i < source.record.size(); i++)
        record.push_back({source.record[i].objectName, source.record[i].amount}); // 考虑到可能改名的情况，在这里只作浅复制
                                                                                  // 这样的话名字只复制了指针，如果出现改名也能应付
}

inline void transfer(bank &source, bank &target, unsigned int amount)   // 实现转账
{
    // 用unsigned是防止有出现从别人钱包拿钱的非法转账。
    if (source.Balance < amount)
        cout << "Insufficient balance." << endl;
    else    //逐项拷贝
    {
        source.Balance -= amount;
        target.Balance += amount;
        source.record.push_back({target.Name, (int)-amount});
        target.record.push_back({source.Name, (int)amount});
        cout << "Successfully transfered " << amount << " from " << (char *)source << " to " << (char *)target << endl;
    }
}

inline void bank::showStatus()
{
    cout << "Here are " << Name << " 's " << record.size() << " transaction record(s):" << endl;
    for (int i = 0; i < record.size(); i++) // 显示转账记录
    {
        if (record[i].amount > 0)
            cout << record[i].objectName << " -> " << Name << "\t+" << record[i].amount << endl;
        else
            cout << Name << " -> " << record[i].objectName << "\t-" << -record[i].amount << endl;
    }
    cout << "Balance:" << Balance << endl;
}

inline bank::~bank()    // 析构函数，删除new新建的内存。
{
    cout << Name << "'s bank account has been deleted." << endl;
    delete[] Name;
}
```

#### 主程序``bank.cpp``

```cpp
#include "bank.h"
#include <iostream>
using namespace std;
int main()
{
    bank bank1((char*)"Ho-Lay", 600);     // 构造 我的银行账户
    bank bank2((char*)"Hak-Tsing", 5000); // 构造 朋友的银行账户
    bank bank3 = bank2;            // 拷贝构造函数，公司的账户 
    bank3.resetName((char*)"Mai-Hayau");  // company叫Mai-Hayau

    transfer(bank1, bank3, 648); // 调用成员函数转账，会余额不足
    transfer(bank2, bank1, 50);  // mate vivo 50
    transfer(bank1, bank3, 648); // 再课648，成功
    transfer(bank3, bank1, 324); // 首充半价返现

    cout << endl;
    bank1.showStatus(); // 调用成员函数，看看各自的状态与转账记录
    bank2.showStatus();
    bank3.showStatus();
    return 0;
}
```

### 运行情况

```
Insufficient balance.
Successfully transfered 50 from Hak-Tsing to Ho-Lay
Successfully transfered 648 from Ho-Lay to Mai-Hayau
Successfully transfered 324 from Mai-Hayau to Ho-Lay

Here are Ho-Lay 's 3 transaction record(s):
Hak-Tsing -> Ho-Lay     +50
Ho-Lay -> Mai-Hayau     -648
Mai-Hayau -> Ho-Lay     +324
Balance:326
Here are Hak-Tsing 's 1 transaction record(s):
Hak-Tsing -> Ho-Lay     -50
Balance:4950
Here are Mai-Hayau 's 2 transaction record(s):
Ho-Lay -> Mai-Hayau     +648
Mai-Hayau -> Ho-Lay     -324
Balance:5324
Mai-Hayau's bank account has been deleted.
Hak-Tsing's bank account has been deleted.
Ho-Lay's bank account has been deleted.
```

## 第2题

定义一个旅行（``travel``）类，包含的类变量有旅程的距离``length``、旅行的出发地和目的地、旅行携带的费用、旅行的花费项目（自定义多项花费，具体各项费用可用数组存储）；通过有参构造函数初始化对象``travel1``，通过重载“``=``”实现对另一对象``travel2``的赋值。要求实现的功能有：对象的各属性的输入输出（通过重载``<<``和``>>``实现）、计算对象``travel2``本次旅程携带的金钱是否足够本次旅程的花费。要求实现析构函数并提供对象操作的主函数。

### 解题思路

1. 同理，将每个花费项目用结构体存起来，包括名称和价格。
2. 按常规套路重载``=``、``>>``、``<<``。
3. 在输出中实现判断是否足够本次旅程的花费

### 源代码

#### 头文件``travel.h``

```cpp
#include <iostream>
#include <vector>
using namespace std;
class travel
{
private:
    int length, totalCost = 0, Budget = 0;
    string Departure, Destination;
    struct object
    {
        string name;
        int price;
    };  // 花费项目的结构体
    vector<object> cost;    // 用vector实现动态数组

public:
    travel(){}
    travel(int len, string depart, string dest, int budget);    // 构造函数
    ~travel();  //析构函数
    travel& operator=(travel &source);     // 重载=
    friend istream &operator>>(istream &is, travel &a);// 重载>>
    friend ostream &operator<<(ostream &os, travel &a);// 重载<<
    operator bool() { return totalCost < Budget; }
};

inline travel::travel(int len, string depart, string dest, int budget)
{
    length = len;
    Departure = depart;
    Destination = dest;
    Budget = budget;
}

inline travel& travel::operator=(travel &source)    // 一个个拷贝过去
{
    length = source.length;
    Departure = source.Departure;
    Destination = source.Destination;
    Budget = source.Budget;
    totalCost = source.totalCost;
    for (int i = 0; i < source.cost.size(); i++)
        cost.push_back({source.cost[i].name, source.cost[i].price});
    return *this;
}

istream &operator>>(istream &is, travel &a)
{
    cout << "Please enter the length:";
    is >> a.length;
    is.get();
    cout << "Please enter the departure:";
    getline(is, a.Departure);
    cout << "Please enter the destination:";
    getline(is, a.Destination);
    cout << "Please enter the budget:";
    is >> a.Budget;
    int n;
    cout << "How many objects?";
    is >> n;
    is.get();
    for (int i = 0; i < n; i++)
    {
        string str;
        int num;
        cout << "Object Name #" << i + 1 << ':';
        getline(is, str);
        cout << "Object Price #" << i + 1 << ':';
        is >> num;
        is.get();   // 读掉空格
        a.cost.push_back({str, num});
        a.totalCost += num;
    }
    return is;
}

ostream &operator<<(ostream &os, travel &a)
{
    os << a.Departure << " -> " << a.Destination << "\tLength: " << a.length << endl;
    os << "Cost list:" << endl;
    for (int i = 0; i < a.cost.size(); i++)
        os << a.cost[i].name << '\t' << a.cost[i].price << endl;
    os << "Total cost: " << a.totalCost << endl;
    if (a)
        os << "Money Enough." << endl;
    else
        os << "Money not enough." << endl;
    return os;
}

travel::~travel()
{
    cout << "The travel from " << Departure << " to " << Destination << " has been deleted." << endl;
}
```

#### 主程序``travel.cpp``

```cpp
#include "travel.h"
#include <iostream>
using namespace std;
int main()
{
    travel travel1(3100, "Mung Dak", "Lei Yut", 500000), travel2, travel3;
    cin >> travel2;
    travel3 = travel2;
    cout << travel1;
    cout << travel3;
    return 0;
}
```

#### 运行结果

```
Please enter the length:> 5200
Please enter the departure:> Dau Tsai
Please enter the destination:> Lai Yut
Please enter the budget:> 30000
How many objects?> 3
Object Name #1:> eat
Object Price #1:> 15000
Object Name #2:> drink
Object Price #2:> 20000
Object Name #3:> play
Object Price #3:> 30000
Mung Dak -> Lei Yut     Length: 3100
Cost list:
Total cost: 0
Money Enough.
Dau Tsai -> Lai Yut     Length: 5200
Cost list:
eat     15000
drink   20000
play    30000
Total cost: 65000
Money not enough.
The travel from Dau Tsai to Lai Yut has been deleted.
The travel from Dau Tsai to Lai Yut has been deleted.
The travel from Mung Dak to Lei Yut has been deleted.
```

## 第3题

定义一个``Shape``类记录二维平面上的任意形状的位置，在``Shape``类的基础上派生出一 个``Rectangle``类，在``Rectangle``类的基础上派生出一个``Square``类，必须保证每个类都有计算面积和周长的功能。要求使用虚函数并在主函数中实现动态绑定功能。

### 解题思路

1. 将``Shape``定义为抽象类（在里面放计算面积、周长的纯虚函数）
2. 从``Shape``中派生``Rectangle``和``Square``类，并在里面实现虚函数
3. 主程序用new创建各派生类，并实现虚函数。

### 源代码

#### 头文件``Shape.h``

```cpp
class Shape // 定义一个抽象类
{
public:
    virtual double area()=0;    // 两个纯虚函数，用于派生类虚函数的实现
    virtual double cir()=0;
};

class Rectangle : public Shape
{
private:
    int L, W;

public:
    Rectangle(int l, int w) : L(l), W(w){};
    virtual double area()   // 计算面积
    {
        return L * W;
    };
    virtual double cir()    // 计算周长
    {
        return L * 2 + W * 2;
    }
};

class Square : public Shape
{
private:
    int sideLen;

public:
    Square(int sl, int x = 0, int y = 0) : sideLen(sl) { Rectangle(sl, sl); }
    virtual double area()   // 计算面积
    {
        return sideLen * sideLen;
    }
    virtual double cir()    // 计算周长
    {
        return 4 * sideLen;
    }
};
```

#### 主程序``Shape.cpp``

```cpp
#include <iostream>
#include "Shape.h"
using namespace std;
int main()
{
    Shape *a = new Rectangle(2, 3);
    Shape *b = new Square(2);
    cout << "The Area of a: " << a->area() << endl
         << "The Area of b: " << b->area() << endl
         << "The Circumference of a: " << a->cir() << endl
         << "The Circumference of b: " << b->cir() << endl;
    return 0;
}
```

### 运行结果

```
The Area of a: 6
The Area of b: 4
The Circumference of a: 10
The Circumference of b: 8
```