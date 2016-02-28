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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL dp[N][3];
int odd[N], even[N];
/*
	dp[posisinya] [status]
	status : 
	0	belum masuk ke bagian permainan
	1	lagi di tengah permainan
	2	permainan udah selesai, dia di luar fragile
*/
int main(void)
{
	int n, i, j, x;
	sf("%d", &n);
	FOR(i, 1, n - 1) {
		sf("%d", &x);
		if(x & 1) odd[i] = x, even[i] = x - 1;
		else odd[i] = x - 1, even[i] = x;
	}
	LL ans = 0;
	FOR(i, 2, n) {
		dp[i][0] = dp[i-1][0] + even[i-1];
		dp[i][1] = odd[i-1] + max(dp[i-1][0], dp[i-1][1]);
		dp[i][2] = even[i-1] + max(dp[i-1][1], dp[i-1][2]);
		if(!even[i-1]) {
			dp[i][0] = 0;
			dp[i][2] = 0;
		}
		FORS(j, 3) if(ans < dp[i][j]) ans = dp[i][j];
	}
	cout << ans << endl;
	return 0;
}
