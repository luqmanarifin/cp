#include <bits/stdc++.h>

/**
 * Codeforces Round #284 (Div. 2)
 * Problem : E
 * Luqman Arifin (kadalbonek)
 * بسم الله الرحمان الرحيم
 */

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
const int sz = 5000;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int ada[105][sz];
vector<int> prime;
bitset<mod> is;

void push(int a) {
	int i;
	FORS(i, prime.size()) {
		while(a % prime[i] == 0) {
			a /= prime[i];
		}
	}
	if(a > 1) {
		prime.push_back(a);
	}
}

int a[105];

int main(void)
{
	int i, n, m;
	LL j;
	for(i = 2; i*i < mod; i++) {
		if(!is[i]) {
			prime.push_back(i);
			for(j = (LL)i*i; j*j < mod; j += i) {
				is[j] = 1;
			}
		}
	}
	//cout << prime.back() << endl;
	sf("%d %d", &n, &m);
	FORS(i, n) {
		sf("%d", &a[i]);
		push(a[i]);
	}
	sort(prime.begin(), prime.end());
	prime.resize(distance(prime.begin(), unique(prime.begin(), prime.end())));
	int ans = 0;
	FORS(i, n) {
		FORS(j, prime.size()) {
			while(a[i] % prime[j] == 0) {
				a[i] /= prime[j];
				ada[i][j]++;
			}
		}
	}
	FORS(i, m) {
		int l, r;
		sf("%d %d", &l, &r);
		l--, r--;
		FORS(j, prime.size()) {
			int add = min(ada[l][j], ada[r][j]);
			ada[l][j] -= add;
			ada[r][j] -= add;
			ans += add;
		}
	}
	cout << ans << endl;
	return 0;
}
