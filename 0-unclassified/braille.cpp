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

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char a[500][2];
char b[500][2];
char tc[500];

int trans(int i) {
	if(a[i][0] == '*' && a[i][1] == '.' && b[i][0] == '.' && b[i][1] == '.')
		return 1;
	if(a[i][0] == '*' && a[i][1] == '.' && b[i][0] == '*' && b[i][1] == '.')
		return 2;
	if(a[i][0] == '*' && a[i][1] == '*' && b[i][0] == '.' && b[i][1] == '.')
		return 3;
	if(a[i][0] == '*' && a[i][1] == '*' && b[i][0] == '.' && b[i][1] == '*')
		return 4;
	if(a[i][0] == '*' && a[i][1] == '.' && b[i][0] == '.' && b[i][1] == '*')
		return 5;
	if(a[i][0] == '*' && a[i][1] == '*' && b[i][0] == '*' && b[i][1] == '.')
		return 6;
	if(a[i][0] == '*' && a[i][1] == '*' && b[i][0] == '*' && b[i][1] == '*')
		return 7;
	if(a[i][0] == '*' && a[i][1] == '.' && b[i][0] == '*' && b[i][1] == '*')
		return 8;
	if(a[i][0] == '.' && a[i][1] == '*' && b[i][0] == '*' && b[i][1] == '.')
		return 9;
	return 0;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	int d, i, j;
	string id;
	cin >> d;
	while(d) {
		cin >> id;
		if(id == "S") {
			cin >> tc;
			FORS(i, d) {
				switch(tc[i]) {
					case '0' :
						pf(".* ");
						break;
					case '1' :
						pf("*. ");
						break;
					case '2' :
						pf("*. ");
						break;
					case '3' :
						pf("** ");
						break;
					case '4' : 
						pf("** ");
						break;
					case '5' :
						pf("*. ");
						break;
					case '6' :
						pf("** ");
						break;
					case '7' :
						pf("** ");
						break;
					case '8' : 
						pf("*. ");
						break;
					case '9' :
						pf(".* ");
						break;						
				}
			}
			nl;
			FORS(i, d) {
				switch(tc[i]) {
					case '0' :
						pf("** ");
						break;
					case '1' :
						pf(".. ");
						break;
					case '2' :
						pf("*. ");
						break;
					case '3' :
						pf(".. ");
						break;
					case '4' : 
						pf(".* ");
						break;
					case '5' :
						pf(".* ");
						break;
					case '6' :
						pf("*. ");
						break;
					case '7' :
						pf("** ");
						break;
					case '8' : 
						pf("** ");
						break;
					case '9' :
						pf("*. ");
						break;						
				}
			}
			nl;
			FORS(i, d) pf(".. ");
			nl;
		} else {
			FORS(i, d) {
				cin >> a[i];
			}
			FORS(i, d) {
				cin >> b[i];
			}
			char temp[5];
			FORS(i, d) {
				cin >> temp;
			}
			FORS(i, d) pf("%d", trans(i)); nl;
		}
		cin >> d;
	}
	
	
	return 0;
}
