#include<bits/stdc++.h>
using namespace std;
int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int edist(string a, string b, int m, int n)
{
    int yes[m+1][n+1];
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            
            if (a[i-1] == b[j-1] && i-1 >= 0 && j-1 >= 0) // i == 0 atau j == 0, i-1 = -1
                yes[i][j] = yes[i-1][j-1];
            else {
                int ret = 1e8;
                if(j-1 >= 0) ret = min(ret, yes[i][j-1]);
                if(i-1 >= 0) ret = min(ret, yes[i-1][j]);
                if(i-1 >= 0 && j-1 >= 0) ret = min(ret, yes[i-1][j-1]);
                yes[i][j] = 1 + ret;
            }
        }
    }

    return yes[m][n];
}

int o;
string a,b;

int main()
{
    cin>>o;
    for (int i=1;i<=o;i++)
    {
       cin>>a>>b;
        cout<<edist(a, b, a.length(), b.length());
    }
    return 0;
}