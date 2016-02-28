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
#define isi first
#define init second

const LL mod = 1e9 + 7;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

pair<int,int> a[N], b[N], num[N];

bool byInit(const pair<int,int> &lef, const pair<int,int> &rig) {
	return lef.init < rig.init;
}

int main(void)
{
	int i, n; sf("%d", &n);
	FOR(i,1,n) {
		sf("%d", &num[i].isi);
		num[i].init = i;
	}
	sort(num + 1, num + 1 + n);
	FOR(i,1,n) a[i].init = b[i].init = num[i].init;
	
	int amax = n/3 + (n % 3 > 0);
	int bmax = n/3 + (n % 3 == 2);
	i = 1;
	while(i <= amax) {
		a[i].isi = i - 1;
		b[i].isi = num[i].isi - i + 1;
		++i;
	}
	
	int j = 1;
	while(j <= bmax) {
		a[i].isi = num[i].isi - i + 1;
		b[i].isi = i - 1;
		++i;
		++j;
	}
	
	--amax;
	while(i <= n) {
		a[i].isi = num[i].isi - amax;
		b[i].isi = amax;
		--amax;
		++i;
	}
	
	sort(a + 1, a + 1 + n, byInit);
	sort(b + 1, b + 1 + n, byInit);
	puts("YES");
	FOR(i,1,n) pf("%d ", a[i].isi); nl;
	FOR(i,1,n) pf("%d ", b[i].isi); nl;
	
	return 0;
}
