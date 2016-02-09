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
const int N = 2*5000*5000+10;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bitset<N> ans;
bool is[205];
vector<int> prime;

int main(void)
{
	int i, j, k;
	sf("%d", &k);
	int limit = 2*k*k;
	reset(is, 1);
	for(i = 2; i < 200; i++) {
		if(is[i]) {
			prime.push_back(i);
			for(j = i*i; j < 200; j += i)
				is[j] = 0;
		}
	}
	ans[1] = 1;
	int tot = 0;
	FORS(i, prime.size()) {
		int now = prime[i];
		FOR(j, 1, limit) {
			if(now*j > limit) break;
			if(ans[j]) {
				ans[now*j] = 1;
				tot++;
			}
		}
		if(tot >= k) break;
	}
	tot = 0;
	FORD(i, limit, 2) {
		if(tot == k) break;
		if(ans[i]) {
			pf("%d ", i);
			tot++;
		}
	}
	nl; return 0;
}
