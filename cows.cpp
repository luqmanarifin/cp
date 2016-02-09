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
const int N = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

bool a[N];
LL ans, cur, one, nol;

int main(void)
{
	int i, n;
	sf("%d", &n);
	FORS(i, n) {
		sf("%d", a + i);
		if(a[i]) one++;
		else nol++;
	}

	FORS(i, n) {
		if(a[i]) ans += nol;
		else nol--;
	}
	FORM(i, n) {
		if(a[i]) one--;
		else cur += one;
	}
	cout << min(ans, cur) << endl;
	return 0;
}
