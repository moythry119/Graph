#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,c=0;
    cin>>n;
    int a[n];
    string s;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
            c++;
    }

  //  cout<<c<<endl;
    if(c==0)
    {
        cout<<"EASY"<<endl;
    }
    else
        cout<<"HARD"<<endl;


}
