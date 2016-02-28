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
const int N = 1e9 + 5;
const int sz = 20000;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL fact[sz], ifact[sz];
vector<int> prime;
vector<int> cur;
bitset<N> is;

LL power(LL a, LL b) {
	if(b == 0) return 1;
	LL temp = power(a, b/2);
	temp *= temp;
	temp %= mod;
	if(b & 1) {
		temp *= a;
		temp %= mod;
	}
	return temp;
}

LL inv(LL a) {
	return power(a, mod - 2);
}

LL c(LL n, LL k) {
	if(n < 0 || k < 0 || n < k) return 0;
	LL temp = fact[n] * ifact[k];
	temp %= mod;
	temp *= ifact[n-k];
	temp %= mod;
	return temp;
}

void insert(int a, int i) {
	if(i >= prime.size()) return;
	while(a % prime[i] == 0) {
		a /= prime[i];
		cur[i]++;
	}
	insert(a, i + 1);
}

void push(int a) {
	int i;
	FORS(i, prime.size()) {
		while(a % prime[i] == 0) a /= prime[i];
	}
	if(a > 1) prime.push_back(a);
}

int a[555];

int main(void)
{
	int n;
	LL i, j;
	fact[0] = ifact[0] = 1;
	FOR(i, 1, sz-1) {
		fact[i] = fact[i-1] * i;
		fact[i] %= mod;
		ifact[i] = inv(fact[i]);
	}
	prime.push_back(2);
	for(i = 2; i*i < N; i += (i == 2? 1 : 2)) {
		if(!is[i]) {
			prime.push_back(i);
			for(j = (LL) i*i; (LL) j*j < N; j += i) {
				is[j] = 1;
			}
		}
	}
	
	sf("%d", &n);
	FORS(i, n) {
		sf("%d", &a[i]);
		push(a[i]);
	}
	
	sort(prime.begin(), prime.end());
	prime.resize(distance(prime.begin(), unique(prime.begin(), prime.end())));	
	cur.resize(prime.size(), 0);
	FORS(i, n) insert(a[i], 0);
	
	LL ans = 1;
	FORS(i, prime.size()) {
		ans *= c(cur[i] + n - 1, cur[i]);
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
