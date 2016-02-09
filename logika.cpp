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

bool ada[26][2];

bool alpha(char a) {
	int b = a - 'a';
	return (0 <= b && b <= 25);
}

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		reset(ada, 0);
		char s[105];
		sf("%s", s);
		bool ans = 1, maybe = 0;
		int n = strlen(s), i;
		FORS(i, n) {
			if(s[i] != 'B' && s[i] != 'S' && !alpha(s[i]))
				continue;
			bool now, tmp = 0;
			if(s[i] == 'B') now = 1;
			else if(s[i] == 'S') now = 0;
			else if(alpha(s[i])) tmp = 1, maybe = 1;
			
			if(i && s[i-1] == '~') now ^= 1, tmp ^= 1;
			if(alpha(s[i])) ada[s[i]-'a'][tmp] = 1;
			if(!alpha(s[i])) ans = (ans && now);
		}
		FORS(i, 26) if(ada[i][0] && ada[i][1]) ans = 0;
		if(!ans) puts("salah");
		else if(ans && maybe) puts("mungkin");
		else puts("benar");
	}
	return 0;
}
