#include <bits/stdc++.h>
#include <time.h>  

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
#define open freopen("pagar.in","r",stdin); freopen("out1.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL a[1005], len, n;

bool valid(LL t) {
	LL i;
	vector<pair<LL,LL> > seg;
	seg.clear();
	FORS(i, n) {
		seg.push_back( mp(a[i] - t, a[i] + t/2) );
	}
	pair<LL,LL> now, bef = mp(0, 0);
	int it = 0;
	bool ret = 1;
	while(it < seg.size()) {
		now = seg[it];
		if(bef.second + 1 < now.first) {
			ret = 0;
			break;
		}
		bef = now;
		it++;
	}
	if(bef.second < len) ret = 0;
	return ret; 
}

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		LL i;
		reset(a, 0);
		sf("%lld %lld", &len, &n);
		FORS(i, n) sf("%lld", a + i);
		LL l = 0, r = 2*len;
		while(l < r) {
			LL mid = (l + r) >> 1;
			if(valid(mid)) r = mid;
			else l = mid + 1;
		}
		pf("%d", (int) l);
		if(t) pf(" ");
		else puts("");
	}
	return 0;
}
