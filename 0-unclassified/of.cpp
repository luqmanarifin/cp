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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int main(void)
{
	LL l, r, n;
	sf("%I64d", &n);
	l = 0, r = 1e6;
	while(l < r) {
		//pf("%I64d %I64d\n", l, r);
		LL mid = (l + r + 1) >> 1;
		if((3*mid*mid + mid)/2 <= n)
			l = mid;
		else
			r = mid - 1;
	}
	//pf("l = %I64d\n", l);
	LL ans = l/3;
	if(l % 3 == 2) {
		if(n % 3) ans++;
	} else if(l % 3 == 1) {
		if(n % 3 == 2) ans++;
	}
	cout << ans << endl;
	
	return 0;
}
