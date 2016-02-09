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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool done[2][105];
int a[2][105], lim[2];
int to[2][105];

bool find(int id, int num) {
	//pf("%d %d\n", id, num);
	int i, j;
	done[id][num] = 1;
	FOR(j, 1, lim[id^1]) {
		if(abs(a[id][num] - a[id^1][j]) <= 1) {
			if(to[id^1][j] == 0) {
				//pf("%d %d %d\n", id, num, j);
				to[id][num] = j;
				to[id^1][j] = num;
				return 1;
			} else if(!done[id][to[id^1][j]] && find(id, to[id^1][j])) {
				//pf("%d %d %d\n", id, num, j);
				to[id][num] = j;
				to[id^1][j] = num;
				return 1;
			}
		}
	}
	return 0;
}

int main(void)
{
	int i, j;
	FORS(i, 2) {
		sf("%d", &lim[i]);
		FOR(j, 1, lim[i]) {
			sf("%d", &a[i][j]);
		}
	}
	FOR(i, 1, lim[0]) {
		reset(done, 0);
		if(to[0][i] == 0) {
			find(0, i);
		}
	}
	int ans = 0;
	FOR(i, 1, lim[0]) {
		if(to[0][i]) {
			ans++;
			//pf("%d %d\n", i, to[0][i]);
		}
	}
	cout << ans << endl;
	return 0;
}
