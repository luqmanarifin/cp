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
const int N = 5005;
const DB eps = 1e-3;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

LL high[N], dis[N];

bool isGreaterEqual(double a, double b) {
	if(abs(a - b) < eps) return true;
	return a > b;
}

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	reset(dis, 0);
	FORS(i,n) sf("%I64d", &high[i]);
	FOR(i,1,n-1) {
		sf("%I64d", &dis[i]);
		dis[i] += dis[i-1];
	}
	LL ans = 0;
	FOR(i, 0, n-2) {
		double m = -INF;
		FOR(j, i+1, n-1) {
			LL dist = dis[j] - dis[i];
			LL delta = high[j] - high[i];
			if(isGreaterEqual((DB) delta, (DB)m*dist)) {
				m = max(m, (double) delta/dist);
				ans = max(ans, dist*dist + delta*delta);
			}
		}
	}
	double Ans = sqrt(ans);
	pf("%.8f\n", Ans);
	return 0;
}
