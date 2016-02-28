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

int a, b, c, d;

int main(void)
{
	sf("%d %d %d %d", &a, &b, &c, &d);
	char x[100005];
	int aa = 0, bb = 0, cc = 0, dd = 0;
	cin >> x;
	int i, n = strlen(x);
	FORS(i, n) {
		if(x[i] == '1') aa++;
		else if(x[i] == '2') bb++;
		else if(x[i] == '3') cc++;
		else dd++;
	}
	cout << 1LL*a*aa + 1LL*b*bb + 1LL*c*cc + 1LL*d*dd << endl;
	
	return 0;
}
