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