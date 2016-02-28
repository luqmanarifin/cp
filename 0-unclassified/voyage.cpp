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
const int N = 1e4 + 4;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N], b[N];

int main(void)
{
	//open;
	int n, c, i;
	sf("%d %d", &n, &c);
	c -= n;
	if(c < 0) {
		puts("0");
		return 0;
	}
	bool allZero = 1;
	FORS(i, n) {
		sf("%d %d", &a[i], &b[i]);
		if(a[i]) allZero = 0;
	}
	if(allZero && c == 0) {
		puts("-1");
		return 0;
	}
	
	LL lower, upper;
	LL l = 1, r = 1e18;
	while(l < r) {
		LL need = 0;
		LL mid = (l + r) >> 1;
		FORS(i, n) {
			if(need > c) break;
			if(mid*a[i] < 0) {
				need = c + 1;
				break;
			}
			need += mid*a[i]/b[i];
		}
		if(need < c) l = mid + 1;
		else r = mid;
	}
	lower = l;
	
	l = 1, r = 1e18;
	while(l < r) {
		LL need = 0;
		LL mid = (l + r) >> 1;
		FORS(i, n) {
			if(need > c) break;
			if(mid*a[i] < 0) {
				need = c + 1;
				break;
			}
			need += mid*a[i]/b[i];
		}
		if(need <= c) l = mid + 1;
		else r = mid;
	}
	upper = l;
	
	cout << upper - lower << endl;
	
	//close;
	return 0;
}
