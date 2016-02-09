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
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int main(void)
{
	char s[205]; int k;
	sf("%s %d", s, &k);
	int n = strlen(s), i;
	int ans = min(k, (n + k)/2);
	int a = 0, b = ans;
	while(b < n) {
		while(2*b - a <= n + k) {
			bool valid = 1;
			FORS(i, b - a) {
				if(b + i == n) break;
				if(s[a+i] != s[b+i]) {
					valid = 0;
					break;
				}
			}
			if(valid) ans = max(ans, b - a);
			b++;
		}
		a++;
		b = a + ans;
	}
	cout << 2*ans << endl;
	return 0;
}
