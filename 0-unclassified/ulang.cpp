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
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int n, num[N];
char s[N];

int main(void)
{
	sf("%d", &n);
	sf("%s", s);
	n = strlen(s);
	int i, ans = 0, j = 0;
	reset(num, 0);
	num[0] = 1;
	FOR(i,1,n-1) {
		if(s[i] == s[i-1]) num[j]++;
		else j++, num[j]++;
	}

	FOR(i,0,j) {
		ans += num[i]/2*8;
		num[i] %= 2;
	}
	i = 0;
	while(i < j-1) {
		if(num[i] && num[i+1]) {
			ans += 3;
			i += 2;
		} else i++;
	}
	if(num[j]) ans += 4;
	
	cout << ans << endl;
	return 0;
}
