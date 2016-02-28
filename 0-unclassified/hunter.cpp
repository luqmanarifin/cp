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
const int N = 3e4 + 5;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int got[N][300];
int ada[N];
bool vis[N][300];

int main(void)
{
	int i, j, k, n, p, lim;
	sf("%d %d", &n, &p);
	int now = 0;
	i = 0;
	while(now < N) {
		now -= i;
		i++;
	}
	lim = max(1, p - i);
	vis[p][p - lim] = 1;
	//cout << lim << endl;
	FORS(i, n) {
		int a;
		sf("%d", &a);
		ada[a]++;
	}
	int ans = 0;
	FOR(i, 1, N - 1) {
		FORS(j, 300) {
			if(vis[i][j]) {
				int cur = got[i][j] + ada[i];
				if(cur >= ans) {
					//pf("%d %d dapet %d\n", i, j + lim, cur);
					ans = cur;
				}
				FOR(k, -1, 1) {
					if(lim + j + k <= 0 || j + k < 0) continue;
					if(i + lim + j + k >= N || j + k >= 300) break;
					vis[i + lim + j + k][j + k] = 1;
					got[i + lim + j + k][j + k] = max(got[i + lim + j + k][j + k], cur);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}