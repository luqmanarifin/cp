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

const int INF = 1e9 + 2;

int n,k;
int data[1000005];
int sparse[21][1000005];
int nowsparse[21][1000005];
int risan = 0;

const int OK = -1;

int jarak(int a,int b)
{
  return a < b ? b - a : b + n - a;
}

int dekat(int a,int b,int c)
{
  if (a == b) return b;
  if (a == c) return c;
  return jarak(a,b) <= jarak(a,c) ? b : c;
}

int jauh(int a,int b,int c)
{
  return jarak(a,b) >= jarak(a,c) ? b : c; 
}

int main() 
{
  scanf("%d %d",&n,&k);
  REP(i,n) sparse[0][i] = (i + 1) % n;
  REP(i,n) scanf("%d",&data[i]);
  FORD(bit,30,0)
  {
    int kecil = INF;
    REP(i,n) if (data[i] & (1 << bit)) MIN(kecil,i);
    if (kecil == INF) continue;
    int besar = INF;
    FORD(i,n-1,0)
    {
      if (data[i] & (1 << bit)) MIN(besar,i);
      int now = (dekat(i,kecil,besar) + 1) % n;
      nowsparse[0][i] = jauh(i,sparse[0][i],now);
      // printf("%d %d %d %d\n",i,kecil,besar,now);
    }
    FOR(i,1,21) REP(j,n)
    {
      int x = nowsparse[i-1][j];
      if (x == OK) nowsparse[i][j] = OK;
      else
      {
        int y = nowsparse[i-1][x];
        if (y == OK) nowsparse[i][j] = OK;
        if (jarak(j,x) + jarak(x,y) > n) nowsparse[i][j] = OK;
        else nowsparse[i][j] = y;
      }
    }
    // printf("==== %d\n", bit);
    // REP(i,21)
    // {
    //   REP(j,n) printf("%2d ",nowsparse[i][j]);
    //   puts("");
    // }
    REP(j,n)
    {
      int steps = 0;
      int now = j;
      FORD(i,20,0) if (k & (1 << i))
      {
        // printf("%d %d %d\n",now,j,i);
        if (nowsparse[i][now] == OK) goto gabisa;
        // if (jarak(now,nowsparse[i][now]) > jarak(now,j)) goto gabisa;
        // steps |= (1 << i);
        steps += jarak(now,nowsparse[i][now]);
        now = nowsparse[i][now];
      }
      if (steps > n) goto gabisa;
      // printf("%d\n",j);
      if (true)
      {
        REP(i,21) REP(j,n) sparse[i][j] = nowsparse[i][j];
        risan |= (1 << bit);
        break;
      }
      gabisa:;
    }
    // gabisa:;
  }
  printf("%d\n",risan);
}
