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
const LL inf = 4e18;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

pair<int,char> num[5];

int main(void)
{
	int i;
	char s[105];
	FORS(i,4) {
		sf("%s", s);
		num[i].first = strlen(s) - 2;
		num[i].second = i + 'A';
	}
	sort(num, num+4);
	if(num[0].first*2 <= num[1].first && num[2].first*2 <= num[3].first) pf("C");
	else if(num[0].first*2 <= num[1].first) putchar(num[0].second);
	else if(num[2].first*2 <= num[3].first) putchar(num[3].second);
	else pf("C");
	nl;
	
	return 0;
}
