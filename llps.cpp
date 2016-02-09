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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool palin(string a) {
	int n = a.size(), i;
	bool is = 1;
	FORS(i, n)
		if(a[i] != a[n - 1 - i]) {
			is = 0;
			break;
		}
	return is;
}

string choose(string a, string b) {
	int aa = a.size();
	int bb = b.size(), i;
	if(aa > bb) swap(a, b);
	if(a.empty()) return b;
	FORS(i, min(aa, bb)) {
		if(a[i] > b[i]) return a;
		if(a[i] < b[i]) return b;
	}
	return b;
}

int main(void)
{
	string s, ans = "";
	cin >> s;
	int tt, j, n = s.length();
	FORS(tt, (1 << n)) {
		string cur = "";
		FORS(j, n) {
			if(tt & (1 << j))
				cur += s[j];
		}
		if(palin(cur))
			ans = choose(ans, cur);
	}
	cout << ans << endl;
	return 0;
}
