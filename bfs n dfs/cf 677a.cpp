#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,h,cnt=0;
    cin>>n>>h;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<=h)
            cnt++;
        else
        {
            cnt+=2;
        }
    }
    cout<<cnt<<endl;
}
