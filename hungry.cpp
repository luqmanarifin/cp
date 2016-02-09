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
const int N = 1e7 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> ans;
bitset<N> is;

int main(void)
{
	int n, i;
	sf("%d", &n);
	FOR(i, 2, 1300000) {
		if(!is[i]) {
			ans.push_back(i);
			for(LL j = (LL) i*i; j < N; j += i) {
				is[j] = 1;
			}
		}
	}
	FORS(i, n) pf("%d ", ans[i]); nl;
	
	return 0;
}
