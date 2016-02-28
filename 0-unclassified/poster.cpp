#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = b; i >= a; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n-i; i >= 0; --i)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

int main(void)
{
	int n, k, i;
	char word[105];
	cin >> n >> k >> word;
	int a = n - k;
	int b = k - 1;
	if(a < b) {
		FORS(i,a) puts("RIGHT");
		FORD(i,1,n-1) {
			pf("PRINT "); pf("%c", word[i]); nl;
			puts("LEFT");
		}
		pf("PRINT "); pf("%c", word[0]); nl;
	} else {
		FORS(i,b) puts("LEFT");
		FOR(i,0,n-2) {
			pf("PRINT "); pf("%c", word[i]); nl;
			puts("RIGHT");
		}
		pf("PRINT "); pf("%c", word[n-1]); nl;
	}
	
	return 0;
}