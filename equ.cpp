#include <bits/stdc++.h>

/**
 * Codeforces Round #262 (Div. 2)
 * Problem : B
 * Luqman Arifin (kadalbonek)
 */

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
const int lim = 1e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> ans;

int digit(LL a) {
	int temp = 0;
	while(a != 0) {
		temp += a%10;
		a /= 10;
	}
	return temp;
}

int main(void)
{
	LL i, j, a, b, c;
	sf("%I64d %I64d %I64d", &a, &b, &c);
	FOR(i, 1, 81) {
		LL now = 1;
		FORS(j, a) now *= i;
		now = now * b + c;
		if(now >= lim || now <= 0) continue;
		//pf("%I64d %d", now, digit(now)); nl;
		if(digit(now) == i) ans.push_back(now);
	}
	if(ans.size()) sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	FORS(i, ans.size()) pf("%d ", ans[i]); nl;
	return 0;
}
