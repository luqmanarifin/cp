#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

#define LL long long
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORM(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORD(i,n) FORM(i, 0, n-1)
#define mp make_pair

const LL maxnum = 10000000000;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

map<LL, bool> is;

int main()
{
	is[0] = true;
	is[1] = true;
	LL a = 0, b = 1, c = 1, t, n;
	while(c <= maxnum) {
		c = a+b;
		is[c] = true;
		a = b; b = c;
	}
	cin >> t;
	while(t--) {
		cin >> n;
		if(is[n]) puts("IsFibo");
		else puts("IsNotFibo");
	}
	
	return 0;
}