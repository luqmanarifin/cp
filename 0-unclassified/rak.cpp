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

int dp[105];

#define sumnear(a) dp[prev[a]] + dp[next[a]]

int main(void)
{
	int t;
		char s[105];
		sf("%s", s);
		int i, n = strlen(s);
		reset(dp, 0);
		int now = (s[0] == '2');
		dp[now]++;
		FOR(i, 1, n-1) {
			if(s[i-1] != s[i])
				now++;
			dp[now]++;
		}
		if(now % 2 == 0) now++;
		int prev[105], next[105];
		FOR(i, 0, now) {
			prev[i] = i-1, next[i] = i+1;
			//pf("%d ", dp[i]);
		} //nl;
			
		int ans = 0;
		while(next[0] != now) {
			int pos = -1, l, r;
			//cout << next[0] << endl;
			for(i = next[0]; i < now; i = next[i]) {
				if(pos == -1 || dp[i] < dp[pos])
					pos = i;
				else if(dp[i] == dp[pos]) {
					if(sumnear(i) > sumnear(pos))
						pos = i;
				}
			}
			if(pos & 1) { // yg dipindah B
				dp[prev[pos]] += dp[next[pos]];
				l = prev[pos];
				r = next[next[pos]];
			} else { // yg dipindah A
				dp[next[pos]] += dp[prev[pos]];
				l = prev[prev[pos]];
				r = next[pos];
			}
			next[l] = r;
			prev[r] = l;
			ans += dp[pos];
		}
		
		int a = 0, b = 0;
		bool heu = 0;
		FORS(i, n) {
			if(s[i] == '2') {
				heu = 1;
				continue;
			}
			if(heu && s[i] == '1') a++;
		}
		heu = 0;
		FORM(i, n) {
			if(s[i] == '1') {
				heu = 1;
				continue;
			}
			if(heu && s[i] == '2') b++;
		}
		pf("%d\n", min(ans, min(a, b)));
	return 0;
}