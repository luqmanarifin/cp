#include <bits/stdc++.h>

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
#define open freopen("burrito.in","r",stdin); freopen("burrito.out","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-14;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

double a[N], b[N], g[N];
double gram[N];
double dem[N];

bool equal(double c, double d) {
	return abs(c - d) < eps;
}

int main(void)
{
	open;
	int i, n;
	double A, B;
	sf("%d %lf %lf", &n, &A, &B);
	priority_queue<pair<DB, int> > pq;
	double ans = 0;
	double cost = 0;
	FORS(i, n) {
		sf("%lf %lf %lf", &g[i], &a[i], &b[i]);
		if(a[i] == 0 || g[i] == 0) continue;
		if(b[i] == 0) {
			gram[i] = g[i];
			ans += (DB) a[i] * g[i];
		} else {
			dem[i] = (DB) a[i] / b[i];
			pq.push(mp((DB)a[i]*g[i], i));
		}
	}

	while(!pq.empty() && !equal(0, B)) {
		i = pq.top().second;
		double real = pq.top().first;
		double must = min(real, dem[i]*B);
		pq.pop();
		if(!equal(real, must)) pq.push(mp(must, i));
		else {
			gram[i] = must / a[i];
			ans += must;
			cost += gram[i] * b[i];
			B -= gram[i] * b[i];
		}
	}
	//cout << ans << endl;
	if(ans < A && !equal(ans, A)) {
		puts("-1 -1");
	} else {
		pf("%.15lf %.15lf\n", ans, cost);
		FORS(i, n) pf("%.15lf ", gram[i]); nl;
	}
	
	close;
	return 0;
}
