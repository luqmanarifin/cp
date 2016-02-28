#include <bits/stdc++.h>

/**
 * Good Bye 2014
 * Problem : C
 * Luqman Arifin (kadalbonek)
 * بسم الله الرحمان الرحيم
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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> books;
vector<int> urut;
int w[1005];
int a[1005];
bool done[1005];

int main(void)
{
	int i, j, n, m;
	sf("%d %d", &n, &m);
	FOR(i, 1, n) sf("%d", &w[i]);
	FORS(i, m) {
		sf("%d", &a[i]);
		if(!done[a[i]]) {
			done[a[i]] = 1;
			urut.push_back(a[i]);
		}
	}
	reverse(urut.begin(), urut.end());
	books = urut;
	int ans = 0;
	FORS(i, m) {
		reset(done, 0);
		int sz = books.size();
		FORM(j, sz) {
			if(books[j] == a[i]) {
				books.push_back(a[i]);
				break;
			}
			if(!done[books[j]]) {
				done[books[j]] = 1;
				ans += w[books[j]];
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
