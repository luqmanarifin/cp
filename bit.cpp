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

int main(void)
{
	char s[100005];
	sf("%s", s);
	int i, n = strlen(s);
	bool ada = 0, udah = 0;
	FORS(i, n) if(s[i] == '0') ada = 1;
	FORS(i, n) {
		if(!udah && !ada && s[i] - '0') i++, udah++;
		if(!udah && ada && s[i] == '0') i++, udah++;
		if(i < n) pf("%c", s[i]);
	}
	if(n == 1) pf("0");
	nl; return 0;
}
