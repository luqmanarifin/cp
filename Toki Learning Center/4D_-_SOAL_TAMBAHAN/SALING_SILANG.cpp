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

char s[105][105], t[105];

int main(void)
{
	int n, m, i, j, k; 
	sf("%d %d", &n, &m);
	FOR(i, 1, n) FOR(j, 1, m) {
		char c;
		sf("%c", &c);
		while(!('A' <= c && c <= 'Z')) sf("%c", &c);
		s[i][j] = c;
	}
	int q;
	sf("%d", &q);
	while(q--) {
		sf("%s", t);
		pf("%s ", &t);
		int len = strlen(t);
		bool ok = 0;
		FOR(i, 1, n) FOR(j, 1, m) {
			bool valid;
			int ii, jj;
			if(j + len - 1 <= m) {
				valid = 1;
				FORS(k, len) if(t[k] != s[i][j + k]) valid = 0;
				if(valid) {
					ok = 1;
					goto NEXT;
				}
			}
			if(j - len + 1 >= 1) {
				valid = 1;
				FORS(k, len) if(t[k] != s[i][j - k]) valid = 0;
				if(valid) {
					ok = 1;
					goto NEXT;
				}
			}
			if(i + len - 1 <= n) {
				valid = 1;
				FORS(k, len) if(t[k] != s[i + k][j]) valid = 0;
				if(valid) {
					ok = 1;
					goto NEXT;
				}
			}
			if(i - len + 1 >= 1) {
				valid = 1;
				FORS(k, len) if(t[k] != s[i - k][j]) valid = 0;
				if(valid) {
					ok = 1;
					goto NEXT;
				}
			}
			
			if(i + len - 1 <= n && j + len - 1 <= m) {
				valid = 1;
				FORS(k, len) if(t[k] != s[i + k][j + k]) valid = 0;
				if(valid) {
					ok = 1;
					goto NEXT;
				}
			}
			if(i - len + 1 >= 1 && j - len + 1 >= 1) {
				valid = 1;
				FORS(k, len) if(t[k] != s[i - k][j - k]) valid = 0;
				if(valid) {
					ok = 1;
					goto NEXT;
				}
			}
			if(j + len - 1 <= m && i - len + 1 >= 1) {
				valid = 1;
				FORS(k, len) if(t[k] != s[i - k][j + k]) valid = 0;
				if(valid) {
					ok = 1;
					goto NEXT;
				}
			}
			if(j - len + 1 >= 1 && i + len - 1 <= n) {
				valid = 1;
				FORS(k, len) if(t[k] != s[i + k][j - k]) valid = 0;
				if(valid) {
					ok = 1;
					goto NEXT;
				}
			}
		}
		NEXT:;
		puts(ok? "Y" : "T");
	}
	
	return 0;
}
