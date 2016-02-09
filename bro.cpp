#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int a[N], b[N];

int main(void)
{
	int n, m, i, j, mini = inf, maxi = 0;
	sf("%d %d", &n, &m);
	FORS(i,n) {
		sf("%d", a + i);
		if(a[i] < mini) mini = a[i];
	}
	FORS(i,m) {
		sf("%d", b + i);
		if(b[i] > maxi) maxi = b[i];
	}
	if(mini >= maxi) {
		puts("0");
		return 0;
	}
	sort(a, a + n);
	sort(b, b + m);
	reverse(b, b + m);
	LL ans = 0;
	FORS(i, min(n, m)) {
		if(a[i] >= b[i]) break;
		ans += 0LL + b[i] - a[i];
	}
	cout << ans << endl;
	return 0;
}
