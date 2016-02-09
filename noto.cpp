#include <bits/stdc++.h>

/**
 * Codeforces Round #265 (Div. 2)
 * Problem : C
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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[1005];
int p, n;

bool valid(int i) {
	if(s[i] >= 'a' + p) return 0;
	if(i >= 1 && s[i] == s[i-1]) return 0;
	if(i > 1 && s[i] == s[i-2]) return 0;
	return 1;
}

int main(void)
{
	int i, j;
	sf("%d %d", &n, &p);
	sf("%s", s);
	FORM(i, n) {
		s[i]++;
		if(s[i]-'a' == p) {
			s[i] = 'a';
		} else break;
	}
	bool aa = 1;
	FORS(i, n) {
		if(s[i] != 'a') {
			aa = 0;
			break;
		}
	}
	if(aa) {
		puts("NO");
		return 0;
	}
	for(i = 0; i < n; i++) {
		while(!valid(i)) {
			while(!valid(i) && s[i] < 'a' + p) {
				//pf("%s %d\n", &s, i);
				s[i]++;
			}
			if(s[i] < 'a' + p) break;
			s[i] = 'a';
			s[i-1]++;
			//pf("%s\n", &s);
			i--;
			if(i < 0) {
				puts("NO");
				return 0;
			}
		}
	}
	pf("%s\n", &s);
	return 0;
}
