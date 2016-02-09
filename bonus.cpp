#include <iostream>
#include <cstdio>
#include <iomanip>

typedef long long LL;
typedef double DB;

#define LD long double
#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("bonus.in","r",stdin); freopen("bonus.out","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const LD eps = 7.5e-17;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL n, a, b;
LD ans;

void prob(int id, LD prev, LL num, LL den) {
	LD cur = prev*num/den;
	//pf("%.15lf, %d %d\n", cur, a, b);
	ans += cur;
	if(id == n || cur < eps) return;
	if(a) {
		prob(id+1, prev*a--*2/(LD)den, num, den - 2);
		a++;
	}
	if(b) {
		prob(id+1, prev*b--/(LD)den, num, den - 1);
		b++;
	}
}

int main(void)
{
	//open;
	sf("%d %d %d", &n, &a, &b);
	ans = 0;
	//eps = (LD)2e-10/(LD)(2*a + b + 2);
	prob(1, 1.0, 2, 2*a + b + 2);
	cout << setprecision(30) << ans << endl;
	
	ans = 0;
	//eps = 1e-10/(LD)(2*a + b + 1);
	prob(1, 1.0, 1, 2*a + b + 1);
	cout << setprecision(30) << ans << endl;
	
	//close;
	return 0;
}
