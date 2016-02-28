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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 2e5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> enemy[N + 5];
pair<int,int> will[N + 5];

int main(void)
{
	int n, k, i, j;
	sf("%d %d", &n, &k);
	int need = n - k + 1;
	if(need == 0) {
		puts("0");
		return 0;
	}
	FORS(i, n) {
		int p, e;
		sf("%d %d", &p, &e);
		enemy[p].push_back(e);
		will[i] = mp(e, p);
	}
	FOR(i, 0, N) if((int) enemy[i].size()) {
		sort(enemy[i].begin(), enemy[i].end());
	}
	sort(will, will + n);
	int point = 1, loser = (int) enemy[0].size() + (int) enemy[1].size();
	int obv = 0;
	while(loser < need) {
		point++;
		loser += (int) enemy[point].size();
		if(point >= 2) obv += (int) enemy[point-2].size();
	}
	if(point > n) {
		puts("-1");
		return 0;
	}
	
	bool awal = 1;
	LL ans = INF;
	for(; loser <= n; point++) {
		if(!awal) {
			loser += (int) enemy[point].size();
			if(point >= 2) obv += (int) enemy[point-2].size();
		}
		awal = 0;
		int from = need - obv;
		if((int) enemy[point].size() + (int) enemy[point-1].size() < from)
			continue;
		int a = 0, b = 0;
		LL cur = 0;
		//cout << from << endl;
		FORS(i, from) {
			int lef = (a < (int) enemy[point-1].size()? enemy[point-1][a] : inf);
			int rig = (b < (int) enemy[point].size()? enemy[point][b] : inf);
			if(lef < rig) cur += lef, a++;
			else cur += rig, b++;
		}
		if(from < 0) from = 0;
		int udah = 0;
		//pf("a b : %d %d\n", a, b);
		for(i = 0; udah < point - from; i++) {
			int id = will[i].second;
			int cost = will[i].first;
			if(id == point - 1 && a) {
				a--;
				continue;
			}
			if(id == point && b) {
				b--;
				continue;
			}
			udah++;
			cur += cost;
		}
		//pf("haha %d %I64d\n", point, cur);
		ans = min(ans, cur);
		if(obv >= need) break;
	}
	cout << (ans == INF? -1 : ans) << endl;
	return 0;
}
