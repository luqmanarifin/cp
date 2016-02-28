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
const DB eps = 1e-4;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

typedef pair<int,int> pii;
#define x first
#define y second

pii num[305];
int ans = inf;

int area(pii a, pii b, pii c) {
	int p = b.x - a.x;
	int q = b.y - a.y;
	int r = c.x - a.x;
	int s = c.y - a.y;
	return abs(p*s - q*r);
}

int main(void)
{
	int n, i, j, k;
	sf("%d", &n);
	FORS(i, n) sf("%d %d", &num[i].x, &num[i].y);
	bool bisa = 1;
	FORS(i, n) {
		FOR(j, i+1, n-1) {
			FOR(k, j+1, n-1) {
				int cur = area(num[i], num[j], num[k]);
				if(cur <= 0) continue;
				if(cur < ans) {
					ans = cur;
					bisa = 1;
				} else if(cur == ans) {
					bisa = 0;
				}
			}
		}
	}
	if(ans == inf) bisa = 0;
	pf("%.2lf\n", bisa? ans/2.0 : -1);
	return 0;
}
