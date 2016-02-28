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
const int N = 5e5 + 5;

int bit[N], n;

void add(int i) {
	for(; i <= n; i |= i + 1) bit[i]++;
}	

int find(int i) {
	int temp = 0;
	for(; i >= 0; i = (i & (i + 1)) - 1) temp += bit[i];
	return temp;
}

LL a[N];

int main(void)
{
	int i, j;
	sf("%d", &n);
	FOR(i, 1, n) {
		sf("%lld", &a[i]);
		a[i] += a[i - 1];
	}
	LL tot = a[n];
	FOR(i, 1, n) {
		if(a[i]*3 == tot) add(i);
	}
	//FOR(i, 1, n) cout << a[i] << ' ';
	LL ans = 0;
	FOR(i, 2, n - 1) {
		if(a[i]*3 == tot*2) ans += find(i - 1);
	}
	cout << ans << endl;
	return 0;
}
