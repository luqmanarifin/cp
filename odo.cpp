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

int paket[15];

int main(void)
{
	int i, j;
	char s[20];
	paket[1] = 1;
	int po = 1;
	FOR(i, 2, 9) {
		po *= 10LL;
		paket[i] = po + 9*paket[i-1];
	}
	//FOR(i, 1, 9) pf("%d %d\n", i, paket[i]);
	sf("%s", s);
	while(s[0] != '0') {
		int ans = 0;
		int n = strlen(s), pos = 0;
		po = 1LL;
		FORM(i, n) {
			if(pos) po *= 10LL; 
			pos++;
			int d = s[i] - '0';
			if(d >= 4) {
				ans += po;
				d--;
			}
			ans += d*paket[pos-1];
			//pf("%d %d\n", ans, paket[pos-1]);
		}
		int num = 0;
		FORS(i, n) {
			num = num*10 + s[i] - '0';
		}
		pf("%d: %d\n", num, num-ans);
		sf("%s", s);
	}
	
	return 0;
}
