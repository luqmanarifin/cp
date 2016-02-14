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
const int lim = 32000;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> prime;
bool is[lim + 5];
int ten[10];
vector<pair<int,int> > ans;

bool isPrime(int a) {
	//pf("%d\n", a);
	if(a <= lim) return !is[a];
	int i;
	FORS(i, prime.size()) {
		if(i*i > a) break;
		if(a % prime[i] == 0)
			return 0;
	}
	return 1;
}

int dig(int a) {
	int ret = 0;
	while(a) {
		ret++;
		a /= 10;
	}
	return ret;
}

int main(void)
{
	int i, j, a, b;
	ten[0] = 1;
	FOR(i, 1, 9) ten[i] = ten[i-1]*10;
	FOR(i, 2, lim) {
		if(!is[i]) {
			prime.push_back(i);
			for(j = i*i; j <= lim; j += i)
				is[j] = 1;
		}
	}
	sf("%d %d", &a, &b);
	FOR(i, a, b) FOR(j, a, b) {
		if(!is[i] && !is[j]) {
			//pf("%d %d haha\n", i, j);
			if(isPrime(i*ten[dig(j)] + j))
				ans.push_back(mp(i, j));
		}
	}
	if((int) ans.size()) {
		FORS(i, ans.size()) pf("%d %d\n", ans[i].first, ans[i].second);
	} else puts("TIDAK ADA");
	
	return 0;
}
