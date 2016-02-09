#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for((i) = (a); (i) <= (b); ++(i))
#define FORD(i,a,b) for((i) = (a); (i) >= (b); --(i))
#define FORS(i,n) for((i) = 0; (i) < (n); ++(i))
#define FORM(i,n) for((i) = (n)-1; (i) >= 0; --(i))
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

int main(void)
{
	char pos[204]; int n, i, a = 0, b = 0, k;
	cin >> n >> pos;
	FORS(i,n)
		if(pos[i] == 'x') a++;
		else b++;
	k = abs(n/2-a);
	pf("%d", k); nl;
	if(a == b) {
		cout << pos;
	} else if(a > b) {
		FORS(i,n) {
			if(pos[i] == 'x' && k) {
				putchar('X');
				k--;
			} else
				putchar(pos[i]);
		}
	} else {
		FORS(i,n) {
			if(pos[i] == 'X' && k) {
				putchar('x');
				k--;
			} else
				putchar(pos[i]);
		}
	} nl;

	return 0;
}