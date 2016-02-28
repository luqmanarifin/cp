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
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

pair<int,int> num[N];

int main(void)
{
	int i, j, n, r, avg;
	sf("%d %d %d", &n, &r, &avg);
	LL goal = (LL) avg * n, now = 0;
	FORS(i, n) {
		sf("%d %d", &num[i].second, &num[i].first);
		now += num[i].second;
	}
	sort(num, num + n);
	LL ans = 0;
	FORS(i, n) {
		if(goal == now) break;
		LL add = min((LL)goal - now, (LL)r - num[i].second);
		if(add < 0) add = 0;
		//cout << "add " << add << endl;
		ans += add * num[i].first;
		now += add;
	}
	cout << ans << endl;
	return 0;
}
