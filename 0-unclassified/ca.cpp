/*-------------icalFikr's template v2.3--------------*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#ifndef GEDEBUG
	#define DEBUG   printf(__VA_ARGS__)
	#define DEBUGS  puts("gukguk")
	#define TIME()  printf("\nFinished in %.3lf s\n",clock()/(double)CLOCKS_PER_SEC)
#endif

#ifndef gc
    #ifdef __WIN32__
        #define gc getchar()
    #else
        #define gc getchar_unlocked()
    #endif
#endif

/* Abbreviations */
#define puf                 push_front
#define pof                 pop_front()
#define pub                 push_back
#define pob                 pop_back()
#define fs                  first
#define sc                  second
#define mp                  make_pair
#define FORINC(i,a,b,inc)   for(int i=int(a),_b=int(b);i<=_b;i+=inc)
#define FOR(i,a,b)          FORINC(i,a,b,1)
#define FORD(i,a,b)         FORINC(i,a,b,-1)
#define FORLL(i,a,b)        for(LL i=LL(a),_b=LL(b);i<=_b;i++)
#define FOREACH(i,a)        for (__typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define OPEN                freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define CLOSE               fclose(stdin); fclose(stdout);
#define ALL(v)              (v).begin(),(v).end()
#define sz                  size()
#define RESET(x,N)          memset(x,N,sizeof(x))
#define COPY(x,y)           memcpy(x,y,sizeof(x))
#define nl                  printf("\n")

using namespace std;
typedef double          db;
typedef long long       LL;
typedef pair <int,int>  ii;
typedef pair <LL,LL>    pll;
typedef vector <ii>     vii;
typedef vector <int>    vint;

const db EPS	= 0.0000001;
const db PI 	= acos(-1);
const LL INFLL	= 0x7FFFFFFFFFFFFFFF;
const int INF	= 0x7FFFFFFF;

template<typename T>
inline void next(T &num) {
    char c; num=0;
    do { c=gc; }
    while (c!=EOF && c==' ' && c=='\n' && c=='\t');
    int sign=(c=='-' ? -1 : 1);
    if (c!='-') num+=(c-'0');
    while ( (c=gc)!=EOF && c!='\n' && c!='\t' && c!=' ') {
        num*=10; num+=(c-'0');
    }
    num*=sign;
}
template<class T> T extractPQ ( priority_queue<T> pq ) { T res = pq.top(); pq.pop(); return res; }

/*-------------end of template-------------*/
const int MAX = 100000;

vector<LL> divs[MAX+3];
int cnt = 0;
bitset<MAX+3> udah;
map<LL, vector<LL> > faktor;

void solve(LL x, LL k) {
    if (cnt >= MAX) return;

    if (k == 0LL || x == 1LL) {
        printf("%I64d ",x);
        cnt++;
        return;
    }

    if (x > MAX) {
        vector<LL> tmp = faktor[x];
		  if(tmp.empty()) {
			  LL i;
			  for(i = 1; i*i < x; i++)
					if (x % i == 0) { tmp.pub(i); tmp.pub(x/i); }
			  if (i*i == x) tmp.pub(i);

			  sort(ALL(tmp));
			  faktor[x] = tmp;
		  }

        if (tmp.sz < 3) {
            while (k--) {
                printf("1 ");
                cnt++;
                if (cnt >= MAX) return;
            }
            printf("%I64d ",x);
            cnt++;
        } else {
            FOREACH(j,tmp) {
                solve(*j,k-1);
                if (cnt >= MAX) return;
            }
        }
    } else {
        if (!udah[x]) {
            LL i;
            for(i = 1; i*i < x; i++)
                if (x % i == 0) { divs[x].pub(i); divs[x].pub(x/i); }
            if (i*i == x) divs[x].pub(i);

            sort(ALL(divs[x]));

            udah[x] = 1;
        }

        if (divs[x].sz < 3) {
            while (k--) {
                printf("1 ");
                cnt++;
                if (cnt >= MAX) return;
            }
            printf("%I64d ",x);
            cnt++;
        } else {
            FOREACH(j,divs[x]) {
                solve(*j,k-1);
                if (cnt >= MAX) return;
            }
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","rt",stdin);
    #endif // ONLINE_JUDGE

    LL x, k;
    cin >> x >> k;

    solve(x,k);
    return 0;
}