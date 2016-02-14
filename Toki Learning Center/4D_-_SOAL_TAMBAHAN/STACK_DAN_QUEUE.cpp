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

deque<int> d;
char s[15];

int main(void)
{
	int n, a;
	sf("%d", &n);
	while(n--) {
		sf("%s", s);
		int len = strlen(s);
		if(len == 10) {
			sf("%d", &a);
			d.push_front(a);
		} else if(len == 8) d.pop_back();
		else {
			if(s[8] == 'k') {
				sf("%d", &a);
				d.push_back(a);
			} else d.pop_front();
		}
	}
	while(!d.empty()) {
		a = d.front();
		pf("%d\n", a);
		d.pop_front();
	}
	return 0;
}
