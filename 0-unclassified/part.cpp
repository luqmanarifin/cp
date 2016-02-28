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

int n, k, p;
vector<int> odd;

int main(void)
{
	sf("%d %d %d", &n, &k, &p);
	
	int i, j = -1;
	vector<int> ans[N];
	FORS(i,n) {
		int a; sf("%d", &a);
		if(a&1) odd.push_back(a);
		else {
			if(j < k - 1) j++;
			ans[j].push_back(a);
		}
	}
	
	int needOdd = k - p + (j < p? 2*(p - 1 - j) : 0);
	if(odd.size() < needOdd || (odd.size() - needOdd)&1) {
		puts("NO");
		return 0;
	}
	int oo = 0;
	FOR(i,j+1,p-1) {
		ans[i].push_back(odd[oo]);
		ans[i].push_back(odd[oo+1]);
		oo += 2;
	}
	FOR(i,p,k-2) {
		ans[i].push_back(odd[oo]);
		oo++;
	}
	while(oo < odd.size()) {
		ans[k-1].push_back(odd[oo]);
		oo++;
	}
	puts("YES");
	FORS(i,k) {
		pf("%d ", ans[i].size());
		FORS(j, ans[i].size()) {
			pf("%d ", ans[i][j]);
		}
		nl;
	}
	
	return 0;
}
