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
	int i, j, n, len;
	char ans[100005], temp[100005];
	cin >> n;
	cin >> ans; len = strlen(ans);
	FORS(i,n-1) {
		cin >> temp;
		FORS(j,len) {
			if(ans[j] == '*' || ans[j] == temp[j]) continue;
			else if(ans[j] != '?' && ans[j] != '*' && temp[j] == '?')
				continue;
			else if(ans[j] == '?' && temp[j] != '?')
				ans[j] = temp[j];
			else if(ans[j] != '?' && temp[j] != '?')
				ans[j] = '*';
		}
	}
	
	FORS(i,len) {
		if(ans[i] == '?')
			putchar('x');
		else if(ans[i] == '*')
			putchar('?');
		else
			putchar(ans[i]);
	} nl;
	
	return 0;
}