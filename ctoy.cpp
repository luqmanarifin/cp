#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair
#define X har
#define Y init

const LL mod = 1e9 + 7;
const LL inf = 4e18;
const int N = 1005;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int n, m, pos[N];
LL cost[N];
LL ans = 0;
vector<int> near[N];
bool done[N];

int main(void)
{
	int i, j;
	sf("%d %d", &n, &m);
	FOR(i,1,n) {
		sf("%d", &pos[i]);
	}
	while(m--) {
		int a, b;
		sf("%d %d", &a, &b);
		cost[a] += pos[b];
		cost[b] += pos[a];
		near[a].push_back(b);
		near[b].push_back(a);
	}
	FOR(j,1,n) {
		LL cur = inf; int curi;
		FOR(i,1,n)
			if(!done[i] && (cost[i] < cur || (cost[i] == cur && pos[i] > pos[curi]))) {
				cur = cost[i];
				curi = i;
			}
		FORS(i, near[curi].size()) {
			int adj = near[curi][i];
			cost[adj] -= pos[curi];
		}
		cout << curi <<' ';
		ans += cur;
		done[curi] = 1;
	}

	cout << ans << endl;
	return 0;
}
