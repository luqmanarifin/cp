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
  #define debug(...) fprintf(stderr, VA_ARGS)
#else
  #define DEBUG
  #define VALUE(x)
  #define debug(...)
#endif

#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) (x))
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

int n,k;
bool dah[50];
vector<string> bisa[50];

int main()
{
  // scanf("%d %d",&n,&k);
  n = 12;
  FORD(bit,(1<<n)-1,0) if (__builtin_popcount(bit) == n / 2)
  {
    string s = "";
    FORD(i,n-1,0) if (bit & (1 << i)) s += ')';
    else s += '(';
    int sc = 0;
    int maxlen = 0;
    bool ok = 0;
    // if (s == "()()()()()()") ok = 1;
    // if (s == "(())()()()()") ok = 1;
    // if (s == "((()))()()()") ok = 1;
    // if (s == "(((())))()()") ok = 1;
    // if (s == "((((()))))()") ok = 1;
    // if (s == "(((((())))))") ok = 1;
    // if (!ok) continue;
    REP(i,n)
    {
      if (s[i] == '(') ++sc;
      else --sc;
      if (sc < 0) goto gabisa;
    }
    REP(bit2,1<<n)
    {
      string t = "";
      REP(i,n) if (bit2 & (1 << i)) t += s[i];
      string r = t;
      REVERSE(r);
      if (t == r) MAX(maxlen,SIZE(t));
    }
    // VALUE(s);
    // VALUE(maxlen);
    bisa[maxlen].pb(s);
    // if (!dah[maxlen])
    // {
    //   printf("%d %s\n",maxlen,s.c_str());
    //   dah[maxlen] = 1;
    // }
    gabisa:;
  }
  FORN(i,1,n)
  {
    printf(">>>>>>> k = %d\n",i);
    for (string s : bisa[i]) printf("%s\n",s.c_str());
  }
  return 0;
}