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

struct item {
	item(LL _val, int _upd, int _stat) : val(_val), upd(_upd), stat(_stat) {};
	LL val; int upd, stat;
};

bool operator < (const item &a, const item &b){
	return a.val < b.val ||
		(a.val == b.val && a.upd < b.upd) ||
		(a.val == b.val && a.upd == b.upd && a.stat < b.stat);
} 

priority_queue<item> pq;
LL ans, row[1005], col[1005];
int cnt[2];

int main(void)
{
	int n, m, k, p, i, j, x;
	sf("%d %d %d %d", &n, &m, &k, &p);
	FORS(i, n) FORS(j, m) {
		sf("%d", &x);
		row[i] += x;
		col[j] += x;
	}
	if(n > m) {
		FORS(i, n) pq.push(item(row[i], 0, 1));
		FORS(i, m) pq.push(item(col[i], 0, 0));
	} else {
		FORS(i, n) pq.push(item(row[i], 0, 0));
		FORS(i, m) pq.push(item(col[i], 0, 1));
		swap(n, m);
	}
	// asumsi bahwa n > m jadi ngambil row selalu untung
	
	while(k--) {
		item now = pq.top();
		while(now.upd != cnt[now.stat]) {
			pq.pop();
			pq.push( item(now.val - p*(cnt[now.stat] - now.upd), cnt[now.stat], now.stat) );
			now = pq.top();
		}
		cnt[1 - now.stat]++;
		pq.pop();
		pq.push( item(now.val - p*(now.stat? m : n), now.upd, now.stat) );
		ans += now.val;
	}
	cout << ans << endl;
	return 0;
}
