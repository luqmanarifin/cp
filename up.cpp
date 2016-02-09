
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

bool mirror(char a) {
	char list[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
	bool temp = 0; int i;
	FORS(i,11) if(a == list[i]) temp = 1;
	return temp;
}

int main(void)
{
	char x[100005]; cin >> x;
	int i, n = strlen(x);
	FORS(i,n)
		if(!mirror(x[i]) || x[i] != x[n-1-i]) {
			puts("NO");
			return 0;
		}
	puts("YES");

	return 0;
}