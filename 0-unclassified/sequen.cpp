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

const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5;
const int N5 = N + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

LL mod, n;
vector<int> num;
map<pair<int,int>, bool> ada;
LL fact[2*N5];

void masuk(int a, LL cur) {
	if(a & 1) {
		fact[a] += cur;
		return;
	}
	fact[2] += cur;
	masuk(a/2, cur);
}

LL power(LL a, LL b) {
	if(!b) return 1LL;
	LL temp = power(a, b/2);
	temp *= temp;
	temp %= mod;
	if(b & 1) {
		temp *= a;
		temp %= mod;
	}
	return temp;
}

int main(void)
{
	sf("%I64d", &n);
	int i, j, x, dobel = 0, bef = 0;

	FORS(i, n) {
		sf("%d", &x);
		num.push_back(x);
		if(!ada[mp(x, i)])
			ada[mp(x, i)] = 1;
		else
			dobel++;
	}
	FORS(i, n) {
		sf("%d", &x);
		num.push_back(x);
		if(!ada[mp(x, i)])
			ada[mp(x, i)] = 1;
		else
			dobel++;
	}
	sf("%I64d", &mod);
	sort(num.begin(), num.end());
	
	FOR(i, 1, 2*n-1)
		if(num[i] != num[i-1]) {
			fact[i-bef]++;
			bef = i;
		}
	fact[2*n-bef]++;
	
	FORD(i, 2*N, 1)
		fact[i] += fact[i+1];
	for(i = 2*N; i >= 4; i -= 2)
		if(fact[i]) {
			masuk(i, fact[i]);
			fact[i] = 0;
		}
	
	fact[2] -= dobel;
	LL ans = 1;
	FOR(i, 2, 2*N)
		if(fact[i]) {
			ans *= power(i, fact[i]);
			ans %= mod;
		}
	cout << ans << endl;
	return 0;
}
