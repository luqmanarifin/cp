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
char pos[26];
int n;

int main() {
	FOR(i,0,25) pos[i]=(char)('a'+i);
	
	next(n);
	while (n) {
		FOR(i,0,25) { 
			putc(pos[i],stdout); 
			n--;
			if (!n) break;
		}
		next_permutation(pos,pos+26);
	}
}