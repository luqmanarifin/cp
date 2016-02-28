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
const int N = 5e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int ne[N], pr[N], a[N];
queue<int> q;
bool done[N];

void check(int i) {
	if(done[i]) return;
	if(a[pr[i]] >= a[i] && a[i] <= a[ne[i]]) {
		q.push(i);
		done[i] = 1;
	}
}

int main(void)
{
	int n, i;
	sf("%d", &n);
	FOR(i, 1, n) {
		sf("%d", &a[i]);
		pr[i] = i - 1;
		ne[i] = i + 1;
	}
	ne[0] = 1;
	pr[n + 1] = n;
	FOR(i, 1, n) check(i);
	LL ans = 0;
	while(q.size()) {
		int now = q.front();
		q.pop();
		int next = ne[now];
		int prev = pr[now];
		ne[prev] = next;
		pr[next] = prev;
		ans += min(a[next], a[prev]);
		check(next);
		check(prev);
	}
	int now = ne[0];
	while(now <= n) {
		ans += min(a[pr[now]], a[ne[now]]);
		now = ne[now];
	}
	cout << ans << endl;
	return 0;
}
