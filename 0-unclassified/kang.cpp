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
const int N = 5e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

bool done[N];

int main(void)
{
	int n, a[N], i;
	sf("%d", &n);
	FORS(i, n) sf("%d", a + i);
	sort(a, a + n);
	int j = 0, ans = n; i = 0;
	while(j < n && i < n) {
		j = lower_bound(a, a + n, 2*a[i]) - a;
		while(done[j] && j < n) j++;
		if(a[i]*2 <= a[j]) {
			ans--;
			done[j] = 1;
		}
		i++;
	}
	cout << ans << endl;
	return 0;
}
