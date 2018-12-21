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

int bf(int n,int r,int c,int k)
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
      // printf("%d\n",sini);
    }
    risan = (risan + sini) % MOD;
    // printf("%d %d %d %d %d %lld\n",i,j,ii,jj,sini,risan);
  }
  return risan;
}

int sumfr[5005],sumfc[5005];
int sumf[5005][5005];
int modpow[5015];

int sumg(int r,int c)
{
  LL now = sumf[r][c];
  now = now - 2 * sumf[r][c+1] - 2 * sumf[r+1][c];
  now = now + sumf[r][c+2] + 4LL * sumf[r+1][c+1] + sumf[r+2][c];
  now = now - 2 * sumf[r+2][c+1] - 2 * sumf[r+1][c+2];
  now = now + sumf[r+2][c+2];
  // now = (now % MOD + MOD) % MOD;
  while (now >= MOD) now -= MOD;
  while (now < 0) now += MOD;
  return now;
}

void normalize(int &x)
{
  if (x >= MOD) x -= MOD;
}

int answer(int n,int R,int C,int k)
{
  // if (n == 1000000 && R == 5000 && C == 5000 && k == 1)
  //   return 109292833;
  FORN(i,0,max(R,C)+10) modpow[i] = bigmod(i,n);
  // return 0;
  RESET(sumf,0);
  RESET(sumfr,0);
  RESET(sumfc,0);
  // return 0;
  FORN(r,1,R)
  {
    sumfr[r] = 0;
    FORN(x,1,R-r+1)
    {
      sumfr[r] = (sumfr[r] + (LL)modpow[x] * modpow[R-r-x+2] % MOD);
      normalize(sumfr[r]);
    }
  }
  FORN(c,1,C)
  {
    sumfc[c] = 0;
    FORN(y,1,C-c+1)
    {
      sumfc[c] = (sumfc[c] + (LL)modpow[y] * modpow[C-c-y+2] % MOD);
      normalize(sumfc[c]);
    }
  }
  // return 0;
  FORN(r,1,R) FORN(c,1,C)
  {
    sumf[r][c] = (LL)sumfr[r] * sumfc[c] % MOD;
    // printf("%d %d %d\n",r,c,sumf[r][c]);
    // printf("%d %d\n",r,c,sumf[r][c]);
  }
  // return 0;
  int risan = 0;
  FORN(r,1,R) FORN(c,1,C)
  {
    // printf("%d %d %d\n",r,c,sumg(r,c));
    if (r * c < k) continue;
    risan = (risan + sumg(r,c));
    normalize(risan);
  }
  return risan;
}

int main() 
{
  // printf("%d\n",answer(1,2,2,1));
  // return 0;
  // printf("%d\n",answer(1,2,1,1));
  // return 0;
  int n,r,c,k;
  scanf("%d %d %d %d",&n,&r,&c,&k);
  printf("%d\n",answer(n,r,c,k));
  return 0;
  while (1)
  // const int K = 5;
  // FORN(n,1,K) FORN(r,1,K) FORN(c,1,K) FORN(k,1,r*c)
  {
    int n = rand() % 1000000 + 1;
    int r = rand() % 100 + 1;
    int c = rand() % 100 + 1;
    int k = rand() % (r * c) + 1;
    printf("%d %d %d %d %d %d\n",n,r,c,k,answer(n,r,c,k),bf(n,r,c,k));
    assert(answer(n,r,c,k) == bf(n,r,c,k));
  }
  // printf("%d\n",answer(n,r,c,k));
}
