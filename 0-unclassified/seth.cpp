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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> s; // {1, 2, 2, 3, 4, 4}
// set with 6 element, indeksnya 0..5

int main(void)
{
	s.push_back(1);
	s.push_back(2);
	s.push_back(2);
	s.push_back(3);
	s.push_back(4);
	s.push_back(4);
	// set is indexed from 0
	int it = lower_bound(s.begin(), s.end(), 2) - s.begin();
	pf("Lower bound of 2 is at %d", it); nl;
	
	it = upper_bound(s.begin(), s.end(), 2)  - s.begin();
	pf("Lower bound of 2 is at %d", it); nl;
	
	it = upper_bound(s.begin(), s.end(), 4) - s.begin();
	pf("Lower bound of 4 is at %d", it); nl;
	
	it = lower_bound(s.begin(), s.end(), 123567) - s.begin();
	pf("Lower bound of 123567 is at %d", it); nl;
	return 0;
}
