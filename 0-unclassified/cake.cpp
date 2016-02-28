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

char a[15][15];
bool done[15];

int main(void)
{
	int x, y, i, j, ans = 0;
	sf("%d %d", &x, &y);
	FORS(i,x) cin >> a[i];
	FORS(i,x) {
		int temp = 0;
		FORS(j,y) {
			if(a[i][j] == '.') temp++;
			else goto next;
		}
		done[i] = true;
		ans += temp;
		next:;
	}
	
	FORS(i,y) {
		int temp = 0;
		FORS(j,x) {
			if(a[j][i] == '.' && !done[j]) temp++;
			else if(a[j][i] == 'S') goto next2;
		}
		ans += temp;
		next2:;
	}
	
	cout << ans << endl;
	
	return 0;
}