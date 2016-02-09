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

char s[8][10] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
bool valid[10];

int main(void)
{
	int i, j, n;
	char t[10];
	sf("%d %s", &n, t);
	reset(valid, 1);
	FORS(i, n) {
		FORS(j, 8) {
			if(!valid[j]) continue;
			if(n != strlen(s[j])) {
				valid[j] = 0;
				continue;
			}
			if(t[i] == '.') continue;
			if(s[j][i] != t[i]) valid[j] = 0;
		}
	}
	FORS(i, 8) if(valid[i]) {
		puts(s[i]);
		return 0;
	}
	//FORS(i, 8) pf("%d ", valid[i]); nl;
}
