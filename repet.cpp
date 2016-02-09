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
const int N = 4e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

char t[N];

int main(void)
{
	int i, n, now = 1;
	sf("%d", &n);
	t[1] = 'a';
	while(true) {
		i = 1;
		while(i < now) {
			if(now+i > n) goto PRINT;
			t[now+i] = t[i];
			i++;
		}
		if(now+i > n) goto PRINT;
		t[now+i] = (char) t[i] + 1;
		now *= 2;
	}
	PRINT:;
	puts(&t[1]);
	return 0;
}
