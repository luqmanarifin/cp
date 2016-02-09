/*-------------icalFikr's template v2.3--------------*/
/*----- http://beat.inkubatorit.com/icftemplate -----*/

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
#define FOR(i,a,b)          for(int i=int(a),_b=int(b);i<=_b;++i)
#define FORD(i,a,b)         for(int i=int(a),_b=int(b);i>=_b;--i)
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

/*-------------end of template-------------*/
struct edge {
    public :
    int u, v, w;
};

int n, m, last[300003], res[300003];
edge ed[300003];

bool operator < (const edge& a, const edge& b) {
    return (a.w < b.w);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    FOR(i,0,m-1)
    cin >> ed[i].u >> ed[i].v >> ed[i].w;

    sort(ed, ed+m);
	 int bef = -1;
	 vector<pair<int,int> > que;
    FOR(i,0,m-1) {
        edge cur = ed[i];
		  if(cur.w != bef) {
				FOR(j, 0, que.size()-1)
					if(que[j].second > res[que[j].first]) {
						res[que[j].first] = que[j].second;
						last[que[j].first] = bef;
					}
				que.clear();
		  }
		  bef = cur.w;
       if (last[cur.u] < cur.w && res[cur.v] <= res[cur.u]) {
				que.push_back(mp(cur.v, res[cur.u] + 1));
        }
    }
				FOR(j, 0, que.size()-1)
					if(que[j].second > res[que[j].first]) {
						res[que[j].first] = que[j].second;
						last[que[j].first] = bef;
					}

    int ans = 0;
    FOR(i,1,n) ans = max(ans, res[i]);
    cout << ans;
}