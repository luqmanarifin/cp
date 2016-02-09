#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

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

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int a[1005][1005], ca[1005][1005];
int b[1005][1005], cb[1005][1005];
char s[1005][1005];

void norm(int &x) {
	if(x >= mod) x -= mod;
}

int mul(int x, int y) {
	return (long long) x * y % mod;
}

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//open;
	int n, i, j;
	sf("%d", &n);
	FOR(i, 1, n) sf("%s", &s[i][1]);
	ca[1][1] = 1;
	FOR(i, 1, n) FOR(j, 1, n) {
		if(i > 1) {
			if(a[i-1][j] > a[i][j]) {
				a[i][j] = a[i-1][j];
				ca[i][j] = ca[i-1][j];
			} else if(a[i-1][j] == a[i][j]) {
				ca[i][j] += ca[i-1][j];
				norm(ca[i][j]);
			}
		}
		if(j > 1) {
			if(a[i][j-1] > a[i][j]) {
				a[i][j] = a[i][j-1];
				ca[i][j] = ca[i][j-1];
			} else if(a[i][j-1] == a[i][j]) {
				ca[i][j] += ca[i][j-1];
				norm(ca[i][j]);
			}
		}
		a[i][j] += (s[i][j] == 'C');
	}
	cb[n][n] = 1;
	FORD(i, n, 1) FORD(j, n, 1) {
		if(i < n) {
			if(b[i+1][j] > b[i][j]) {
				b[i][j] = b[i+1][j];
				cb[i][j] = cb[i+1][j];
			} else if(b[i+1][j] == b[i][j]) {
				cb[i][j] += cb[i+1][j];
				norm(cb[i][j]);
			}
		}
		if(j < n) {
			if(b[i][j+1] > b[i][j]) {
				b[i][j] = b[i][j+1];
				cb[i][j] = cb[i][j+1];
			} else if(b[i][j+1] == b[i][j]) {
				cb[i][j] += cb[i][j+1];
				norm(cb[i][j]);
			}
		}
		b[i][j] += (s[i][j] == 'C');
	}
	int q;
	sf("%d", &q);
	while(q--) {
		int maxcoin = 0;
		int ways = 0;
		int xa, ya, xb, yb;
		sf("%d %d %d %d", &xa, &ya, &xb, &yb);
		xa++, ya++, xb++, yb++;
		if((xa == 1 && ya == 1) || (xb == n && yb == n)) {
			puts("0 0");
			continue;
		}
		FOR(j, 1, ya-1) {
			if(xb == n) break;
			int tempcoin = a[xb][j] + b[xb+1][j];
			int tempways = mul(ca[xb][j], cb[xb+1][j]);
			if(tempcoin > maxcoin) {
				maxcoin = tempcoin;
				ways = tempways;
			} else if(tempcoin == maxcoin) {
				ways += tempways;
				norm(ways);
			}
		}
		FOR(i, 1, xa-1) {
			if(yb == n) break;
			int tempcoin = a[i][yb] + b[i][yb+1];
			int tempways = mul(ca[i][yb], cb[i][yb+1]);
			if(tempcoin > maxcoin) {
				maxcoin = tempcoin;
				ways = tempways;
			} else if(tempcoin == maxcoin) {
				ways += tempways;
				norm(ways);
			}
		}
		pf("%d %d\n", maxcoin, ways);
	}
	
	//close;
	return 0;
}