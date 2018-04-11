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
const int N = 6e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int ans, a[N];

int main(void)
{
	ios_base::sync_with_stdio(false);
	int i = 0, x;
	while(cin >> x) {
		if(!i || x != a[i - 1]) {
			a[i] = x;
			i++;
		}
	}
	int n = i, top = -1, down = -1;
	if(a[0] < a[1]) down = a[0];
	else top = a[0];
	FOR(i, 1, n-1) {
		if(a[i-1] < a[i] && a[i] > a[i+1])
			top = a[i];
		else if(a[i-1] > a[i] && (a[i] < a[i+1] || i == n - 1))
			down = a[i];
		if(top - down > ans && top != -1 && down != -1)
			ans = top - down;
	}
	cout << ans << endl;
	return 0;
}
