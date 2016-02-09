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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int d[1000], s[1000], tangki;
int ben, t;

int main()
{
	int i, m, k;
	sf("%d %d", &m, &k);
	FORS(i, m) sf("%d", &d[i]);
	FORS(i, m) {
		sf("%d", &s[i]);
		tangki += s[i];
		ben = max(ben, s[i]);
		while(tangki < d[i]) {
			tangki += ben;
			t += k;
		}
		tangki -= d[i];
		t += d[i];
	}
	cout << t << endl;
	return 0;
}