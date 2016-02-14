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

bool is[205][205];
int x[55];

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FORS(i, n) sf("%d", x + i);
	FORS(i, n) {
		int a;
		sf("%d", &a);
		is[x[i]+100][a+100] = 1;
	}
	int ans = 0;
	FOR(i, 0, 200) FOR(j, 0, 200) {
		bool a = 0, b = 0, c = 0, d = 0;
		int ii = i + 1, jj = j;
		while(ii <= 200) {
			if(is[ii][jj]) {
				a = 1;
				break;
			}
			ii++;
		}
		
		ii = i - 1, jj = j;
		while(ii >= 0) {
			if(is[ii][jj]) {
				b = 1;
				break;
			}
			ii--;
		}
		
		ii = i, jj = j + 1;
		while(jj <= 200) {
			if(is[ii][jj]) {
				c = 1;
				break;
			}
			jj++;
		}
		
		ii = i, jj = j - 1;
		while(jj >= 0) {
			if(is[ii][jj]) {
				d = 1;
				break;
			}
			jj--;
		}
		if(a && b && c && d) ans++;
	}
	cout << ans << endl;
	return 0;
}
