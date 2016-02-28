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
const int N = 1e6;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool udah[N + 5], is[N + 5];
vector<int> prime;
int num[100005];

bool check(int a) {
	if(a == 1) return false;
	if(!is[a]) {
		if(udah[a]) return true;
		udah[a] = 1;
		return false;
	}
	int i;
	FORS(i, prime.size()) {
		if(1LL*prime[i]*prime[i] > a) return false;
		if(a % prime[i] == 0) {
			if(udah[prime[i]]) return true;
			udah[prime[i]] =1;
			while(a % prime[i] == 0) a /= prime[i];
			return check(a);
		}
	}
}

int main(void)
{
	int i, j, t;
	for(i = 2; i <= N; i++) {
		if(!is[i]) {
			prime.push_back(i);
			if(1LL*i*i <= N)
			for(j = i*i; j <= N; j += i)
				is[j] = 1;
		}
	}
	sf("%d", &t);
	while(t--) {
		reset(udah, 0);
		reset(num, 0);
		int n;
		sf("%d", &n);
		FORS(i, n) sf("%d", num + i);
		FORS(i, n) {
			if(check(num[i])) {
				puts("TIDAK");
				goto NEXT;
			}
		}
		puts("YA");
		NEXT:;
	}
	return 0;
}
