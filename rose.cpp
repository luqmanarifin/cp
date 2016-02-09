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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

typedef pair<int,int> pii;
#define x first
#define y second

vector<pii> will[2], ans, temp;
int n, res;

int dist(pii a, pii b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int allDist(vector<pii> a) {
	int i, j, ret = 0;
	FORS(i, a.size()) FOR(j, i+1, a.size()-1)
		ret += dist(a[i], a[j]);
	return ret;
}

void backtrack(int id) {
	//pf("%d\n", id);
	if(id == n) {
		int cur = allDist(temp);
		if(cur > res) {
			res = cur;
			ans = temp;
		}
		return;
	}
	int i, j;
	FORS(i, will[0].size()) {
		temp.push_back(will[id < n/2][i]);
		backtrack(id + 1);
		temp.pop_back();
	}
}

bool cmp(pii a, pii b) {
	return dist(a, mp(0, 0)) > dist(b, mp(0, 0));
}

int main(void)
{
	int r, i, j;
	sf("%d %d", &n, &r);
	if(n % 2 == 0) {
		FORS(i, n) {
			if(i < n/2) ans.push_back(mp(r, 0));
			else ans.push_back(mp(-r, 0));
		}
		cout << allDist(ans) << endl;
		FORS(i, ans.size()) pf("%d %d\n", ans[i].x, ans[i].y);
		return 0;
	}
	will[0].push_back(mp(r, 0));
	will[0].push_back(mp(0, r));
	pii found = mp(0, 0);
	int difound = 0, h = r;
	vector<pii> wow;
	FOR(i, 1, r-1) {
		while(i*i + h*h > r*r) h--;
		wow.push_back(mp(i, h));
	}
	sort(wow.begin(), wow.end(), cmp);
	FORS(i, min((int)wow.size(), 4)) {
		will[0].push_back(wow[i]);
		will[0].push_back(mp(wow[i].x, -wow[i].y));
	}
	FORS(i, will[0].size()) {
		will[1].push_back(mp(-will[0][i].x, -will[0][i].y));
	}
	backtrack(0);
	cout << res << endl;
	FORS(i, ans.size()) pf("%d %d\n", ans[i].x, ans[i].y);
	return 0;
}
