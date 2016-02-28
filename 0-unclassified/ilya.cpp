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
#define reset(cok,n) memset(cok, n, sizeof(cok))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9+7;
const int maxn = 2e6+5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

bool des(const int &lef, const int &rig) {
	return lef > rig;
}

int k, a[maxn], i, j;

int main(void)
{
	sf("%d", &k);
	long double N = (long double)log(k)/log(4) + 1;
	int n = trunc(N);
	FOR(i,1,k) sf("%d", a + i);
	sort(a+1, a+1+k, des);
	
	int t = 0; LL ans = 0;
	FOR(i,1,k) {
		if(i > pow(4,t)) { t++; n--; }
		ans += 1LL*n*a[i];
	}
	
	cout << ans << endl;
	
	return 0;
}