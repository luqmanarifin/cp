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
	char pass[105];
	bool a = 0,b = 0,c = 0;
	sf("%s", pass);
	int i, n = strlen(pass);
	FORS(i, n) {
		if(0 <= pass[i] - 'A' && pass[i] - 'A' <= 25) a = 1;
		else if(0 <= pass[i] - 'a' && pass[i] - 'a' <= 25) b = 1;
		else if(0 <= pass[i] - '0' && pass[i] - '0' <= 9) c = 1;
	}
	if(n >= 5 && a && b && c) puts("Correct");
	else puts("Too weak");
	return 0;
}