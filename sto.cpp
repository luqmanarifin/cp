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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int x[N], h[N], m[N];

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int i, j, n, ans = 0;
		priority_queue<pair<int,int> > pq;
		sf("%d", &n);
		FORS(i, n) sf("%d %d %d", &x[i], &h[i], &m[i]);
		FORM(i, n) {
			pq.push(mp(h[i], m[i]));
			while(!pq.empty() && x[i]) {
				int now = pq.top().second;
				int price = pq.top().first;
				int sell = min(x[i], now);
				pq.pop();
				ans += sell * price;
				int sisa = now - sell;
				if(sisa) pq.push(mp(price, sisa));
				x[i] -= sell;
			}
		}
		pf("%d\n", ans);
	}
	
	return 0;
}
