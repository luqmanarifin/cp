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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int t, num[55], pos[55];

int main(void)
{
	sf("%d", &t);
	while(t--) {
		int n, i;
		reset(num, 0);
		sf("%d", &n);
		FOR(i, 1, n) {
			sf("%d", &num[i]);
			pos[num[i]] = i;
		}
		int ans = 0;
		FOR(i,1,n) {
			while(i < pos[i]) {
				swap(num[pos[i]], num[pos[i]-1]);
				swap(pos[num[pos[i]]], pos[num[pos[i]-1]]);
				ans++;
			}
		}
		pf("Optimal train swapping takes %d swaps.\n", ans);
	}
	
	return 0;
}
