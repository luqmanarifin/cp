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
int MOD = 1e9 + 7;

int n,r,c,k;

int g(int a,int b,int c,int d)
{
  return (LL)a * b % MOD * c % MOD * d % MOD;
}

int bigmod(int a,int b)
{
  if (b == 0) return 1;
  if (b == 1) return a % MOD;
  LL tmp = bigmod(a,b/2);
  LL tmp2 = tmp * tmp % MOD;
  if (b % 2 == 0) return tmp2;
  return tmp2 * a % MOD;
}

int f(int n,int r,int c,int k)
{
  int risan = 0;
  REP(i,r) FOR(ii,i,r) REP(j,c) FOR(jj,j,c)
  {
    if ((ii - i + 1) * (jj - j + 1) < k) continue;
    LL now = 0;
    int xa = i + 1;
    int ya = j + 1;
    int xb = r - ii;
    int yb = c - jj;
    // printf("%d %d %d %d\n",xa,ya,xb,yb);
    vector<int> ada = vector<int>({xa, ya, xb, yb});
    int sini = 0;
    REP(bit,1<<4)
    {
      LL now = 1;
      REP(k,4) if (bit & (1 << k)) now = now * (ada[k] - 1) % MOD;
      else now = now * ada[k] % MOD;
      now = bigmod(now,n);
      if (__builtin_popcount(bit) & 1) sini = (sini - now + MOD) % MOD;
      else sini = (sini + now) % MOD;
      printf("%d\n",sini);
    }
    risan = (risan + sini) % MOD;
    // printf("%d %d %d %d %d %lld\n",i,j,ii,jj,sini,risan);
  }
  return risan;
}

int main() 
{
  int n,r,c,k;
  // FORN(n,1,10)
  // {
  //   printf("N = %d\n",n);
  //   FORN(r,1,10)
  //   {
  //     FORN(c,1,10) printf("%d ",f(n,r,c,1));
  //     puts("");
  //   }
  //   puts("=========");
  // }
  scanf("%d %d %d %d",&n,&r,&c,&k);
  printf("%d\n",f(n,r,c,k));
}
