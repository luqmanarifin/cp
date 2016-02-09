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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[5], b[5];

bool nice() {
	return (b[3] - b[0] == (b[1] + b[2])/2
	&& b[3] - b[0] == (b[0] + b[1] + b[2] + b[3])/4
	&& (b[1] + b[2])%2 == 0
	&& (b[0] + b[1] + b[2] + b[3])%4 == 0);
}

int main(void)
{
	int n, i, j, k;
	sf("%d", &n);
	FORS(i, n) sf("%d", &a[i]);
	switch(n) {
		case 0 :
			puts("YES");
			puts("1 1 3 3");
			return 0;
			break;
		case 1 :
			puts("YES");
			pf("%d %d %d\n", a[0], 3*a[0], 3*a[0]);
			return 0;
			break;
		case 2 :
			FOR(i, 1, 1000) {
				FOR(j, 1, 1000) {
					FORS(k, n) b[k] = a[k];
					b[2] = i;
					b[3] = j;
					sort(b, b + 4);
					if(nice()) {
						puts("YES");
						pf("%d %d\n", i, j);
						return 0;
					}
				}
			}
			break;
		case 3 :
			FOR(i, 1, 1000) {
				FORS(j, n) b[j] = a[j];
				b[3] = i;
				sort(b, b + 4);
				if(nice()) {
					puts("YES");
					pf("%d\n", i);
					return 0;
				}
			}
			break;
		case 4 :
			FORS(i, n) b[i] = a[i];
			sort(b, b + 4);
			if(nice()) {
				puts("YES");
				return 0;
			}
			break;
	}
	puts("NO");
	return 0;
}
