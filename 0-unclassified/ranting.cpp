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

bool alpha(char c) {
	if('0' <= c && c <= '9') return true;
	if('a' <= c && c <= 'z') return true;
	if('A' <= c && c <= 'Z') return true;
	return false;
}

bool bet(char c) {
	if('a' <= c && c <= 'z') return true;
	if('A' <= c && c <= 'Z') return true;
	return false;
}

string s;
bool done[1005];

int main(void)
{
	ios_base::sync_with_stdio(false);
	int tt, t;
	cin >> t;
	cin.ignore();
	FOR(tt, 1, t) {
		reset(done, 0);
		vector<string> ans;
		getline(cin, s);
		int n = s.length(), i, j;
		FORS(i, n) {
			if(s[i] == '#' && i < n-1 && bet(s[i+1])) {
				if((i && !done[i-1]) || i == 0) {
					int awal = i;
					while(i < n-1 && alpha(s[i+1])) {
						i++;
					}
					done[i] = 1;
					ans.push_back(s.substr(awal, i - awal + 1));
				}
			}
		}
		int sz = (int) ans.size();
		printf("Case #%d: %d\n", tt, (int) ans.size());
		FORS(i, sz) {
			printf("%s\n", ans[i].c_str());
		}
	}
	
	return 0;
}
