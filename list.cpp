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

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

pair<int,int> a[55];
int cur[55];

#define p first
#define t second

bool by(pair<int,int> i, pair<int,int> j) {
	if(i.p != j.p) return i.p > j.p;
	return i.t < j.t;
}

int main(void)
{
	int n, k, i;
	sf("%d %d", &n, &k);
	FORS(i, n) sf("%d %d", &a[i].p, &a[i].t);
	sort(a, a + n, by);
	FORS(i, n) {
		cur[i] = 1;
		if(a[i] == a[i-1])
			cur[i] += cur[i-1];
	}
	k--;
	while(cur[k+1] != 1 && k + 1 < n) k++;
	cout << cur[k] << endl;
	return 0;
}
