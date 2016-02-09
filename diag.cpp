#include <bits/stdc++.h>

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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

struct ih {
	ih(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {};
	int a, b, c;
};

pair<int,int> pos[1005];
vector<ih> ans;
#define x first
#define y second

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FOR(i, 1, n-1) sf("%d %d", &pos[i].x, &pos[i].y);
	FOR(i, 1, n-1) {
		if(pos[i].y != i) {
			ans.push_back(ih(2, i, pos[i].y));
			FOR(j, i+1, n-1)
				if(pos[j].y == i) {
					pos[j].y = pos[i].y;
					break;
				}
		}
		if(pos[i].x != i + 1) {
			ans.push_back(ih(1, i+1, pos[i].x));
			FOR(j, i+1, n-1)
				if(pos[j].x == i + 1) {
					pos[j].x = pos[i].x;
					break;
				}
		}
	}
	cout << ans.size() << endl;
	FORS(i, ans.size()) pf("%d %d %d\n", ans[i].a, ans[i].b, ans[i].c);
	return 0;
}
