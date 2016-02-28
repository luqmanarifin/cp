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

bool is(string a) {
	int len = a.length(), i;
	FORS(i, len) if(a[i] != a[len - i - 1]) return 0;
	return 1;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	int i, j, k, n;
	string s;
	cin >> s;
	n = s.length();
	FOR(i, 0, n) {
		FORS(j, 26) {
			string temp;
			FORS(k, i) temp.push_back(s[k]);
			temp.push_back(j + 'a');
			FOR(k, i, n-1) temp.push_back(s[k]);
			if(is(temp)) {
				pf("%s\n", temp.c_str());
				return 0;
			}
		}
	}
	puts("NA");
	
	return 0;
}
