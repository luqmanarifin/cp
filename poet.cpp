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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char fn[11], ln[11];
char fm[11], lm[11];
int dp[1 << 9][1 << 9][26];
int n, m;

int find(int nask, int mask, int st, char c) {
	int i;
	if(dp[nask][mask][c] != -1) return dp[nask][mask][c];
	int ans = 1;
	if(st) {
		FORS(i, m) {
			if((1 << i) & mask) continue;
			if(c == fm[i])
				ans = min(ans, find(nask, mask | (1 << i), st ^ 1, lm[i]));
		}
	} else {
		FORS(i, n) {
			if((1 << i) & nask) continue;
			if(c == fn[i])
				ans = min(ans, find(nask | (1 << i), mask, st ^ 1, ln[i]));
		}
	}
	return dp[nask][mask][c] = ans ^ 1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	int i, j, t, tt;
	cin >> t;
	cin.ignore();
	FOR(tt, 1, t) {
		reset(dp, -1);
		cin >> n;
		cin.ignore();
		string temp;
		FORS(i, n) {
			getline(cin, temp);
			int len = temp.length();
			fn[i] = temp[0];
			ln[i] = temp[len-1];
		}
		
		cin >> m;
		cin.ignore();
		FORS(i, m) {
			getline(cin, temp);
			int len = temp.length();
			fm[i] = temp[0];
			lm[i] = temp[len-1];
		}
		
		int ans = 1;
		FORS(i, n) {
			ans = min(ans, find((1 << i), 0, 1, ln[i]));
		}
		pf("Game %d: ", tt);
		pf(ans? "player2" : "player1"); nl;
	}
	
	return 0;
}
