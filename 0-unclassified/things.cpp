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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> pos[2005];
int ans[3][2005], udah;

int main(void)
{
	int i, j, k, n;
	sf("%d", &n);
	FORS(i, n) {
		int a;
		sf("%d", &a);
		pos[a].push_back(i);
	}
	int temp = 0;
	FOR(i, 1, 2000) {
		if(pos[i].size() > 1)
			temp += pos[i].size();
	}
	if(temp < 3) {
		puts("NO");
		return 0;
	}
	puts("YES");
	int t = 0;
	FOR(i, 1, 2000) {
		if(pos[i].empty()) continue;
		if(udah && pos[i].size() == 2) {
			FORS(j, 2) {
				ans[j][t] = pos[i][0];
				ans[j][t + 1] = pos[i][1];
			}
			ans[2][t] = pos[i][1];
			ans[2][t + 1] = pos[i][0];
			t += pos[i].size();
			continue;
		}
		FORS(j, 3) {
			FORS(k, pos[i].size()) {
				ans[j][t + k] = pos[i][k];
			}
			next_permutation(pos[i].begin(), pos[i].end());
		}
		if(!udah && pos[i].size() == 2)
			udah = 1;
		t += pos[i].size();
	}
	FORS(i, 3) {
		FORS(j, n) pf("%d ", ans[i][j] + 1);
		nl;
	}
	return 0;
}
