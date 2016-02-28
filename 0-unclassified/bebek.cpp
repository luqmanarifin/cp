#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int n;
char s[N];
pair<int,int> m[N], k[N], b[N];
int mm, kk, bb;

#define val(p) 1LL*(p.second - p.first)

int main(void)
{
	int i;
	sf("%d %s", &n, s);
	m[0].first = -1;
	k[0].first = -1;
	b[0].first = -1;
	// first  = tempat sebelumnya
	// second = tempat asli
	FORS(i, n) {
		if(s[i] == 'M') {
			m[mm].second = m[mm+1].first = i;
			mm++;
		}
		if(s[i] == 'K') {
			k[kk].second = k[kk+1].first = i;
			kk++;
		}
		if(s[i] == 'B') {
			b[bb].second = b[bb+1].first = i;
			bb++;
		}
	}
	m[mm].second = n; if(mm) m[mm].first = m[mm-1].second;
	k[kk].second = n;	if(kk) k[kk].first = k[kk-1].second;
	b[bb].second = n; if(bb) b[bb].first = b[bb-1].second;
	int q;
	sf("%d", &q);
	
	while(q--) {
		int num; char c;
		cin >> c >> num;
		LL ans = 0;
		if(c == 'M') {
			if(num)
				FOR(i, 0, mm - num)
					ans += val(m[i])*val(m[i+num]);
			else
				FOR(i, 0, mm)
					ans += val(m[i])*(val(m[i])-1)/2;
		} else if(c == 'K') {
			if(num)
				FOR(i, 0, kk - num)
					ans += val(k[i])*val(k[i+num]);
			else
				FOR(i, 0, kk)
					ans += val(k[i])*(val(k[i])-1)/2;
		} else if(c == 'B') {
			if(num)
				FOR(i, 0, bb - num)
					ans += val(b[i])*val(b[i+num]);
			else
				FOR(i, 0, bb)
					ans += val(b[i])*(val(b[i])-1)/2;
		}
		pf("%I64d\n", ans);
	}
	//FOR(i, 0, kk) pf("%d %d\n", k[i].first, k[i].second);
	return 0;
}
