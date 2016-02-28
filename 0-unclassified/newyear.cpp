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
const int N = 1e6 + 1e5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int buyut[N];
int deep[N];
int pol[5];

int ans() {
	vector<int> num;
	int i;
	FOR(i, 2, 4) num.push_back(pol[i]);
	sort(num.begin(), num.end());
	return num[2] + num[1];
}

int main(void)
{
	int q, i;
	FOR(i, 2, 4) {
		buyut[i] = i;
		deep[i] = 1;
		pol[i] = 1;
	}
	sf("%d", &q);
	int n = 4;
	FORS(i, q) {
		int v;
		sf("%d", &v);
		buyut[n+1] = buyut[n+2] = buyut[v];
		deep[n+1] = deep[n+2] = deep[v] + 1;
		pol[buyut[v]] = max(pol[buyut[v]], deep[n+1]);
		pf("%d\n", ans());
		n += 2;
	}
	
	return 0;
}
