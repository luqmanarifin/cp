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
const double eps = 1e-13;
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int at[N], bt[N];
int last[N];

void add(int a, int num, int numb) {
	at[a] += num;
	bt[a] += numb;
	if(a) return add(last[a], num, numb);
}

int main(void)
{
	int m, id, n, temp;
	sf("%d", &m);
	while(m--) {
		sf("%d %d", &id, &n);
		while(n--) {
			sf("%d", &temp);
			last[temp] = id;
		}
	}
	int q;
	sf("%d", &q);
	while(q--) {
		int op, a, b;
		sf("%d", &op);
		if(op == -1) {
			sf("%d", &a);
			pf("%d %d\n", at[a], bt[a]);
		} else {
			sf("%d %d", &a, &b);
			add(op, a, b);
		}
	}
	
	
	return 0;
}
