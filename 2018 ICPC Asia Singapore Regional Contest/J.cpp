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

int n,a,b;
int ada[405];

int main() 
{
  scanf("%d",&n);
  REP(i,n)
  {
    scanf("%d %d",&a,&b);
    FORN(j,a,b) ada[j] = 1;
  }
  int risan = 0;
  FORN(j,0,400) risan += ada[j];
  printf("%d\n",risan);
}
