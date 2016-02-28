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
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int dp[10005][26];

int main(void)
{
	char a[10005], s[1000005];
	sf("%s %s", a, s);
	int j, aa = strlen(a), ss = strlen(s), i;
	FORS(i, 26) dp[aa][i] = inf;
	
	FORM(i, aa)
		FORS(j, 26)
			if(a[i]-'a' == j) dp[i][j] = i;
			else dp[i][j] = dp[i+1][j];
	
	int ans = 1, now = 0;
	FORS(i, ss) {
		if(dp[now][s[i]-'a'] == inf) {
			now = 0; ans++;
			if(dp[now][s[i]-'a'] == inf) {
				puts("-1");
				return 0;
			}
		}
		now = dp[now][s[i]-'a'] + 1;
	}
	
	cout << ans << endl;
	return 0;
}
