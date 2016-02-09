#include <bits/stdc++.h>

/** 
 * Codeforces Round #271 (Div. 2)
 * Problem : A
 * بسم الله الرحمان الرحيم
 */

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

char s[105], c;
map<char, char> lef, rig; 

void init() {
	rig['q'] = 'w';
	rig['w'] = 'e';
	rig['e'] = 'r';
	rig['r'] = 't';
	rig['t'] = 'y';
	rig['y'] = 'u';
	rig['u'] = 'i';
	rig['i'] = 'o';
	rig['o'] = 'p';
	rig['p'] = ' ';
	
	rig['a'] = 's';
	rig['s'] = 'd';
	rig['d'] = 'f';
	rig['f'] = 'g';
	rig['g'] = 'h';
	rig['h'] = 'j';
	rig['j'] = 'k';
	rig['k'] = 'l';
	rig['l'] = ';';
	rig[';'] = ' ';
	
	rig['z'] = 'x';
	rig['x'] = 'c';
	rig['c'] = 'v';
	rig['v'] = 'b';
	rig['b'] = 'n';
	rig['n'] = 'm';
	rig['m'] = ',';
	rig[','] = '.';
	rig['.'] = '/';
	rig['/'] = ' ';
	
	int i;
	FORS(i, 26) {
		lef[rig[i + 'a']] = i + 'a';
	}
	lef[';'] = 'l';
	lef[','] = 'm';
	lef['.'] = ',';
	lef['/'] = '.';
}

int main(void)
{
	init();
	int i, j, n;
	sf("%c %s", &c, s);
	n = strlen(s);
	FORS(i, n) {
		if(c == 'R')
			pf("%c", lef[s[i]]);
		else
			pf("%c", rig[s[i]]);
	}
	nl;
	return 0;
}
