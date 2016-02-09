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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int n, m, k, a[N], b[N];

bool descen(const int &lef, const int &rig) {
	return lef > rig;
}

int main(void)
{
	sf("%d %d %d", &n, &m, &k);
	int i;
	FORS(i,n) sf("%d", &a[i]);
	FORS(i,m) sf("%d", &b[i]);
	sort(a, a + n); reverse(a, a + n);
	sort(b, b + m); reverse(b, b + m);
	FORS(i, min(n, m))
		if(a[i] > b[i]) {
			puts("YES");
			return 0;
		}
	if(n > m) puts("YES");
	else puts("NO");
	return 0;
}
