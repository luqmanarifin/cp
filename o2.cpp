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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> ada[8], q[8];
int ans[3];
bool done[N];

int main(void)
{
	int n, m, i, j;
	sf("%d", &n);
	FORS(i, n) {
		int x, y;
		sf("%d %d", &x, &y);
		ada[x].push_back(y);
	}
	sf("%d", &m);
	FORS(i, m) {
		int x, y;
		sf("%d %d", &x, &y);
		q[x].push_back(y);
	}
	FOR(i, 1, 7) {
		if(ada[i].size()) sort(ada[i].begin(), ada[i].end());
		if(q[i].size()) sort(q[i].begin(), q[i].end());
	}
	FOR(i, 1, 7) {
		vector<int> sedia = ada[i];
		reset(done, 0);
		int udah = 0;
		if(sedia.empty()) continue;
		if(q[i].size())
		FORS(j, q[i].size()) {
			int qq = q[i][j];
			int pos = lower_bound(sedia.begin(), sedia.end(), qq-2) - sedia.begin();
			while(pos < sedia.size() && done[pos] && sedia[pos] <= qq + 2) pos++;
			if(pos == sedia.size() || sedia[pos] > qq + 2) continue;
			done[pos] = 1;
			udah++;
			ans[abs(qq - sedia[pos])]++;
			if(udah == sedia.size()) break;
		}
	}
	int score = ans[0]*100 + ans[1]*50 + ans[2]*25;
	pf("Score : %d\n", score);
	pf("Cool : %d\n", ans[0]);
	pf("Good : %d\n", ans[1]);
	pf("Bad : %d\n", ans[2]);
	pf("Miss : %d\n", n - ans[0] - ans[1] - ans[2]);
	return 0;
}
