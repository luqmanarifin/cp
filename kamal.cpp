#include <bits/stdc++.h>

/** 
 * Bayan 2015 Contest Warm Up
 * Problem : C
 * بسم الله الرحمان الرحيم
 */

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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int dp[1005][1005];
char s[1005][1005];

inline int take(int i, int j, int ii, int jj) {
	return dp[ii][jj] - dp[ii][j-1] - dp[i-1][jj] + dp[i-1][j-1];
}

int main(void)
{
	int i, j, n, m;
	pair<int,int> st = mp(inf,inf), fn = mp(-1, -1);
	sf("%d %d", &n, &m);
	FOR(i, 1, n) sf("%s", &s[i][1]);
	int ans = inf, tot = 0;
	FOR(i, 1, n) FOR(j, 1, m) {
		dp[i][j] = (s[i][j] == 'X');
		dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		if(s[i][j] == 'X') {
			st = min(st, mp(i, j));
			fn = max(fn, mp(i, j));
			tot++;
		}
	}
	int lefi = st.first, lefj = st.second;
	int rigi = fn.first, rigj = fn.second;
	int row = inf, col = inf;
	FOR(j, 1, m) {
		bool udah = 0;
		int temp = 0;
		FOR(i, 1, n) {
			if(s[i][j] != 'X' && s[i-1][j] == 'X')
				break;
			temp += (s[i][j] == 'X');
		}
		if(temp == 0) continue;
		row = min(row, temp);
	}
	FOR(i, 1, n) {
		bool udah = 0;
		int temp = 0;
		FOR(j, 1, m) {
			if(s[i][j] != 'X' && s[i][j-1] == 'X')
				break;
			temp += (s[i][j] == 'X');
		}
		if(temp == 0) continue;
		col = min(col, temp);
	}
	int asi, asj;
	//pf("%d %d\n", row, col);
	FOR(asi, 1, row) FOR(asj, 1, col) {
		int i = lefi + asi - 1;
		int j = lefj + asj - 1;
		bool valid = 1;
		int token = 0;
		//pf("panjang %d %d : \n", asi, asj);
		while(!(i == rigi && j == rigj)) {
			int remrig = take(i - asi + 1, j + 1, i, j + 1);
			int remdow = take(i + 1, j - asj + 1, i + 1, j);
			//pf("%d %d %d %d\n", i, j, remrig, remdow);
			if(remrig == asi) {
				if(remdow == asj) {
					valid = 0;
					break;
				}
				token += asi;
				j++;
			} else if(remdow == asj) {
				if(remrig == asi) {
					valid = 0;
					break;
				}
				token += asj;
				i++;
			} else {
				valid = 0;
				break;
			}
		}
		//nl;
		token += asi*asj;
		if(valid && token == tot) {
			//pf("token %d %d\n", token, tot);
			ans = min(ans, asi*asj);
		}
	}
	cout << (ans == inf? -1 : ans) << endl;
	return 0;
}
