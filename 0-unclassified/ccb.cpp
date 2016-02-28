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
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int cnt[N], tt;
bool is[N];
vector<int> prime;

void fact(int a) {
	if(a == 1) return;
	for(; tt < prime.size(); tt++) {
		if(!is[a]) {
			cnt[a] = max(cnt[a], 1);
			return;
		}
		if(1LL*prime[tt]*prime[tt] > a)
			break;
		int cur = 0;
		while(a % prime[tt] == 0) {
			cur++;
			a /= prime[tt];
		}
		cnt[prime[tt]] = max(cnt[prime[tt]], cur);
	}
}

int main(void)
{
	int t, i, j;
	for(i = 2; i < N; i++) {
		if(!is[i]) {
			prime.push_back(i);
			if(1LL*i*i < N)
			for(j = 1LL*i*i; j < N; j += i)
				is[j] = 1;
		}
	}
	sf("%d", &t);
	while(t--) {
		reset(cnt, 0);
		int n, a;
		sf("%d", &n);
		FORS(i, n) {
			sf("%d", &a);
			tt = 0;
			fact(a);
		}
		LL ans = 0;
		FORS(i, prime.size())
			ans += cnt[prime[i]];
		pf("%lld\n", ans);
	}
	
	return 0;
}
