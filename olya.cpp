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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

#define fail { puts("0"); return 0; }
vector<int> cut;
LL dua[N];
int st[N];

int main(void)
{
	//open;
	int i, j, n, m, k;
	dua[0] = st[0] = 1;
	FOR(i, 1, N-1) {
		st[i] = 1;
		dua[i] = dua[i-1] << 1;
		dua[i] %= mod;
	}
	sf("%d %d %d", &n, &m, &k);
	while(m--) {
		int a, b;
		sf("%d %d", &a, &b);
		if(a + 1 == b) continue;
		cut.push_back(a);
		st[a]--;
		if(a + k + 1 == b) continue;
		fail;
	}
	k++;
	if(!cut.empty()) {
		if(cut[0] + k <= cut.back()) {
			fail;
		}
	}
	FOR(i, 1, N-1) st[i] += st[i-1];
	LL ans = 0;
	if(cut.empty()) {
		ans = 1;
		FOR(i, 1, n - k) {
			ans += dua[min(i - 1, k - 1)];
			if(ans >= mod) ans -= mod;
		}
	} else {
		FOR(i, max(1, cut.back() - k + 1), cut[0]) {
			ans += dua[st[min(n - k, i + k - 1)] - st[i]];
			if(ans >= mod) ans -= mod;
		}
	}
	cout << ans << endl;
	//close;
	return 0;
}
