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

LL a[8][3], num[100];
bool done;

LL dist(LL c[], LL b[]) {
	return (c[0] - b[0])*(c[0] - b[0])
	+ (c[1] - b[1])*(c[1] - b[1])
	+ (c[2] - b[2])*(c[2] - b[2]);
}

void backtrack(int pos) {
	if(done == 1) return;
	if(pos == 8) {
		int i, j;
		FORS(i, 8) {
			int t = 0;
			LL sm = INF;
			FORS(j, 8) {
				if(i == j) continue;
				num[t++] = dist(a[i], a[j]);
				sm = min(sm, num[t-1]);
			}
			if(sm == 0) return;
			sort(num, num + t);
			FOR(j, 1, 5) {
				if(j == 3) continue;
				if(num[j-1] != num[j]) return;
			}
			//FORS(j, 7) pf("%I64d ", num[j]); nl;
			if(num[2]*2 != num[3]) return;
			if(num[2]*3 != num[6]) return;
		}
		puts("YES");
		FORS(i, 8) {
			FORS(j, 3) pf("%d ", a[i][j]);
			nl;
		}
		done = 1;
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
	if(!done) puts("NO");
	return 0;
}
