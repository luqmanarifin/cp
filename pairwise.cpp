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
const double eps = 1e-13;
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int ans[N];
bool is[N];

int main(void)
{
	int t, tt, i, j, n;
	ans[1] = 1;
	FOR(i, 2, N-1) {
		ans[i] = ans[i - 1];
		if(!is[i]) {
			ans[i]++;
			if(1LL*i*i < N)
			for(j = i*i; j < N; j += i)
				is[j] = 1;
		}
	}
	sf("%d", &t);
	FOR(tt, 1, t) {
		sf("%d", &i);
		pf("Case #%d: %d\n", tt, ans[i]);
	}
	
	return 0;
}
