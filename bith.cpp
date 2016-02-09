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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int cnt(LL a) {
	return __builtin_popcountll(a);
}

int main(void)
{
	int n, i;
	cin >> n;
	while(n--) {
		LL a, b, ans = 0;
		cin >> a >> b;
		bool beda = 0;
		FORM(i, 63) {
			if(beda) ans |= (1LL << i);
			else if((a & (1LL << i)) != (b & (1LL << i))) {
				beda = 1;
			} else {
				ans |= ((1LL << i) & a);
			}
		}
		if(cnt(a) > cnt(ans)) ans = a;
		if(cnt(b) > cnt(ans)) ans = b;
		
		int ct = cnt(ans);
		ans = a;
		int rem = ct - cnt(ans);
		FORS(i, 63) {
			if(rem == 0) break;
			if(((1LL << i) & ans) == 0) {
				ans |= (1LL << i);
				rem--;
			}
		}
		pf("%I64d\n", ans);
	}
	
	return 0;
}
