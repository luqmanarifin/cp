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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> edge[3005];
int cnt[3005];

int main(void)
{
	//open;
	int i, j, k, n, m;
	sf("%d %d", &n, &m);
	while(m--) {
		int a, b;
		sf("%d %d", &a, &b);
		edge[a].push_back(b);
	}
	int ans = 0;
	FOR(i, 1, n) {
		reset(cnt, 0);
		FORS(j, edge[i].size()) {
			int near = edge[i][j];
			FORS(k, edge[near].size()) {
				int next = edge[near][k];
				cnt[next]++;
			}
		}
		FOR(j, 1, n) if(i != j) {
			ans += cnt[j] * (cnt[j] - 1) / 2;
		}
	}
	cout << ans << endl;
	
	//close;
	return 0;
}
