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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int suami[25];
vector<int> harem[25];
int poin[25][25];
vector<int> ans;
int n;

void find(int mask, int man, int temp) {
	int i;
	if(man == n) {
		//FORS(i, n) pf("suami %d adalah %d\n", i, suami[i]);
		//pf("suka %d\n\n", temp);
		ans.push_back(temp);
		return;
	}
	if(mask & (1 << man)) {
		FORS(i, harem[man+1].size()) {
			if(suami[harem[man+1][i]] == 0 && poin[man+1][harem[man+1][i]]) {
				suami[harem[man+1][i]] = man + 1;
				find(mask, man + 1, temp + poin[man+1][harem[man+1][i]]);
				suami[harem[man+1][i]] = 0;
			}
		}
	} else {
		find(mask, man + 1, temp);
	}
} 

int main(void)
{
	//open;
	int i, j, k, t;
	sf("%d %d %d", &n, &k, &t);
	while(k--) {
		int a, b, c;
		sf("%d %d %d", &a, &b, &c);
		harem[a].push_back(b);
		poin[a][b] = c;
	}
	int pol = (1 << n), mask;
	FORS(mask, pol) {
		bool valid = 1;
		FORS(i, n) {
			if((mask & (1 << i)) && harem[i+1].size() == 0) {
				valid = 0;
				break;
			}
		}
		if(!valid) continue;
		find(mask, 0, 0);
	}
	sort(ans.begin(), ans.end());
	cout << ans[t-1] << endl;
	//FORS(i, ans.size()) pf("%d ", ans[i]); nl;
	
	//close;
	return 0;
}
