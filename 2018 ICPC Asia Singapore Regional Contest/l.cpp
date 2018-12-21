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

// vi fprime[2000005];
int fprime[2000005];
bool pr[2000005];
int q,n;
int risan[2000005];

int main() 
{
  memset(pr,1,sizeof(pr));
  pr[1] = 0;
  FORN(i,2,2000000) if (pr[i])
  {
    FORN(j,1,INF)
    {
      if ((LL)i * j > 2000000) break;
      if (j > 1) pr[i*j] = 0;
      // fprime[i * j].pb(i);
      fprime[i * j] = i;
    }
  }
  // return 0;
  // q = 3000000;
  FORN(i,2,2000000)
  {
    n = i;
    // int primes = SIZE(fprime[n]);
    int factors = 1;
    int x = n;
    int last = 0;
    int ada = 0;
    int beda = 0;
    while (x > 1)
    {
      int now = fprime[x];
      // if (i == 100) printf("%d %d\n",now,x);
      if (now != last)
      {
        ++beda;
        factors *= (ada + 1);
        ada = 1;
      } else ++ada;
      x /= now;
      last = now;
    }
    factors *= (ada + 1);
    // if (i == 100) printf("%d %d\n",factors, beda);
    // REP(i,SIZE(fprime[n]))
    // {
    //   int ada = 0;
    //   while (x % fprime[n][i] == 0)
    //   {
    //     ++ada;
    //     x /= fprime[n][i];
    //   }
    //   factors *= (ada + 1);
    // }
    risan[i] = factors - beda;
  }
  // return 0;
  scanf("%d",&q);
  TC(q)
  {
    scanf("%d",&n);
    printf("%d\n",risan[n]);
    // continue;
    // n = 2000000;
    // int primes=  SIZE(fprime[n]);
    // int factors = 1;
    // int x = n;
    // REP(i,SIZE(fprime[n]))
    // {
    //   int ada = 0;
    //   while (x % fprime[n][i] == 0)
    //   {
    //     ++ada;
    //     x /= fprime[n][i];
    //   }
    //   factors *= (ada + 1);
    // }
    // printf("%d\n",factors - primes);
  }
}
