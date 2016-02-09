#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>

using namespace std;

#define LL long long
#define DB double
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORD(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)


const int N = 100010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

DB dp[1 << 20], x[N], y[N], a[N], l, r;
int n, i, j;

DB calculate(int id, const double &now) {
	DB delta = atan((now - x[id]) / y[id]) + a[id];
	if(delta > atan((r - x[id]) / y[id])) return r;
	return x[id] + tan(delta)*y[id];
}

int main(void)
{
	cin >> n >> l >> r;
	FORS(i,n) {
		cin >> x[i] >> y[i] >> a[i];
		a[i] = a[i] * PI / 180;
	}
	int next;
	FORS(i,(1 << n)) dp[i] = l;
	FORS(i,(1 << n)) {
		FORS(j,n) {
			if(i & 1 << j) continue;
			next = i | 1 << j;
			//cout << calculate(j, dp[i]); nl;
			dp[next] = fmax(dp[next], calculate(j, dp[i]));
			//cout << dp[next]<<' ' <<i<<' '<<j<< endl;
		}
	}
	pf("%.10f\n", min(r, dp[(1 << n) - 1]) - l);
	
	return 0;
}