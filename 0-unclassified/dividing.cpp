#include <bits/stdc++.h>

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
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair
#define X first
#define Y second

const LL mod = 1e9 + 7;
const int N = 1e4 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int n, t;
pair<int,int> node[N];

int main(void)
{
	sf("%d", &n);
	int a, b, c, d, i;
	FORS(i,n) sf("%d %d", &node[i].X, &node[i].Y);
	sf("%d", &t);
	while(t--) {
		sf("%d %d %d %d", &a, &b, &c, &d);
		int atas = 0, bawah = 0;
		double m = (DB)(d-b)/(c-a);
		FORS(i,n) {
			double expected = b + 1LL*(node[i].X-a)*m;
			if(node[i].Y > expected) atas++;
			else if(node[i].Y < expected) bawah++;
		}
		if(atas && bawah) pf("%d %d\n", atas, bawah);
		else puts("0");
	}
	
	return 0;
}
