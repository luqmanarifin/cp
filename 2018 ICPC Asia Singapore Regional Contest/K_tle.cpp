#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef pair<int,int> pii;

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
#define mp make_pair
#define fi first
#define se second
#define SIZE(v) (int)v.size()
#define RESET(a,b) memset(a,b,sizeof(a))

const int INF = 1e9 + 2;

class MaxFlow
{
public:
  int n,start,end;
  unordered_map<int,int> cap[100005];
  vi adj[100005];

  void reset(int _n)
  {
    n = _n;
    start = n - 2;
    end = n - 1;
    REP(i,n)
    {
      cap[i].clear();
      adj[i].clear();
    }
  }

  void addEdge(int a,int b,int c)
  {
    adj[a].pb(b);
    adj[b].pb(a);
    cap[a][b] += c;
  }

  int bisa(void)
  {
    queue <pii> q;
    int parent[n + 5];
    bool sudah[n + 5];
    RESET(parent,-1);
    RESET(sudah,0);
    q.push(mp(start,INF));
    parent[start] = -1;
    sudah[start] = 1;
    while (!q.empty())
    {
      pii now = q.front();
      q.pop();
      if (now.fi == end)
      {
        int ix = now.fi;
        while (ix != start)
        {
          cap[parent[ix]][ix] -= now.se;
          cap[ix][parent[ix]] += now.se;
          ix = parent[ix];
        }
        return now.se;
      }
      REP(i,SIZE(adj[now.fi]))
      {
        int dest = adj[now.fi][i];
        if (cap[now.fi][dest] > 0)
        {
          int jalan = min(cap[now.fi][dest],now.se);
          if (!sudah[dest])
          {
            parent[dest] = now.fi;
            sudah[dest] = 1;
            q.push(mp(dest,jalan));
          }
        }
      }
    }
    return 0;
  }

  int count()
  {
    int res = 0;
    while (1)
    {
      int x = bisa();
      if (x == 0) break;
      res += x;
    }
    return res;
  }
};

MaxFlow MF;
int n,k,m;
int a,b;

int main() 
{
  scanf("%d %d %d",&n,&k,&m);
  MF.reset(n*k+2);
  TC(m)
  {
    scanf("%d %d",&a,&b);
    --a; --b;
    REP(i,k)
    {
      int x = a * k + i;
      int y = b * k + (i + 1) % k;
      MF.addEdge(x,y,1);
    }
  }
  REP(i,k) 
  {
    MF.addEdge(MF.start,i*k+i,1);
  }
  REP(i,k)
  {
    MF.addEdge((n-1) * k + i,MF.end,k);
  }
  int risan = MF.count();
  printf("%d\n",risan);
}
