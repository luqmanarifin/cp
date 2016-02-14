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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

vector<int> a, b;

int main(void)
{
	int aa, bb;
	sf("%d %d", &aa, &bb);
	while(aa) {
		a.push_back(aa % 10);
		aa /= 10;
	}
	while(bb) {
		b.push_back(bb % 10);
		bb /= 10;
	}
	LL ans = 0, i, j;
	FORS(i, a.size())
		FORS(j, b.size())
			ans += a[i]*b[j];
	cout << ans << endl;
	return 0;
}
