/********* Begin *********/
class Rectangle
{
    //在此处实现Rectangle类
    private:
        int height, width;
    public:
        Rectangle(int h,int w)
        {
            height = h;
            width = w;
        }
        int GetRectArea()
        {
            return height * width;
        }
};
/********* End *********/

Rectangle GetRect(int h,int w)
{
    /********* Begin *********/
    //返回一个 h*w 的 Rectangle 对象
    Rectangle a(h,w);
    return a;
    /********* End *********/
}

int GetRectArea(Rectangle rect)
{
    /********* Begin *********/
    //返回 rect 对象的面积
    return rect.GetRectArea();
    /********* End *********/
}

