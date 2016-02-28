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
const int mod = 1e9+7;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

LL dp[2005][2005]; // nomer ke berapa urutan ke berapa

int main(void)
{
	int n, k, i, j, l;
	sf("%d %d", &n, &k);
	memset(dp,0,sizeof(dp));
	FOR(i,1,2000)
		dp[i][1] = 1;
	FOR(i,2,k) {
		FOR(j,1,n) {
			l = j;
			while(l <= n) {
				dp[l][i] += dp[j][i-1];
				if(dp[l][i] > mod) dp[l][i] -= mod;
				l += j;
			}
		}
	}
	//FOR(i,1,n) cout << dp[i][2] << " "; nl;
	LL ans = 0;
	FOR(i,1,n) {
		ans += dp[i][k];
		if(ans > mod) ans -= mod;
	}
	cout << ans << endl;
	
	return 0;
}