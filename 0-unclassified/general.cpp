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

const LL mod = 1e9+7;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int main(void)
{
	int i, n, mini = 100, maks = 1, x, a, b, num[105];
	sf("%d", &n);
	FORS(i,n) {
		sf("%d", &num[i]);
		if(num[i] > maks) maks = num[i];
		if(num[i] < mini) mini = num[i];
	}
	FORS(a,n)
		if(num[a] == maks)
			break;
	FORM(b,n)
		if(num[b] == mini)
			break;
	
	cout << (b < a? a - 2 + n - b : a - 1 + n - b) << endl;
	
	return 0;
}