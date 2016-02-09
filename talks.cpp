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
#define db double

const int N = 1000010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int t[4001], d[4001], dp[4001][4001];

int main(void)
{
	int n, k, i, j;
	sf("%d %d", &n, &k);
	FORS(i,n) sf("%d %d", &t[i], &d[i]);
	FOR(i,0,min(n,k)) dp[i][i] = 1;
	FOR(i,1,n) {
		dp[i][0] = max(dp[i-1][0], t[i-1]) + d[i-1];
		FOR(j,1,min(i-1,k))
			dp[i][j] = min(dp[i-1][j-1], max(dp[i-1][j], t[i-1]) + d[i-1]);
	}
	int ans = 0;
	FORS(i,n)
		ans = max(ans, t[i] - dp[i][k]);
	ans = max(ans, 86401 - dp[n][k]);
	/*
	FOR(i,0,n)
		FOR(j,0,k)
			pf("dp[%d][%d] = %d\n",i,j,dp[i][j]);
	*/
	cout << ans << endl;
	
	return 0;
}