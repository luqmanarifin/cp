#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

void write(int a) {
	if(a < 26) pf("%c", a + 'A');
	else {
		write(a/26 - 1);
		pf("%c", (a % 26) + 'A');
	}
}

int main(void)
{
	int n; sf("%d", &n);
	while(n--) {
		char s[50];
		sf("%s", s);
		int i = 0, n = strlen(s);
		while('A' <= s[i] && s[i] <= 'Z') i++;
		while('0' <= s[i] && s[i] <= '9' && i < n) i++;
		int a = 0, b = 0;
		if(i == n) {
			i = 0;
			while('A' <= s[i] && s[i] <= 'Z') {
				a = a*26 + (s[i] - 'A' + 1);
				++i;
			}
			while(i < n) {
				b = b*10 + (s[i] - '0');
				++i;
			}
			pf("R%dC%d\n", b, a);
		} else {
			i = 1;
			while(s[i] != 'C') {
				a = a*10 + (s[i] - '0');
				++i;
			} ++i;
			while(i < n) {
				b = b*10 + (s[i] - '0');
				++i;
			}
			write(b-1); pf("%d\n", a);
		}
	}
	
	return 0;
}
