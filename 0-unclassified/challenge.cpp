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

const LL mod = 1073741824;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> cnt[105], prime;
bool is[105];
LL d[N];

int find(int a, int b) {
	int temp = 0;
	while(a % b == 0)
		temp++, a /= b;
	return temp;
}

int main(void)
{
	int a, b, c, i, j, aa, bb, cc;
	for(i = 2; i <= 100; i++) {
		if(!is[i]) {
			prime.push_back(i);
			for(j = i*i; j <= 100; j += i)
				is[j] = 1;
		}
	}
	FOR(i, 1, 100) cnt[i].resize(prime.size());
	FOR(i, 1, 100) {
		FORS(j, prime.size()) {
			if(prime[j] > i) break;
			cnt[i][j] = find(i, prime[j]);
		}
	}
	sf("%d %d %d", &a, &b, &c);
	LL res = 0;
	FOR(aa, 1, a) FOR(bb, 1, b) FOR(cc, 1, c) {
		int now = aa*bb*cc;
		LL cur = 1;
		if(!d[now]) {
			FORS(j, prime.size()) {
				int temp = cnt[aa][j] + cnt[bb][j] + cnt[cc][j];
				cur *= 1LL*(temp + 1);
				cur %= mod;
			}
			d[now] = cur;
		}
		res += d[now];
		if(res >= mod) res -= mod;
	}
	cout << res << endl;
	return 0;
}
