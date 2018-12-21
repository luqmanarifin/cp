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

int n;
int data[400005];
set<int> sisa;
int kiri[400005];
int kanan[400005];
pii risan = mp(INF,INF);
int tree[2000005];

void update(int ix,int L,int R,int x,int y,int val)
{
  // printf("UPDATE %d %d %d\n",x,y,val);
  // printf("%d: (%d, %d) = %d\n",ix,L,R,tree[ix]);
  if (x <= L && R <= y)
  {
    MIN(tree[ix],val);
    return;
  }
  if (R < x || y < L) return;
  MIN(tree[ix*2+1],tree[ix]);
  MIN(tree[ix*2+2],tree[ix]);
  int M = (L + R) >> 1;
  update(ix*2+1,L,M,x,y,val);
  update(ix*2+2,M+1,R,x,y,val);
}

int query(int ix,int L,int R,int pos)
{
  // printf("%d: (%d, %d) = %d\n",ix,L,R,tree[ix]);
  if (L == R) return tree[ix];
  MIN(tree[ix*2+1],tree[ix]);
  MIN(tree[ix*2+2],tree[ix]);
  int M = (L + R) >> 1;
  if (pos <= M) return query(ix*2+1,L,M,pos);
  return query(ix*2+2,M+1,R,pos);
}

int main() 
{
  scanf("%d",&n);
  REP(i,n) scanf("%d",&data[i]);
  RESET(kanan,-1);
  RESET(kiri,-1);
  FORN(i,0,2000000) tree[i] = INF;
  FORD(i,n-1,0)
  {
    // printf("====>%d\n",i);
    int x = kanan[data[i]];
    // printf("%d\n",x);
    if (x != -1)
    {
      int val = query(0,0,n-1,x);
      // printf("%d\n",val);
      if (val != INF) MIN(risan,mp(data[i],val));
      update(0,0,n-1,i+1,x-1,data[i]);
    }
    if (kanan[data[i]] == -1) kanan[data[i]] = i;
    kiri[data[i]] = i;
  }
  if (risan == mp(INF,INF)) printf("%d\n",-1);
  else printf("%d %d\n",risan.fi,risan.se);
}
