#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> vi;

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SORTA(data,n) sort(data,data+n)
#define TC(t) while (t--)
#define pb push_back
#define SIZE(v) (int)v.size()
#define RESET(a,b) memset(a,b,sizeof(a))

const int INF = 1e9 + 2;

int n,m,a,b;
vi adj[500005];
int color[500005];
bool bipartite = 0;

void dfs(int now)
{
  for (int x : adj[now])
  {
    if (color[x] == -1)
    {
      color[x] = 1 - color[now];
      dfs(x);
    } else if (color[x] == color[now]) bipartite = 0;
  }
}

int main() 
{
  scanf("%d %d",&n,&m);
  TC(m)
  {
    scanf("%d %d",&a,&b);
    --a; --b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  RESET(color,-1);
  int risan = 0;
  bipartite = 1;
  REP(i,n) if (color[i] == -1)
  {
    color[i] = 0;
    dfs(i);
    ++risan;
  }
  if (!bipartite) --risan;
  printf("%d\n",risan);
}
