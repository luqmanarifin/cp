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
const int inf = 1e8;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

pair<int,int> a[10005];

int calc(int i, int j) {
	return (a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y)*(a[i].y - a[j].y);
}

bool fi (const pair<int,int> &lef, const pair<int,int> &rig) {
	return lef.x < rig.x;
}

bool sec (const pair<int,int> &lef, const pair<int,int> &rig) {
	return lef.y < rig.y;
}

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	while(n) {
		int ans = inf;
		FORS(i,n)
			sf("%d %d", &a[i].x, &a[i].y);
		
		sort(a, a+n, fi);
		FORS(i,n-1)
			if(calc(i, i+1) < ans)
				ans = calc(i, i+1);
			
		sort(a, a+n, sec);
		FORS(i,n-1)
			if(calc(i, i+1) < ans)
				ans = calc(i, i+1);
		
		if(ans == inf) puts("INFINITY");
		else pf("%.4f\n", sqrt(ans));
		
		sf("%d", &n);
	}
	
	return 0;
}