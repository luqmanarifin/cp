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

vector<int> num;

int main(void)
{
	//open;
	int m, i, j;
	sf("%d", &m);
	while(m--) {
		int tc, l, r, x, ans, y;
		vector<int> temp;
		sf("%d", &tc);
		switch(tc) {
			case 0 :
				sf("%d", &x);
				num.push_back(x);
				break;
			case 1 :
				sf("%d %d %d", &l, &r, &x);
				l--, r--;
				ans = -1;
				FOR(i, l, r) {
					if((num[i] ^ x) > ans) {
						ans = num[i] ^ x;
						y = num[i];
					}
				}
				pf("%d\n", y);
				break;
			case 2 :
				sf("%d", &x);
				while(x--) num.pop_back();
				break;
			case 3 :
				sf("%d %d %d", &l, &r, &x);
				l--, r--;
				ans = 0;
				FOR(i, l, r) if(num[i] <= x) ans++;
				pf("%d\n", ans);
				break;
			case 4 :
				sf("%d %d %d", &l, &r, &x);
				l--, r--, x--;
				FOR(i, l, r) temp.push_back(num[i]);
				sort(temp.begin(), temp.end());
				pf("%d\n", temp[x]);
				break;
		}
	}
	
	//close;
	return 0;
}
