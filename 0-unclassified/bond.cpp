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

DB ans = inf;
int x[105], y[105], posx, posy;

double dist(int a, int b, int c, int d) {
	return sqrt((a - c)*(a - c) + (b - d)*(b - d));
}

int main(void)
{
	int i, j, n, k, m;
	sf("%d %d", &n, &k);
	if(k > n) {
		puts("Gawat!");
		return 0;
	}
	FORS(i, n) sf("%d %d", x + i, y + i);
	FOR(i, -100, 100) FOR(j, -100, 100) {
		vector<DB> dis;
		FORS(m, n) dis.push_back(dist(i, j, x[m], y[m]));
		sort(dis.begin(), dis.end());
		if(dis[k-1] < ans) {
			ans = dis[k-1];
			posx = i;
			posy = j;
		}
	}
	pf("%d %d %d\n", posx, posy, (int) ceil(ans));
	return 0;
}
