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
#define close fclose(stdin); fclose(stdout)

#define SIZE 100000000

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool visited[SIZE];
int cache[SIZE];

int find(int n) {
	switch(n) {
		case 1 : return 1; break;
		case 2 : return 3; break;
		case 3 : return 5; break; 
	}
	if(visited[n]) return cache[n];
	visited[n] = true;
	cache[n] = 2*find(n - 3)
				+ 2*find(n - 2)
				+   find(n - 1);
	return cache[n];
}

int main() {
	memset(visited, false, sizeof(visited));
	clock_t t;
	t = clock();
	int k = 15, i;
	FOR(i, 1, 15) pf("%d ", find(i));
	t = clock() - t;
	printf ("It took me (%.3lf miliseconds).\n", ((double)t*1000)/CLOCKS_PER_SEC);
	return 0;
}