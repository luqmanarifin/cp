//start of jonathanirvings' template v3.0.3 (BETA)
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;
 
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};
 
#ifdef TESTING
  #define DEBUG fprintf(stderr,"====TESTING====\n")
  #define VALUE(x) cerr << "The value of " << #x << " is " << x << endl
  #define debug(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DEBUG
  #define VALUE(x)
  #define debug(...)
#endif
 
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)
 
inline string IntToString(LL a){
  char x[100];
  sprintf(x,"%lld",a); string s = x;
  return s;
}
 
inline LL StringToInt(string a){
  char x[100]; LL res;
  strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
  return res;
}
 
inline string GetString(void){
  char x[1000005];
  scanf("%s",x); string s = x;
  return s;
}
 
inline string uppercase(string s){
  int n = SIZE(s);
  REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}
 
inline string lowercase(string s){
  int n = SIZE(s);
  REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}
 
inline void OPEN (string s) {
  #ifndef TESTING
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
  #endif
}
 
//end of jonathanirvings' template v3.0.3 (BETA)
 
bool adj[1<<10][1<<10];
int dist[1<<10][1<<10];
int n = 6;
int conn = 0;
 
string bin(int x)
{
  string s = "";
  while (x > 0)
  {
    s = (char)(x % 2 + '0') + s;
    x /= 2;
  }
  while (SIZE(s) < n) s = '0' + s;
  return s;
}
 
// string bin(int x)
// {
//   return IntToString(x);
// }
 
bool dah[1<<10];
void dfs(int x)
{
  if (dah[x]) return;
  ++conn;
  dah[x] = 1;
  string s = bin(x);
  // bool gaprint = 0;
  bool gaprint = 0;
  // REP(i,SIZE(s)-1) if (s[i] == '1' && s[i+1] == '1') gaprint = 1;
  if (!gaprint) printf("%s ",s.c_str());
  REP(i,1<<n) if (adj[x][i]) dfs(i);
}
 
int grup(string s)
{
  vi v;
  FORD(i,SIZE(s)-1,0) if (s[i] == '1') v.pb(i + 1);
  while (SIZE(v) >= 2)
  {
    int i = v.back(); v.pop_back();
    int j = v.back(); v.pop_back();
    v.pb(j-i);
  }
  if (SIZE(v) == 0) return 0;
  return v[0];
}
 
int main()
{
  int T;
  scanf("%d",&T);
  TC(T)
  {
    int n;
    scanf("%d",&n);
    string s = GetString();
    string t = GetString();
    for (char a = '0'; a <= '1'; ++a)
    {
      for (char b = '0'; b <= '1'; ++b)
      {
        string ss = s + a;
        string tt = t + b;
        // VALUE(tt);
        if (grup(ss) == grup(tt))
        {
          // printf("%s %s\n",ss.c_str(),tt.c_str());
          puts("YES");
          goto ok;
        }
      }
    }
    puts("NO");
    ok:;
  }
  return 0;
  // REP(bit,1<<n) REP(bit2,1<<n) dist[bit][bit2] = INF;
  // REP(bit,1<<n) dist[bit][bit] = 0;
  // REP(bit,1<<n)
  // {
  //   // REP(i,n) if (bit & (1 << i))
  //   // FOR(i,0,n-1) if (bit & (1 << i))
  //   FOR(i,1,n-1) if (bit & (1 << i))
  //   {
  //     int bit2 = bit;
  //     if (i - 1 >= 0) bit2 ^= (1 << (i - 1));
  //     if (i + 1 < n) bit2 ^= (1 << (i + 1));
  //     adj[bit][bit2] = 1;
  //     dist[bit][bit2] = 1;
  //   }
  // }
  // REP(k,1<<n) REP(i,1<<n) REP(j,1<<n)
  // {
  //   adj[i][j] |= (adj[i][k] && adj[k][j]);
  //   MIN(dist[i][j],dist[i][k]+dist[k][j]);
  // }
  // REP(bit,1<<n)
  // {
  //   vector<int> pt(1<<n);
  //   vector<bool> dah(1<<n);
  //   queue<int> q;
  //   q.push(bit);
  //   dah[bit] = 1;
  //   pt[bit] = -1;
  //   while (!q.empty())
  //   {
  //     int now = q.front();
  //     q.pop();
  //     if (__builtin_popcount(now) <= 1)
  //     {
  //       while (now != -1)
  //       {
  //         printf("%s ",bin(now).c_str());
  //         now = pt[now];
  //       }
  //       puts("");
  //       break;
  //     }
  //     REP(bit2,1<<n) if (dist[now][bit2] == 1 && !dah[bit2])
  //     {
  //       dah[bit2] = 1;
  //       pt[bit2] = now;
  //       q.push(bit2);
  //     }
  //   }
  // }
  int res = 0;
  REP(i,1<<n) if (!dah[i])
  {
    conn = 0;
    dfs(i);
    printf("= %d\n",conn);
    // puts("");
    ++res;
  }
  // REP(i,1<<n)
  // {
  //   // printf("%4d:",i);
  //   printf("%s:",bin(i).c_str());
  //   // REP(j,1<<n) if (adj[i][j]) printf(" %d",j);
  //   REP(j,1<<n) if (adj[i][j]) printf(" %s",bin(j).c_str());
  //   puts("");
  // }
 
  return 0;
}