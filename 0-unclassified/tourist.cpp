#include <bits/stdc++.h>
#include <iomanip>

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
#define reset(cok,n) memset(cok, n, sizeof(cok))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const int maxn = 1e5+5;

LL gcd(LL a, LL b) { return b? gcd(b, a%b): a; }
LL lcm(LL a, LL b) { return a*b / gcd(a, b); }

LL ans = 0;
int num[maxn];

int main(void)
{
	int i, n; sf("%d", &n);
	FORS(i,n) sf("%d", &num[i]);
	sort(num, num + n);
	LL a = -2*n + 3;
	FORS(i,n) {
		ans += 1LL*a*num[i];
		a += 4;
	}
	LL N = 1LL * n;
	LL fpb = gcd(ans, N);
	ans /= fpb;
	N /= fpb;
	
	cout << ans << ' ' << N << endl;
	
	return 0;
}
