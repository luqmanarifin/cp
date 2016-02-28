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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int n, q, i;
int lef[N];
int rig[N];

int main(void)
{
	ios_base::sync_with_stdio(false);
	//open;
	cin >> n >> q;
	while(n || q) {
		FOR(i, 1, n) lef[i] = i - 1, rig[i] = i + 1;
		while(q--) {
			int l, r;
			cin >> l >> r;
			pf(lef[l] == 0? "* " : "%d ", lef[l]);
			pf(rig[r] == n + 1? "*" : "%d", rig[r]);
			rig[lef[l]] = rig[r];
			lef[rig[r]] = lef[l];
			nl;
		}
		puts("-");
		cin >> n >> q;
	}
	
	//close;
	return 0;
}