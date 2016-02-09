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
#define open freopen("rotation.in","r",stdin); freopen("rotation.out","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

string s[6];
// front, top, bottom, left, rig, rear
// 0		1		2			3		4		5

void x_axes() {
	string temp = s[1];
	s[1] = s[0];
	s[0] = s[2];
	s[2] = s[5];
	s[5] = temp;
}

void y_axes() {
	string temp = s[1];
	s[1] = s[3];
	s[3] = s[2];
	s[2] = s[4];
	s[4] = temp;
}

void z_axes() {
	string temp = s[0];
	s[0] = s[3];
	s[3] = s[5];
	s[5] = s[4];
	s[4] = temp;
}

int main(void)
{
	//open;
	ios_base::sync_with_stdio(false);
	int t, i, j, tt = 0;
	cin >> t;
	while(t--) {
		FORS(i, 6) cin >> s[i];
		int n, ii = 0;
		cin >> n;
		while(n--) {	
			char temp; int op;
			cin >> temp;
			while(temp != 'X' && temp != 'Y' && temp != 'Z') cin >> temp;
			cin >> op;
			op %= 4;
			if(temp == 'X') {	
				FORS(i, op) x_axes();
			} else if(temp == 'Y') {
				FORS(i, op) y_axes(); 
			} else if(temp == 'Z') {
				FORS(i, op) z_axes();
			}
		}
		FORS(i, 6) cout << s[i] << ' ';
		cout << endl;
	}
	//close;
	return 0;
}
