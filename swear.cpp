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

int dic[1005][30];
int wor[1005][30];

bool same(int d, int w) {
	int h;
	FOR(h, 0, 27) {
		if(dic[d][h] != wor[w][h])
			return 0;
	}
	return 1;
}

int main(void)
{
	int t, tt, i, j, n, m;
	sf("%d", &t);
	FOR(tt, 1, t) {
		reset(dic, 0);
		reset(wor, 0);
		sf("%d %d", &n, &m);
		FORS(i, n) {
			char temp[15];
			sf("%s", temp);
			int len = strlen(temp);
			dic[i][0] = (int) temp[0];
			dic[i][27] = (int) temp[len-1];
			FOR(j, 1, len-2) {
				dic[i][temp[j]-'a'+1]++;
			}
		}
		FORS(i, m) {
			char temp[15];
			sf("%s", temp);
			int len = strlen(temp);
			wor[i][0] = (int) temp[0];
			wor[i][27] = (int) temp[len-1];
			FOR(j, 1, len-2) {
				wor[i][temp[j]-'a'+1]++;
			}
		}
		pf("Case #%d: ", tt);
		FORS(j, m) {
			bool ada = 0;
			FORS(i, n) {
				if(same(i, j)) {
					ada = 1;
					break;
				}
			}
			pf("%d", ada);
		}
		nl;
	}
	
	return 0;
}
