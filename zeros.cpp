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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int a, b, a0, b0;

int main(void)
{
	char A[15], B[15];
	sf("%s %s", A, B);
	int alen = strlen(A);
	int blen = strlen(B), i;
	FORS(i, alen) {
		a = a*10 + A[i] - '0';
		if(A[i] != '0')
			a0 = a0*10 + A[i] - '0';
	}
	FORS(i, blen) {
		b = b*10 + B[i] - '0';
		if(B[i] != '0')
			b0 = b0*10 + B[i] - '0';
	}
	int c = a + b;
	vector<int> C;
	while(c) {
		C.push_back(c % 10);
		c /= 10;
	}
	int c0 = 0;
	FORM(i, C.size())
		if(C[i])
			c0 = c0*10 + C[i];
	if(a0 + b0 == c0) puts("YES");
	else puts("NO");
	return 0;
}
