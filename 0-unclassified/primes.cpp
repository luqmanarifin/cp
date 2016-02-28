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
const int N = 1e6;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<LL> ada;
bitset<N + 10> is;

int main(void)
{
	LL i, j;
	for(i = 2; i <= N; i++) {
		if(!is[i]) {
			ada.push_back(i*i);
			if(i*i <= N)
			for(j = i*i; j <= N; j += i)
				is[j] = 1;
		}
	}
	int n; sf("%d", &n);
	while(n--) {
		LL a; sf("%I64d", &a);
		puts(binary_search(ada.begin(), ada.end(), a)? "YES" : "NO");
	}
	return 0;
}
