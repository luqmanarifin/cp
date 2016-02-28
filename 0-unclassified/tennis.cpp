#include <bits/stdc++.h>

/**
 * Codeforces Round #283 (Div. 2)
 * Problem : D
 * Luqman Arifin (kadalbonek)
 * بسم الله الرحمان الرحيم
 */

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

int sum[N][2];
int win[2];
vector<pair<int,int> > ans;

int main(void)
{
	int i, j, n, t;
	sf("%d", &n);
	FOR(i, 1, n) {
		int a;
		sf("%d", &a);
		sum[i][--a]++;
		sum[i][0] += sum[i-1][0];
		sum[i][1] += sum[i-1][1];
	}
	FOR(t, 1, n) {
		bool valid = 1;
		reset(win, 0);
		int last = 0;
		i = 1;
		while(i <= n) {
			int l = i;
			int r = n;
			while(l < r) {
				int mid = (l + r) >> 1;
				int pointFirst = sum[mid][0] - sum[i-1][0];
				int pointSecond = sum[mid][1] - sum[i-1][1];
				if(pointFirst < t && pointSecond < t)
					l = mid + 1;
				else 
					r = mid;
			}
			if(sum[l][0] - sum[i-1][0] == t) {
				win[0]++;
				last = 0;
			} else if(sum[l][1] - sum[i-1][1] == t) {
				win[1]++;
				last = 1;
			} else {
				valid = 0;
			}
			i = l + 1;
		}
		valid &= (win[0] != win[1]) && ((win[0] < win[1]) == last);
		if(valid) {
			ans.push_back(mp(max(win[0], win[1]), t));
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	FORS(i, ans.size()) pf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}
