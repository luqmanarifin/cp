#include <bits/stdc++.h>

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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[1000];
int n,i, ans = 1;
char tc;

int find(char tc){
	int sum = 0, bef = -1;
	FORS(i,n){
		if(s[i] == tc) {
			// pf("%c %d %d\n", s[i],i,bef);
			if(bef == -1) { bef = i; sum++; }
			else if((i-bef)%2==1) {
				sum++;
				bef = i;
			}
			// pf("%d\n", sum);
		}	
	}
	return sum;
}

int main()
{
	sf("%s", &s);
	n = strlen(s);
	FOR(tc,'A','Z')
		ans = max(ans, find(tc));
	cout << ans << endl;
	return 0;
}