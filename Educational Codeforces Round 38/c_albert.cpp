#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;

#define newline '\n';
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO  ios_base::sync_with_stdio(false);\
		cin.tie(0);\
		cout.tie(0);

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

int x;

void read() {
	cin >> x;
}

void solve() {
	if (x == 0) {
		cout << 1 << " " << 1 << newline;
		return;
	}
	int lower = trunc(sqrt(x));
	vector<ii> factors;
	for (int i = 1; i <= lower; ++i) {
		if (x % i == 0) {
			factors.pb({i, x / i});
		}
	}
	for (auto cur: factors) {
		int a = cur.fi;
		int b = cur.se;
		if (a < b) swap(a,b);
		// cerr << "a=" << a << " " << ", b=" << b << endl;
		if (a + b % 2 == 1) continue;
		int n = (a+b)/2;
		int m = n/max(a-n, 1);
		// cerr << "n=" << n << " " << ", m=" << m << endl;
		if (m == 1) continue;
		if (n * n - (n/m) * (n/m) == x) {
			cout << n << " " << m << '\n';
			return;
		}
	}
	cout << -1 << newline;
}

int main() {
	FAST_IO;
	int tc;
	cin >> tc;
	while(tc--) {
		read();
		solve();
	}

	return 0;
}