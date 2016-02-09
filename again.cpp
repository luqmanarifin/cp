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

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

char s[66];
LL memo[66][66];

LL find(int l, int r) {
	if(memo[l][r] >= 0) return memo[l][r];
	if(r < l) return memo[l][r] = 0;
	if(s[l] == s[r])
		memo[l][r] = find(l+1, r) + find(l, r-1) + 1;
	else
		memo[l][r] = find(l+1, r) + find(l, r-1) - find(l+1, r-1);
	return memo[l][r];
}

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//open;
	int t, i, j, n, k, l;
	sf("%d", &t);
	while(t--) {
		reset(memo, -1);
		sf("%s", &s[1]);
		n = strlen(&s[1]);
		pf("%lld\n", find(1, n));
	}
	
	//close;
	return 0;
}