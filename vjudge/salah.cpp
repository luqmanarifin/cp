#include<bits/stdc++.h>
using namespace std;
int n,t,a,b,i;
bool B[20001],l;
int main()
{
    cin>>n>>t;
    for(i=1;i<=t;i++)
    {
        cin>>a>>b;
        if(B[a] && B[b])l=1;
        B[a]=1;
        B[b]=1;
    }
    if(n!=t+1)cout<<"NO"<<endl;
    else
    {
        if(l)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}