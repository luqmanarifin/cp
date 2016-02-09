#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 2e5 + 5;

struct Bit {
public:
	Bit(int _n) : n(_n) {
		num.resize(n + 1, 0);
	};
	void add(int i) {
		for(; i <= n; i |= i + 1) {
			num[i]++;
		}
	}
	int find(int i) {
		int temp = 0;
		for(; i >= 0; i = (i & (i + 1)) - 1) {
			temp += num[i];
		}
		return temp;
	}
private:
	int n;
	vector<int> num;
};

int ans[N];
int a[N];
int b[N];

int main(void)
{
	int i, j, n;
	sf("%d", &n);
	Bit suma(n), sumb(n);
	FORS(i, n) {
		int temp;
		sf("%d", &temp);
		a[i] = temp - suma.find(temp);
		suma.add(temp);
	}
	FORS(i, n) {
		int temp;
		sf("%d", &temp);
		b[i] = temp - sumb.find(temp);
		sumb.add(temp);
	}
	FORM(i, n) {
		ans[i] += a[i] + b[i];
		if(i) {
			ans[i-1] += ans[i] / (n - i);
		}
		ans[i] %= (n - i);
	}
	Bit tot(n);
	FORS(i, n) {
		int l = 0, r = n - 1;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(mid - tot.find(mid) < ans[i]) l = mid + 1;
			else r = mid;
		}
		pf("%d ", l);
		tot.add(l);
	}
	nl;
	return 0;
}
