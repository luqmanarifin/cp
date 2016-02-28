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
const LL inf = 4e18;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

LL a[50005];

int main(void)
{
	LL n, i;
	LL goal = 0;
	sf("%I64d", &n);
	FORS(i,n) {
		sf("%I64d", &a[i]);
		goal += a[i];
	}
	goal /= n;
	LL bef = 0, ans = 0;
	FORS(i,n-1) {
		a[i] += bef;
		ans += abs(goal - a[i]);
		bef = a[i] - goal;
	}
	cout << ans << endl;
	return 0;
}
