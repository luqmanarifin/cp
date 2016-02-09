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

const LL mod = 1e9 + 7;
const LL inf = 4e18;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

char a[20];
int k;

int main(void)
{
	sf("%s %d", a, &k);
	int n = strlen(a), i, j;
	if(!k) {puts(a); return 0;}
	FORS(i,n-1) {
		int val = 0, pos = i;
		FOR(j,i+1,min(n-1, i+k)) {
			if(a[j] - a[i] > val) {
				val = a[j] - a[i];
				pos = j;
			}
		}
		FORD(j,pos,i+1) {
			swap(a[j], a[j-1]);
			k--;
		}
		if(!k) break;
	}
	
	puts(a);
	return 0;
}
