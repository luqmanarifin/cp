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

long long H(long long previousHash, string &transaction,
            long long token) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}

long long HH(long long previousHash, string &transaction,
            long long target) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  LL now = v * 7 % 1000000007;
  return (target + 1000000007 - now) % 1000000007;
  // return (v * 7 + token) % 1000000007;
}

LL now;

int main() 
{
  scanf("%lld",&now);
  FORN(i,1,2)
  {
    string x = "a";
    FORN(j,1,INF)
    {
      LL k = j * 10000000LL;
      LL token = HH(now,x,k);
      if (0 <= token && token < 1000000000)
      {
        printf("%s %lld\n",x.c_str(),token);
        now = k;
        break;
      }
    }
  }
  string x = "a";
  // printf("%lld\n",H(140000000,x,629999538));
  // printf("%lld\n",H(10000000,x,839999342));
}
