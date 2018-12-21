#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SORT(v) sort(v.begin(),v.end())
#define SORTA(data,n) sort(data,data+n)
#define TC(t) while (t--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define ALLA(v, sz) v, v + sz
#define SIZE(v) (int)v.size()
#define RESET(a,b) memset(a,b,sizeof(a))

const int INF = 1e9 + 2;

int dirx[4] = {-1, 0, 0, 1};
int diry[4] = {0, 1, -1, 0};

int r,c,b;
vii adax[400005];
vii aday[400005];
pii data[400005];
vi adj[400005];
int indeg[400005];
int parent[400005];
int dir[400005];

int ada(int x,int y)
{
  if (adax[x].size() == 0) return -1;
  int z = lower_bound(ALL(adax[x]),mp(y,-INF)) - adax[x].begin();
  if (z == SIZE(adax[x])) return -1;
  if (adax[x][z].fi != y) return -1;
  return adax[x][z].se;
}

void dfs(int now,int predir)
{
  // printf("%d %d\n",now,predir);
  if (predir != -1) dir[now] = 3 - predir;
  REP(i,4) if (predir == -1 || i != dir[now])
  {
    // printf(">>>>%d %d\n",now,i);
    int x = data[now].fi + dirx[i];
    int y = data[now].se + diry[i];
    if (x < 0 || y < 0) continue;
    int z = ada(x,y);
    if (z == -1) continue;
    parent[z] = now;
    dfs(z,i);
  }
  // printf("%d %d\n",now,predir);
}

void addedge(int a,int b)
{
  adj[a].pb(b);
  ++indeg[b];
}

int main() 
{
  scanf("%d %d %d",&r,&c,&b);
  REP(i,b)
  {
    scanf("%d %d",&data[i].fi,&data[i].se);
    --data[i].fi; --data[i].se;
    adax[data[i].fi].pb(mp(data[i].se, i));
    aday[data[i].se].pb(mp(data[i].fi, i));
  }
  REP(i,r) SORT(adax[i]);
  REP(j,c) SORT(aday[j]);
  dfs(0,-1);
  // REP(i,b) printf("%d %d %d\n",i,parent[i],dir[i]);
  FOR(i,1,b)
  {
    addedge(parent[i],i);
    int x = data[i].fi;
    int y = data[i].se;
    if (dir[i] == 0)
    {
      int z = lower_bound(ALL(aday[y]), mp(x,INF)) - aday[y].begin();
      if (z < SIZE(aday[y])) addedge(i, aday[y][z].se);
    } else if (dir[i] == 1)
    {
      int z = lower_bound(ALL(adax[x]), mp(y,-INF)) - adax[x].begin() - 1;
      // printf("%d %d\n",i,z);
      if (z >= 0) addedge(i, adax[x][z].se);
    } else if (dir[i] == 2)
    {
      int z = lower_bound(ALL(adax[x]), mp(y,INF)) - adax[x].begin();
      if (z < SIZE(adax[x])) addedge(i, adax[x][z].se);
    } else 
    {
      int z = lower_bound(ALL(aday[y]), mp(x,-INF)) - aday[y].begin() - 1;
      if (z >= 0) addedge(i, aday[y][z].se);
    }
  }
  // REP(i,b)
  // {
  //   printf("%d:",i);
  //   for (int j : adj[i]) printf(" %d",j);
  //     puts("");
  // }
  queue<int> q;
  REP(i,b) if (indeg[i] == 0) q.push(i);
  vi risan;
  while (!q.empty())
  {
    int now = q.front();
    risan.pb(now);
    q.pop();
    for (int i : adj[now])
    {
      --indeg[i];
      if (indeg[i] == 0) q.push(i);
    }
  }
  if (SIZE(risan) != b) puts("impossible");
  else
  {
    puts("possible");
    for (int i : risan)
    {
      if (i == 0) continue;
      int x = data[i].fi;
      int y = data[i].se;
      if (dir[i] == 0) printf("^ %d\n",y + 1);
      if (dir[i] == 1) printf("> %d\n",x + 1);
      if (dir[i] == 2) printf("< %d\n",x + 1);
      if (dir[i] == 3) printf("v %d\n",y + 1);
    }
  }
}
