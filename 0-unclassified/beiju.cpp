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

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[N];

int main(void)
{
	ios_base::sync_with_stdio(false);
	while(cin >> s) {
		deque<vector<char> > ans;
		vector<char> temp;
		ans.push_back(temp);
		int i, j, n = strlen(s);
		bool st = 1;
		FORS(i, n) {
			if(s[i] == '[') {
				ans.push_front(temp);
				st = 0;
			} else if(s[i] == ']') {
				ans.push_back(temp);
				st = 1;
			} else {
				if(st) ans.back().push_back(s[i]);
				else ans.front().push_back(s[i]);
			}
		}
		FORS(i, ans.size()) {
			FORS(j, ans[i].size()) {
				pf("%c", ans[i][j]);
			}
		}
		nl;
	}
	
	return 0;
}
