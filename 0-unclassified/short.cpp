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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

set<string> kamus[26];
string tc, temp;

int main(void)
{
	ios_base::sync_with_stdio(false);
	int n, q, i;
	cin >> n >> q;
	while(n--) {
		cin >> temp;
		kamus[temp[0]-'A'].insert(temp);
	}
	while(q--) {
		cin >> tc >> temp;
		if(tc[0] == 'U') kamus[temp[0]-'A'].insert(temp);
		else if(tc[0] == 'D') kamus[temp[0]-'A'].erase(kamus[temp[0]-'A'].find(temp));
		else {
			set<string>::iterator it = kamus[temp[0]-'A'].begin();
			int ans = 0;
			FORS(i, 26) {
				if(i + 'A' >= temp[0]) break;
				ans += kamus[i].size();
			}
			while(it != kamus[temp[0]-'A'].end()) {
				ans++;
				if(temp == *it) break;
				it++;
			}
			pf("%d\n", ans);
		}
	}
	
	return 0;
}
