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
const long long inf = 2e9;
const double eps = 1e-13;
const long long N = 20000 + 5;
const long long L = 100000 + 1;

long long gcd(long long a, long long b) { return b? gcd(b, a%b): a; }
long long lcm(long long a, long long b) { return a/ gcd(a, b)*b; }

long long ada[N];
bool is[L];
vector<long long> prime;

void add(long long a, long long b) {
	long long i, j, awal;
	FORS(i, prime.size()) {
		long long bag = 1;
		long long awal;
		FOR(j, 1, 20) {
			bag *= prime[i];
			if(bag > b || bag < 0) break;
			awal = a/bag;
			if(a % bag) awal++;
			awal *= bag;
			if(awal > b) continue;
			ada[i] += (b-awal)/bag + 1;
		}
	}
}

void subs(long long a, long long b) {
	long long i, j, awal;
	FORS(i, prime.size()) {
		long long bag = 1;
		long long awal;
		FOR(j, 1, 20) {
			bag *= prime[i];
			if(bag > b || bag < 0) break;
			awal = a/bag;
			if(a % bag) awal++;
			awal *= bag;
			if(awal > b) continue;
			ada[i] -= (b-awal)/bag + 1;
		}
	}
}

bool bisa(long long a) {
	long long i;
	FORS(i, prime.size()) {
		long long need = 0;
		while(a % prime[i] == 0) {
			need++;
			a /= prime[i];
		}
		if(ada[i] < need) return 0;
	}
	return 1;
}

int main(void)
{
	long long i;
	LL j;
	FOR(i, 2, L-1) {
		if(!is[i]) {
			prime.push_back(i);
			for(j = (LL)i*i; j < L; j += i)
				is[j] = 1;
		}
	}
	//cout << prime.back() << endl;
	long long a, b, c;
	sf("%lld %lld %lld", &a, &b, &c);
	add(b + 1, a + b);
	subs(1, a); 

	long long ans;
	FORD(ans, c, 2) {
		if(bisa(ans)) {
			cout << ans << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}
