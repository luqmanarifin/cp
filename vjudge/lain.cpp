#include<bits/stdc++.h>
using namespace std;
int t,m,n,i,j,dx[8]={1,-1,0,0,1,1,-1,-1},dy[8]={0,0,1,-1,1,-1,1,-1};
char A[101][101];
string str="ALLIZZWELL";
bool found,done[101][101];
bool valid(int x,int y)
{
    return x>0 && x<=m && y>0 && y<=n;
}
void dfs(int x, int y, int i)
{
    if(i==str.size()) found=1;
    if(found or done[x][y]) return;
    if(A[x][y]==str[i])
    {
        done[x][y]=1;
        for(int j=0;j<8;j++)
        {
            int tx=x+dx[j];
            int ty=y+dy[j];
            if(valid(tx,ty)) dfs(tx,ty,i+1);
        }
        done[x][y]=0;
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        found=0;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++) done[i][j]=0;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++) cin>>A[i][j];
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++) dfs(i,j,0);
        if(found) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}