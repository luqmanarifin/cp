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

int n, m, x;
int num[105], occ[105], bef, ans = 0;

int main(void)
{
	sf("%d %d %d", &n, &m, &x);
	int i, j = 0;
	bef = 0;
	
	FOR(i,1,n) {
		int a; sf("%d", &a);
		if(a != bef) j++;
		num[j] = a;
		occ[j]++;
		bef = a;
	}
	/*
	FOR(i,1,j) cout << num[i]<<' '; nl;
	FOR(i,1,j) cout << occ[i]<<' '; nl;
	*/
	FOR(i,1,j) {
		if(num[i] == x && occ[i] == 2) {
			int temp = occ[i], ham = 1;
			while(num[i-ham] == num[i+ham] && occ[i-ham]+occ[i+ham] >= 3) {
				if(i-ham < 1 || i+ham > j) break;
				temp += (occ[i-ham] + occ[i+ham]);
				ham++;
			}
			if(temp > ans) ans = temp;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
