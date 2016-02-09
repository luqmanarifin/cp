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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int col[105][105], row[105][105], a[105][105];

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FORS(i, n) FORS(j, n) sf("%d", &a[i][j]);
	FORS(i, n) {
		int sum = 0;
		FORS(j, n)
			sum += a[i][j];
		FORS(j, n)
			row[i][j] = sum;
	}
	FORS(i, n) {
		int sum = 0;
		FORS(j, n)
			sum += a[j][i];
		FORS(j, n)
			col[j][i] = sum;
	}
	int ans = 0;
	FORS(i, n) FORS(j, n)
		if(col[i][j] > row[i][j])
			ans++;
	
	cout << ans << endl;
	return 0;
}
