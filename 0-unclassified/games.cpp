#include <bits/stdc++.h>
#include <iomanip>

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
#define reset(cok,n) memset(cok, n, sizeof(cok))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair
#define x first
#define y second

const LL mod = 1e9+7;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

pair<int,int> a[35];

int main(void)
{
	int i, n, j, ans = 0; sf("%d", &n);
	FORS(i,n) sf("%d %d", &a[i].x, &a[i].y);
	FORS(i,n) FOR(j,i+1,n-1) {
		if(a[i].x == a[j].y) ans++;
		if(a[i].y == a[j].x) ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}