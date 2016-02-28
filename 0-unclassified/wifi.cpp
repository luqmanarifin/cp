#include <iostream>
#include <cstdlib>
#include <fstream>
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
#include <cassert>

using namespace std;

#define LL long long
#define DB double
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

double dp[15][25];
char s[15], t[15];

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//open;
	sf("%s %s", s, &t[1]);
	int n = strlen(s), i, j, ans = 0;
	FORS(i, n) {
		if(s[i] == '+') ans++;
		else ans--;
	}
	dp[0][10] = 1.0;
	FOR(i, 1, n) {
		FORS(j, 25) {
			if(t[i] == '+') {
				if(j) dp[i][j] += dp[i - 1][j - 1];
			} else if(t[i] == '-') {
				if(j + 1 < 25) dp[i][j] += dp[i - 1][j + 1];
			} else {
				if(j) dp[i][j] += 0.5*dp[i - 1][j - 1];
				if(j + 1 < 25) dp[i][j] += 0.5*dp[i - 1][j + 1];
			}
		}
	}
	pf("%.18lf\n", dp[n][ans + 10]);
	//close;
	return 0;
}