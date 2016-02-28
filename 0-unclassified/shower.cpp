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

const LL mod = 1e9 + 7;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int num[10];
int a[10][10];

int main(void)
{
	int i, j;
	FORS(i,5) num[i] = i; int ans = 0;
	FORS(i,5) FORS(j,5) sf("%d", &a[i][j]);
	do {
		int c = a[num[0]][num[1]] + a[num[1]][num[0]] + a[num[1]][num[2]] + a[num[2]][num[1]];
		int b = 2*(a[num[2]][num[3]] + a[num[3]][num[2]] + a[num[3]][num[4]] + a[num[4]][num[3]]);
		ans = max(ans, c + b);
	} while(next_permutation(num, num+5));
	
	cout << ans << endl;
	return 0;
}
