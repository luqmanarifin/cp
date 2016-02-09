#include <bits/stdc++.h>

/**
 * Codeforces Round #265 (Div. 2)
 * Problem : D
 * Luqman Arifin (kadalbonek)
 */

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
const DB eps = 1e-6;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL a[8][3];
bool done;

LL dist(LL c[], LL b[]) {
	return 1LL*(c[0] - b[0])*(c[0] - b[0])
	+ 1LL*(c[1] - b[1])*(c[1] - b[1])
	+ 1LL*(c[2] - b[2])*(c[2] - b[2]);
}

void backtrack(int pos) {
	if(done == 1) return;
	if(pos == 8) {
		vector<LL> num;
		int i, j;
		FORS(i, 8) FORS(j, 8) {
			if(i == j) continue;
			num.push_back(dist(a[i], a[j]));
		}
		sort(num.begin(), num.end());
		bool valid = 1;
		FOR(i, 1, 23) if(num[i] != num[i-1]) valid = 0;
		if(num[23]*2LL != num[24]) valid = 0;
		FOR(i, 25, 47) if(num[i] != num[i-1]) valid = 0;
		if(num[23]*3LL != num[48]) valid = 0;
		FOR(i, 49, 55) if(num[i] != num[i-1]) valid = 0;
		if(valid) done = 1;
		return;
	}
	int per = 6;
	while(per--) {
		if(done) return;
		next_permutation(a[pos], a[pos]+3);
		backtrack(pos+1);
	}
}

int main(void)
{
	int i, j;
	FORS(i, 8) FORS(j, 3) sf("%I64d", &a[i][j]);
	backtrack(0);
	if(done) {
		puts("YES");
		FORS(i, 8) {
			FORS(j, 3) pf("%d ", a[i][j]);
			nl;
		}
	} else 
		puts("NO");
	return 0;
}