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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int bit[N];
vector<int> ans;

int main(void)
{
	int i, j;
	int sum, limit;
	sf("%d %d", &sum, &limit);
	FORS(i,N) bit[i] = 1;
	i = 2;
	while(i <= limit) {
		for(j = i; j <= limit; j += i) {
			bit[j] *= 2;
		}
		i *= 2;
	}
	
	int now = 0;
	FORD(i,limit,1) {
		if(now + bit[i] <= sum) {
			ans.push_back(i);
			now += bit[i];
		}
		if(now == sum) {
			cout << ans.size() << endl;
			FORS(i, ans.size()) 
				pf("%d ", ans[i]); nl;
				return 0;
		}
	}
	puts("-1");
	return 0;
}
