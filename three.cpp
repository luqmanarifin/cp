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

const int mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 3e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

inline string get() {
	char f[N];
	sf("%s", f);
	return (string) f;
}

vector<string> s[3][N];
string st[5];
int len[5], ans[N];

int main(void)
{
	int i, j, pos, n = inf;
	FORS(i, 3) {
		st[i] = get();
		len[i] = st[i].length();
		if(len[i] < n) n = len[i];
	}
	FORS(i, 3) {
		FOR(j, 1, n) {
			FORS(pos, len[i]) {
				if(pos + j > len[i]) break;
				s[i][j].push_back(st[i].substr(pos, j));
				//cout << st[i].substr(pos, j) << ' ' << i << endl;
			}
		}
	}
	FOR(i, 1, n) {
		int a, b, c;
		FORS(a, s[0][i].size())
			FORS(b, s[1][i].size())
				FORS(c, s[2][i].size()) {
					if(s[0][i][a] == s[1][i][b] && s[1][i][b] == s[2][i][c])
						ans[i]++;
					if(ans[i] == mod) ans[i] -= mod;
				}
	}
	FOR(i, 1, n) pf("%d ", ans[i]); nl;
	return 0;
}
