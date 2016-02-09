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

#define x first
#define y second

#define size 1500

pair<int,pair<int,int> > item[size];
// coef, inner, outer
LL dp[size][size][2];

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//open;
	
	int i, j, k, n, id;
	while(sf("%d", &n) == 1) {
		id = 0;
		FORS(i, n) FORS(j, n) {
			int a, b;
			sf("%d.%d", &a, &b);
			if(i < j) item[++id].x = a * 1000 + b;
		}
		id = 0;
		FORS(i, n) FORS(j, n) {
			int a;
			sf("%d", &a);
			if(i < j) item[++id].y.x = a;
		}
		id = 0;
		FORS(i, n) FORS(j, n) {
			int a;
			sf("%d", &a);
			if(i < j) item[++id].y.y = a;
		}
		//puts("gukguk");
		sort(item + 1, item + 1 + id);
		FORS(i, size) FORS(j, size) FORS(k, 2) dp[i][j][k] = INF;
		dp[0][0][0] = 0;
		FOR(i, 1, id) {
			FOR(j, 0, i) {
				FORS(k, 2) {
					dp[i][j][k] = min(dp[i][j][k], dp[i-1][j+1][k] + item[i].y.x);
					if(j)
					dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-1][k] + item[i].y.y);
				}
				dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][0]);
			}
		}
		pf("%d %I64d\n", id/2, dp[id][0][id % 2]);
	}
	//close;
	return 0;
}