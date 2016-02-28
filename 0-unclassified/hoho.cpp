/*-------------icalFikr's template v2.1--------------*/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <cstddef>
#include <cassert>
#include <cctype>
#include <utility>
#include <ctime>

#ifdef __WIN32__
	char getchar_unlocked() { return getchar(); }
#endif

/* Abbreviations */
#define puf push_front
#define pof pop_front()
#define pub push_back
#define pob pop_back()
#define fs first
#define sc second
#define mp make_pair
#define FOR(i,a,b) for(int i=int(a),_b=int(b);i<=_b;i++)
#define FORINC(i,a,b,inc) for(int i=int(a),_b=int(b);i<=_b;i+=inc)
#define FORLL(i,a,b) for(LL i=LL(a),_b=LL(b);i<=_b;i++)
#define FORD(i,a,b) for(int i=int(a),_b=int(b);i>=_b;i--)
#define FOREACH(i,a) for (__typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define OPEN freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define CLOSE fclose(stdin); fclose(stdout);
#define ALL(v) (v).begin(),(v).end()
#define sz size()
#define reset(x,N) memset(x,N,sizeof(x))
#define nl puts("")
#define gc getchar_unlocked()

using namespace std;
typedef double db;
typedef long long LL;
typedef pair <int,int> ii;
typedef pair <LL,LL> pll;
typedef vector <ii> vii;
typedef vector <int> vint;

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

inline string getstr() {
    string str; char k;
    while( (k=gc)==' ' || k=='\n' ) {
        k=gc;
        if ( k==' ' || k=='\n' ) continue;
        else break;
    }
	str.pub(k);
    while((k=gc)!=EOF &&k!='\n' && k!='\t'
        && k!='\v' && k!='\0' && k!=' ')
        str.pub(k);
    return str;
}

/*-------------end of template-------------*/
int cl[1000005][26];
char s1[10005],s2[1000005];

int main() {
	gets(s1); gets(s2);
	int n = strlen(s1), m = strlen(s2);
	
	//precalc closest character
	reset(cl,-1);
	FOR(i,0,25) {
		FORD(j,n-1,0)
		if (s1[j] == 'a'+i)
			cl[j][i]=j;
		else
			cl[j][i]=cl[j+1][i];
			
		if (cl[n-1][i] == -1) {
			cl[n-1][i] = cl[0][i];
			
			FORD(j,n-1,0)
			if (cl[j][i] == -1) cl[j][i] = cl[j+1][i];
		}
		
		cl[n][i] = cl[0][i];
	}
	
	//solve
	int ans = 1, last = 0;
	FOR(i,0,m-1) {
		if (cl[last][s2[i]-'a'] == -1) { puts("-1"); return 0; }
		
		ans += (cl[last][s2[i]-'a'] < last);
		last = cl[last][s2[i]-'a'] + 1;
	}
	cout <<ans;
	return 0;
}