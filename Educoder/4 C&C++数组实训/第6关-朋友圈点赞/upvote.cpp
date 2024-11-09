// 请在此添加代码，通过统计朋友圈点赞，统计个人爱好功能
/********** Begin *********/
#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int a[1002];
    for (int i=0;i<1002;i++) a[i]=0;//memset(a,0,sizeof(a));
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        for (int j=0;j<k;j++)
        {
            int s;
            cin>>s;
            a[s]++;
        }
    }

    int max=INT_MIN,maxs;
    for (int i=0;i<1002;i++)
        if (a[i]>=max) 
        {
            max=a[i];
            maxs=i;
            //cout<<maxs<<' '<<max<<endl; //for testing
        }
    cout<<maxs<<' '<<max;
    return 0;
}
/********** End **********/