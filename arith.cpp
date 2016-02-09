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
const int inf = 1e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

LL n, num[20];

int digit(LL a) {
	int i = 1;
	while(a/10) {
		i++;
		a /= 10;
	}
	return i;
}

int dfs(LL a) {
	int i;
	if(a <= 6) return a;
	if(a <= 11) return 13 - a;
	//cout << a << endl;
	int dig = digit(a);
	if(a <= 5*num[dig])
		return dig + dfs(abs(a - num[dig]));
		
	int cur = inf;
	FOR(i, dig, dig+1)
		if(abs(a - num[i]) <= a)
			cur = min(cur, i + dfs(abs(a - num[i])));
			
	return cur;
}

int main(void)
{
	int i;
	// generating 1111111
	num[1] = 1; LL now = 1;
	FOR(i,2,18) {
		now *= 10LL;
		num[i] = num[i-1] + now;
	}
	
	sf("%I64d", &n);
	pf("%d\n", dfs(n));

	return 0;
}
