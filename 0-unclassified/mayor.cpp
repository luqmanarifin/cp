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
const int N = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int m[N], r[N];
bool cover[N];
int link[N], sum, n;

int needPath(int now) {
	int i;
	if(1 <= now-1) {
		if(!cover[now-1] && m[now] + m[now-1] > r[now] + r[now-1]) {
			cover[now-1] = 1;
			if(link[now-1] == 0 || needPath(link[now-1])) {
				link[now-1] = now;
				return now-1;
			}
		}
	}
	if(now+1 <= n) {
		if(!cover[now+1] && m[now] + m[now+1] > r[now] + r[now+1]) {
			cover[now+1] = 1;
			if(link[now+1] == 0 || needPath(link[now+1])) {
				link[now+1] = now;
				return now+1;
			}
		}
	}
	return 0;
}

int main(void)
{
	int i, j;
	sf("%d", &n);
	int win = 0;
	FOR(i, 1, n) {
		sf("%d %d", &m[i], &r[i]);
		if(m[i] > r[i]) win++;
	}
	int cari = n - 2*win + 1;
	if(cari <= 0) cari = 0;
	FOR(i, 1, n) {
		if(sum == cari) break;
		if(m[i] > r[i]) continue;
		reset(cover, 0);
		int ret = needPath(i);
		if(ret) sum++;
	}
	if(sum < cari) {
		puts("-1");
		return 0;
	}
	pf("%d\n", cari);
	FOR(i, 1, n) if(link[i]) pf("%d %d\n", i, link[i]);
	
	return 0;
}
