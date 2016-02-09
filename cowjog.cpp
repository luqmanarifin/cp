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
#define open freopen("cowjog.in","r",stdin); freopen("cowjog.out","w",stdout)
#define close fclose(stdin); fclose(stdout)

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int bit[N], n;
pair<int,int> num[N];

void add(int pos) {
	for(; pos <= n; pos |= pos + 1)
		bit[pos]++;
}

int find(int pos) {
	int temp = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
		temp += bit[pos];
	}
	return temp;
}

int main(void)
{
	//ios_base::sync_with_stdio(false);
	open;
	int i, j;
	sf("%d", &n);
	FORS(i, n) {
		int a, b;
		sf("%d %d", &a, &b);
		num[i] = mp(b, i);
	}
	sort(num, num + n);
	int ans = 0;
	FORS(i, n) {
		if(find(n - num[i].second) == 0) {
			add(n - num[i].second);
			ans++;
		}
	}
	cout << ans << endl;
	close;
	return 0;
}