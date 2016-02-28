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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int t[2005], h[2005], m[2005];
bool done[2005];

int main(void)
{
	int n, x, i, j;
	sf("%d %d", &n, &x);
	FORS(i, n) {
		sf("%d %d %d", &t[i], &h[i], &m[i]);
	}
	FORD(i, n-2, 0)
		FOR(j, 0, i)
			if(h[j] > h[j+1]) {
				swap(t[j], t[j+1]);
				swap(h[j], h[j+1]);
				swap(m[j], m[j+1]);
			}
	
	int now = x, ans1 = 0, udah = 0, type = 0;
	while(udah < n) {
		int cur = upper_bound(h, h + n, now) - h - 1;
		// cout << cur << ' '<< now << endl;
		int maks = 0, it;
		FORD(i, cur, 0)
			if(t[i] == type && !done[i]) {
				if(m[i] > maks) {
					maks = m[i];
					it = i;
				}
			}
		if(!maks) break;
		now += maks;
		done[it] = 1;
		udah++;
		ans1++;
		type ^= 1;
	}
	
	reset(done, 0);
	now = x, udah = 0, type = 1; int ans2 = 0;
	while(udah < n) {
		int cur = upper_bound(h, h + n, now) - h - 1;
		// cout << cur << endl;
		int maks = 0, it;
		FORD(i, cur, 0)
			if(t[i] == type && !done[i]) {
				if(m[i] > maks) {
					maks = m[i];
					it = i;
				}
			}
		if(!maks) break;
		now += maks;
		done[it] = 1;
		udah++;
		ans2++;
		type ^= 1;
	}
	
	cout << max(ans1, ans2) << endl;
	// FORS(i, n) pf("%d %d %d\n", t[i], h[i], m[i]);
	return 0;
}
