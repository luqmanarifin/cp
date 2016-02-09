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

struct fenwick {
public:
	fenwick(int _n) : n(_n) {
		a.resize(n + 1);
	};
	void update(int pos, long long val) {
		for(; pos <= n; pos |= pos + 1) {
			a[pos] += val;
		}
	}
	long long find(int pos) {
		long long aval = 0;
		for(; pos >= 0; pos = (pos & (pos + 1)) - 1) {
			aval += a[pos];
		}
		return aval;
	}
private:
	vector<LL> a;
	int n;
};

int type[N], p[N];
LL v[N], a[N];
vector<LL> num;
map<LL, int> id;

int main(void)
{
	int n, q, i, j;
	sf("%d %d", &n, &q);
	FORS(i, n) {
		sf("%I64d", a + i);
		num.push_back(a[i]);
	}
	FORS(i, q) {
		sf("%d", type + i);
		if(type[i] == 1) {
			sf("%d %I64d", p + i, v + i);
		} else
			sf("%I64d", v + i);
		num.push_back(v[i]);
	}
	sort(num.begin(), num.end());
	FORS(i, num.size()) id[num[i]] = i;
	
	fenwick Sum(n + q);
	fenwick Num(n + q);
	FORS(i, n) {
		Sum.update(id[a[i]], a[i]);
		Num.update(id[a[i]], 1);
	}
	FORS(i, q) {
		if(type[i] == 1) {
			--p[i];
			Sum.update(id[a[p[i]]], -a[p[i]]);
			Num.update(id[a[p[i]]], -1);
			a[p[i]] = v[i];
			Sum.update(id[a[p[i]]], a[p[i]]);
			Num.update(id[a[p[i]]], 1);
		} else {
			int tt;
			double l = 0.0, r = 1e16, ans = INF;
			FORS(tt, 60) {
				double mid = (l + r)/2;
				LL mm = floor(mid);
				LL last = num[upper_bound(num.begin(), num.end(), mm)-num.begin()-1];
				LL sum = Sum.find(id[last]);
				LL num = Num.find(id[last]);
				double high = (DB)(sum + v[i])/(DB)num;
				if(mid < high) l = mid;
				else r = mid;
				ans = min(ans, high);
			}
			pf("%.10lf\n", ans);
		}
	}
	return 0;
}
