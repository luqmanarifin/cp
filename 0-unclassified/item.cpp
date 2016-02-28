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

vector<int> ans;

int main(void)
{
	int i, n, v, j;
	sf("%d %d", &n, &v);
	FOR(i,1,n) {
		int k; sf("%d", &k);
		bool udah = 0;
		FORS(j, k) {
			int x;
			sf("%d", &x);
			if(udah) continue;
			if(v > x) {
				ans.push_back(i);
				udah = 1;
			}
		}
	}
	cout << ans.size() << endl;
	if(ans.size()) {
		FORS(i, ans.size())
			pf("%d ", ans[i]); nl;
			
	}
	
	return 0;
}
