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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

vector<char> depan, belakang;

int main(void)
{
	int i, n;
	sf("%d", &n);
	char s[205];
	sf("%s", s);
	FORS(i, n) {
		depan.push_back(s[i]);
	}
	FOR(i, n, 2*n-1) {
		belakang.push_back(s[i]);
	}
	sort(depan.begin(), depan.end());
	sort(belakang.begin(), belakang.end());
	bool ans1 = 1, ans2 = 1;
	FORS(i, n) {
		if(depan[i] <= belakang[i])
			ans1 = 0;
		if(depan[i] >= belakang[i])
			ans2 = 0;
	}
	puts((ans1 || ans2)? "YES" : "NO");
	return 0;
}
