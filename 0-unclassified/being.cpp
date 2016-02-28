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
const int N = 3005 * 3005;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> adj[3005];
int ada[3005], back[3005];
bitset<N> have;

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	while(m--) {
		int a, b;
		sf("%d %d", &a, &b);
		FORS(i, adj[b].size()) {
			ada[adj[b][i]]++;
		}
		ada[b] += back[a];
		if(have[b * (n + 1) + a]) {
			ada[b]--;
			ada[a]--;
		} 
		have[a * (n + 1) + b] = 1;
		adj[a].push_back(b);
		back[b]++;
	}
	int ans = 0;
	FOR(i, 1, n) {
		ans += ada[i]/2;
		//pf("%d %d\n", ada[i], back[i]);
	}
	cout << ans << endl;
	return 0;
}
