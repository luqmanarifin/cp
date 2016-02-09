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
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int main(void)
{
	char a[N], s[N];
	sf("%s %s", a, s);
	int aa = strlen(a);
	int n = strlen(s), i;
	sort(s, s+n);
	reverse(s, s+n);
	int j; i = 0;
	FORS(j, aa) {
		if(s[i] > a[j]) {
			swap(s[i], a[j]);
			i++;
		}
		if(i == n) break;
	}
	pf("%s\n", a);
	
	return 0;
}
