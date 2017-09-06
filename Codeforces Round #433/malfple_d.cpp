#include <iostream>
#include <iomanip>
#include <cstdio>

#include <cstring>
#include <string>
#include <sstream>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define mp make_pair

#define pb push_back
#define ff first
#define ss second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

#define getc getchar
template<typename T>
T getnum(){
	int sign = 1;
	T ret = 0;
	char c;

	do{
		c = getc();
	}while(c == ' ' || c == '\n');
	if(c == '-')sign = -1;
	else ret = c-'0';
	while(1){
		c = getc();
		if(c < '0' || c > '9')break;
		ret = 10*ret + c-'0';
	}
	return sign * ret;
}

inline void ini(int& x){
	x = getnum<int>();
}

inline void scani(int& x){
	scanf("%d",&x);
}

//end of macro

const int N = 3e5 + 5;

int n;
int arr[N];
int prefsum[N];

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    ini(n);
    REP(i,1,n)ini(arr[i]);
    REP(i,1,n)prefsum[i] = prefsum[i-1] + arr[i];

    int ans = 0;
    int sisa = 0;
    int lf = 1;
    while(lf <= n){
        int mn = max(0, prefsum[n]-prefsum[lf-1]-sisa);
        int id = lf-1;
        REP(i,lf,n){
            int s = prefsum[i] - prefsum[lf-1];
            int now = s + max(0, prefsum[n]-prefsum[i] - sisa - s/10);

            if(now < mn){
                mn = now;
                id = i;
            }
        }

        if(id == lf-1){
            ans += max(0, prefsum[n] - prefsum[lf-1] - sisa);
            break;
        }
        ans += prefsum[id]-prefsum[lf-1];
        sisa = max(0, sisa + (prefsum[id] - prefsum[lf-1])/10);
        lf = id+1;
        //printf("%d %d %d\n",lf,ans,sisa);
    }

    cout << ans << endl;

    return 0;
}