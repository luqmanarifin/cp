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

typedef long long LL;
typedef double DB;
typedef unsigned long long ULL;

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
const ULL magic = 31;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

ULL power[2005];
ULL hash[1005][1005];
char s[1005][1005];

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//open;
	int t;
	ULL i, j;
	power[0] = 1;
	FOR(i, 1, 2004) power[i] = power[i-1] * magic;
	sf("%d", &t);
	while(t--) {
		int n, m, n1, m1;
		sf("%d %d", &n, &m);
		FOR(i, 1, n) sf("%s", &s[i][1]);
		FOR(i, 1, n) FOR(j, 1, m) {
			hash[i][j] = power[1] * (hash[i-1][j] + hash[i][j-1])
						  - power[2] * hash[i-1][j-1] + s[i][j] - 'a' + 1;
		}
		
		sf("%d %d", &n1, &m1);
		ULL key = 0;
		FOR(i, 1, n1) {
			char tc[105];
			sf("%s", &tc[1]);
			FOR(j, 1, m1) {
				key += (tc[j] - 'a' + 1) * power[n1 + m1 - i - j];
			}
		}
		int ans = 0;
		FOR(i, 1, n) {
			int x = i + n1 - 1;
			if(x > n) break;
			FOR(j, 1, m) {
				int y = j + m1 - 1;
				if(y > m) break;
				ULL now = hash[x][y] - power[n1] * hash[i - 1][y] - power[m1] * hash[x][j - 1]
						  + hash[i - 1][j - 1] * power[n1 + m1];
				if(now == key) ans++;
			}
		}
		
		pf("%d\n", ans);
	}
	
	//close;
	return 0;
}