#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 2e5 + 5;

bool is[N], kiwi[N], isprime[N];
vector<int> prime;

int main(void)
{
	int i; LL j;
	//puts("gukguk");
	FORS(i, N) isprime[i] = 1;
	for(i = 2; i*i <= 1000000000; i++) {
		if(isprime[i]) {
			prime.push_back(i);
			//pf("%d ", i);
			for(j = (LL) i*i; j*j <= 1000000000; j += i) isprime[j] = 0;
		}
	}
	int t;
	sf("%d", &t);
	while(t--) {
		reset(is, 0);
		reset(kiwi, 0);
		int a, b, ans = 0;
		sf("%d %d", &a, &b);
		FORS(i, prime.size()) {
			//pf("%d ", prime[i]);
			if(b < prime[i]) break;
			LL now = a / prime[i] * prime[i];
			//cout << now << endl;
			while(now <= b) {
				if(now < a) {
					now += prime[i];
					continue;
				}
				is[now - a] = 1;
				now += prime[i];
				//cout << now << endl;
			}
			now = 1;
			int power = 0;
			while(now < a) {
				power++;
				now *= prime[i];
				//cout << now << endl;
			}
			while(now <= b) {
				if(isprime[power + 1]) kiwi[now - a] = 1;
				power++;
				now *= prime[i];
				//cout << now << endl;
			}
		}
		FOR(i, a, b) {
			if(!is[i - a]) kiwi[i - a] = 1;
			ans += kiwi[i - a];
		}
		pf("%d\n", ans);
	}
	
	return 0;
}
