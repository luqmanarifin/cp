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
const int N = 3e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

struct item {
	item(int _a, int _b, int _s, int _id) : a(_a), b(_b), s(_s), id(_id) {};
	int a, b, s, id;
};

vector<item> v;
int x[N], y[N], ans[N], n;
LL res;

bool by(item lef, item rig) {
	return lef.b * rig.s < rig.b * lef.s;
}

bool check(int single) {
	int i, idob, dob = inf, idew, dew = -1;
	FORS(i, n) {
		if(ans[i] == 2 && y[i] - x[i] > dew) {
			dew = y[i] - x[i];
			idew = i;
		}
		if(ans[i] == 1 && x[i] > dew) {
			dew = x[i];
			idew = i;
		}
		if(ans[i] == 0 && y[i] < dob) {
			dob = y[i];
			idob = i;
		}
	}
	if(dob != inf && dew != -1 && dob - dew < single) {
		ans[idob] = 2;
		ans[idew]--;
		res += dob - dew;
		return 0;
	}
	return 1;
}

int main(void)
{
	int w, i, j;
	sf("%d %d", &n, &w);
	FORS(i, n) {
		sf("%d %d", x + i, y + i);
		int sec = y[i] - x[i];
		if(sec >= x[i]) {
			v.push_back(item(x[i], x[i], 1, i));
			v.push_back(item(sec, sec, 1, i));
		} else
			v.push_back(item(x[i], y[i], 2, i));
	}
	sort(v.begin(), v.end(), by);
	FORS(i, v.size()) {
		if(w < v[i].s) break;
		res += v[i].b;
		ans[v[i].id] += v[i].s;
		w -= v[i].s;
	}
	if(w) {
		int pos = i;
		for(i++; i < v.size(); i++)
			if(v[i].a < v[pos].a)
				pos = i;
		if(check(v[pos].a)) {
			res += v[pos].a;
			ans[v[pos].id]++;
		}
	}
	cout << res << endl;
	FORS(i, n) pf("%d", ans[i]); nl;
	return 0;
}
