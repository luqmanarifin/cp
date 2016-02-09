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
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool done[100];
int pil[100], lim;
vector<int> need[100];

int main(void)
{
	int t, i, j, k;
	sf("%d", &t);
	while(t--) {
		int n, p;
		reset(done, 0);
		reset(pil, 0);
		FORS(i, 100) need[i].clear();
		sf("%d %d", &n, &p);
		FOR(i, 1, n) {
			sf("%d", pil + i);
			FORS(j, pil[i]) {
				int x;
				sf("%d", &x);
				need[x].push_back(i);
			}
		}
		int ans = 0;
		FOR(i, 1, p) {
			sf("%d", &lim);
			vector<pair<int,int> > will;
			will.clear();
			FORS(j, need[i].size()) {
				int num = need[i][j];
				pil[num]--;
				if(!done[num])
					will.push_back(mp(pil[num], num));
			}
			if(will.size()) sort(will.begin(), will.end());
			FORS(j, will.size()) {
				if(j == lim) break;
				ans++;
				done[will[j].second] = 1;
			}
		}
		pf("%d\n", ans);
	}
	return 0;
}
