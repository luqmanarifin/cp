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
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char trans[26];
char s[N];

int main(void)
{
	int t, i, j;
	sf("%d", &t);
	while(t--) {
		FORS(i, 26) trans[i] = i + 'A';
		sf("%s", s);
		int len = strlen(s);
		int k;
		sf("%d", &k);
		while(k--) {
			char a = ' ', b = ' ';
			while(!('A' <= a && a <= 'Z')) sf("%c", &a);
			while(!('A' <= b && b <= 'Z')) sf("%c", &b);
			FORS(i, 26) if(trans[i] == b) trans[i] = a;
		}
		FORS(i, len) if('A' <= s[i] && s[i] <= 'Z') s[i] = trans[s[i]-'A'];
		pf("%s\n", s);
	}
	
	return 0;
}
