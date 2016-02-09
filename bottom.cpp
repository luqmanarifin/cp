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
#define open freopen("input.txt","r",stdin)
#define close fclose(stdin)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

#define SIZE 10

LL num[SIZE];

int find(int n) {
	num[1] = 1;
	num[2] = 3;
	num[3] = 5;
	int i = 4, j;
	FOR(j, 4, n) {
		num[i] = (2*num[i-3] + 2*num[i-2] + num[i-1]) % mod;
		num[1] = num[2];
		num[2] = num[3];
		num[3] = num[4];
	}
	return (n > 3? num[4] : num[n]);
}

int main(void)
{
	clock_t t = clock();
	#define k 1e9
	cout << find(k) << endl;
	t = clock() - t;
	printf ("It took me (%.3lf miliseconds).\n", ((double)t*1000)/CLOCKS_PER_SEC);
	return 0;
}
