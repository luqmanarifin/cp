#include <bits/stdc++.h>

/**
 * Codeforces Round #284 (Div. 2)
 * Problem : B
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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

map<string,string> f;
string ans[3005];

int main(void)
{
	ios_base::sync_with_stdio(false);
	int n, m, i;
	cin >> n >> m;
	FORS(i, m) {
		string a, b;
		cin >> a >> b;
		f[a] = b;
	}
	FORS(i, n) {
		string temp;
		cin >> temp;
		if(temp.length() <= f[temp].length())
			ans[i] = temp;
		else
			ans[i] = f[temp];
	}
	FORS(i, n) {
		if(i) pf(" ");
		pf("%s", ans[i].c_str());
	}
	nl;
	return 0;
}
