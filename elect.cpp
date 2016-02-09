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
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int dp[15][15][2], c[15], f[15], d[15], a[15];
LL ans;

/*
	dp[digit max][banyak lucky number][state]
	state 1 : bilangan itu sendiri, diambil sekian digit awal m
	state 0 : bilangan < m
	d[i] menyimpan bilangan m dalam array
	c[i] menyimpan banyak integer <= m dengan i lucky number
	f[i] menyimpan berapa kali bilangan dgn i lucky number dipake di tiap permut
	a[i] menyimpan berapa banyak pilihan angka buat partai ke i
*/

int lucky(int x) {
	// balikin berapa banyak lucky number < x
	if(x <= 4) return 0;
	if(x <= 7) return 1;
	return 2;
}

int non(int x) {
	// balikin berapa banyak non lucky number < x
	return x - lucky(x);
}

void solve(int num, int sum) {
	int i, j;
	if(num == 6) {
		a[num] = c[sum] - f[sum];
		LL cur = 1LL;
		FORS(i, 7) cur *= a[i], cur %= mod;
		ans += cur;
		if(ans >= mod) ans -= mod;
	} else {
		FOR(i, 0, sum) {
			a[num] = c[i] - f[i];
			f[i]++;
			solve(num + 1, sum - i);
			f[i]--;
		}
	}
}

int main(void)
{
	char m[15];
	sf("%s", m);
	int n = strlen(m), i, j, k;
	FORS(i, n) d[i] = m[i] - '0';
	dp[1][0][0] = non(d[0]);
	dp[1][1][0] = lucky(d[0]);
	dp[1][1][1] = (d[0] == 4 || d[0] == 7);
	dp[1][0][1] = !dp[1][1][1];
	
	int cnt = dp[1][1][1];
	FOR(i, 1, n-1) {
		if(d[i] == 4 || d[i] == 7) cnt++;
		dp[i+1][cnt][1] = 1;
	}
	FOR(i, 2, n) FOR(j, 0, i) {
		dp[i][j][0] += dp[i-1][j][0]*8 + dp[i-1][j][1]*non(d[i-1]);
		if(j) dp[i][j][0] += dp[i-1][j-1][0]*2 + dp[i-1][j-1][1]*lucky(d[i-1]);
	}
	int sum = 0;
	FOR(i, 0, n) c[i] = dp[n][i][0] + dp[n][i][1], sum += c[i];
	c[0]--; // 0 is excluded
	// cout << sum << endl;
	
	FOR(i, 1, n) {
		a[0] = c[i];
		FOR(j, 0, i - 1) {
			reset(f, 0);
			f[i]++;
			solve(1, j);
		}
	}
	cout << ans << endl;
	return 0;
}
