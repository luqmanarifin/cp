#include <bits/stdc++.h>
#include <iomanip>

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
#define reset(cok,n) memset(cok, n, sizeof(cok))
#define open freopen("A-large-practice.in","r",stdin); freopen("A-large-practice.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const LL maxint = pow(2, 32);

LL gcd(LL a, LL b) { return b? gcd(b, a%b): a; }
LL lcm(LL a, LL b) { return a*b / gcd(a, b); }

bool istrue(LL a) {
	if(a == 1) return true;
	if(a % 2) return false;
	return istrue(a/2);
}

int main(void)
{
	open;
	int n, tc = 0;
	
	sf("%d", &n);
	while(n--) {
		char in[30]; int i = 0;
		cin >> in; int len = strlen(in);
		LL p = 0, q = 0; 
		while(in[i] != '/') {
			p = p*10 + (in[i] - '0');
			i++;
		}
		i++;
		while(i < len) {
			q = q*10 + in[i] - '0';
			i++;
		}
		LL fpb = gcd(p, q);
		p /= fpb;
		q /= fpb;
		bool impos = istrue(q);
		LL ans = 1;
		while(p < q/2) {
			q /= 2;
			ans++;
		}
		
		pf("Case #%d: ", ++tc);
		if(!impos) puts("impossible");
		else cout << ans << endl;
	}
	close;
	return 0;
}
