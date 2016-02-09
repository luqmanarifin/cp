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

int num[5];
vector<int> ans;


void tahap_1(int a, int b, int c, int d) {
		ans.push_back( ( (a + b) + c) + d);
		ans.push_back( ( (a + b) + c) - d);
		ans.push_back( ( (a + b) + c) * d);
		ans.push_back( ( (a + b) - c) + d);
		ans.push_back( ( (a + b) - c) - d);
		ans.push_back( ( (a + b) - c) * d);
		ans.push_back( ( (a + b) * c) + d);
		ans.push_back( ( (a + b) * c) - d);
		ans.push_back( ( (a + b) * c) * d);
		
		ans.push_back( ( (a - b) + c) + d);
		ans.push_back( ( (a - b) + c) - d);
		ans.push_back( ( (a - b) + c) * d);
		ans.push_back( ( (a - b) - c) + d);
		ans.push_back( ( (a - b) - c) - d);
		ans.push_back( ( (a - b) - c) * d);
		ans.push_back( ( (a - b) * c) + d);
		ans.push_back( ( (a - b) * c) - d);
		ans.push_back( ( (a - b) * c) * d);
		
		ans.push_back( ( (a * b) + c) + d);
		ans.push_back( ( (a * b) + c) - d);
		ans.push_back( ( (a * b) + c) * d);
		ans.push_back( ( (a * b) - c) + d);
		ans.push_back( ( (a * b) - c) - d);
		ans.push_back( ( (a * b) - c) * d);
		ans.push_back( ( (a * b) * c) + d);
		ans.push_back( ( (a * b) * c) - d);
		ans.push_back( ( (a * b) * c) * d);
}

void tahap_2(int a, int b, int c, int d) {
		ans.push_back( (a + b) + (c + d) );
		ans.push_back( (a + b) + (c - d) );
		ans.push_back( (a + b) + (c * d) );
		ans.push_back( (a + b) - (c + d) );
		ans.push_back( (a + b) - (c - d) );
		ans.push_back( (a + b) - (c * d) );
		ans.push_back( (a + b) * (c + d) );
		ans.push_back( (a + b) * (c - d) );
		ans.push_back( (a + b) * (c * d) );
		
		ans.push_back( (a - b) + (c + d) );
		ans.push_back( (a - b) + (c - d) );
		ans.push_back( (a - b) + (c * d) );
		ans.push_back( (a - b) - (c + d) );
		ans.push_back( (a - b) - (c - d) );
		ans.push_back( (a - b) - (c * d) );
		ans.push_back( (a - b) * (c + d) );
		ans.push_back( (a - b) * (c - d) );
		ans.push_back( (a - b) * (c * d) );
		
		ans.push_back( (a * b) + (c + d) );
		ans.push_back( (a * b) + (c - d) );
		ans.push_back( (a * b) + (c * d) );
		ans.push_back( (a * b) - (c + d) );
		ans.push_back( (a * b) - (c - d) );
		ans.push_back( (a * b) - (c * d) );
		ans.push_back( (a * b) * (c + d) );
		ans.push_back( (a * b) * (c - d) );
		ans.push_back( (a * b) * (c * d) );
}

void tahap_3(int a, int b, int c, int d) {
		ans.push_back( ( a + (b + c) ) + d);
		ans.push_back( ( a + (b + c) ) - d);
		ans.push_back( ( a + (b + c) )* d);
		ans.push_back( ( a + (b - c) )+ d);
		ans.push_back( ( a + (b - c) )- d);
		ans.push_back( ( a + (b - c) )* d);
		ans.push_back( ( a + (b * c) )+ d);
		ans.push_back( ( a + (b * c) )- d);
		ans.push_back( ( a + (b * c) )* d);
		
		ans.push_back( ( a - (b + c) )+ d);
		ans.push_back( ( a - (b + c) )- d);
		ans.push_back( ( a - (b + c) )* d);
		ans.push_back( ( a - (b - c) )+ d);
		ans.push_back( ( a - (b - c) )- d);
		ans.push_back( ( a - (b - c) )* d);
		ans.push_back( ( a - (b * c) )+ d);
		ans.push_back( ( a - (b * c) )- d);
		ans.push_back( ( a - (b * c) )* d);
		
		ans.push_back( ( a * (b + c) )+ d);
		ans.push_back( ( a * (b + c) )- d);
		ans.push_back( ( a * (b + c) )* d);
		ans.push_back( ( a * (b - c) )+ d);
		ans.push_back( ( a * (b - c) )- d);
		ans.push_back( ( a * (b - c) )* d);
		ans.push_back( ( a * (b * c) )+ d);
		ans.push_back( ( a * (b * c) )- d);
		ans.push_back( ( a * (b * c) )* d);
}

void tahap_4(int a, int b, int c, int d) {
		ans.push_back( a + ((b + c)  + d));
		ans.push_back(  a + ((b + c) - d));
		ans.push_back(  a + ((b + c) * d));
		ans.push_back(  a + ((b - c) + d));
		ans.push_back(  a + ((b - c) - d));
		ans.push_back(  a + ((b - c) * d));
		ans.push_back(  a + ((b * c) + d));
		ans.push_back(  a + ((b * c) - d));
		ans.push_back(  a + ((b * c) * d));
		
		ans.push_back(  a - ((b + c) + d));
		ans.push_back(  a - ((b + c) - d));
		ans.push_back(  a - ((b + c) * d));
		ans.push_back(  a - ((b - c) + d));
		ans.push_back(  a - ((b - c) - d));
		ans.push_back(  a - ((b - c) * d));
		ans.push_back(  a - ((b * c) + d));
		ans.push_back(  a - ((b * c) - d));
		ans.push_back(  a - ((b * c) * d));
		
		ans.push_back(  a * ((b + c) + d));
		ans.push_back(  a * ((b + c) - d));
		ans.push_back(  a * ((b + c) * d));
		ans.push_back(  a * ((b - c) + d));
		ans.push_back(  a * ((b - c) - d));
		ans.push_back(  a * ((b - c) * d));
		ans.push_back(  a * ((b * c) + d));
		ans.push_back(  a * ((b * c) - d));
		ans.push_back(  a * ((b * c) * d));
}

void tahap_5(int a, int b, int c, int d) {
		ans.push_back( a + (b + (c + d) ));
		ans.push_back( a + (b + (c - d) ));
		ans.push_back( a + (b + (c * d) ));
		ans.push_back( a + (b - (c + d) ));
		ans.push_back( a + (b - (c - d) ));
		ans.push_back( a + (b - (c * d) ));
		ans.push_back( a + (b * (c + d) ));
		ans.push_back( a + (b * (c - d) ));
		ans.push_back( a + (b * (c * d) ));
		
		ans.push_back( a - (b + (c + d) ));
		ans.push_back( a - (b + (c - d) ));
		ans.push_back( a - (b + (c * d) ));
		ans.push_back( a - (b - (c + d) ));
		ans.push_back( a - (b - (c - d) ));
		ans.push_back( a - (b - (c * d) ));
		ans.push_back( a - (b * (c + d) ));
		ans.push_back( a - (b * (c - d) ));
		ans.push_back( a - (b * (c * d) ));
		
		ans.push_back( a * (b + (c + d) ));
		ans.push_back( a * (b + (c - d) ));
		ans.push_back( a * (b + (c * d) ));
		ans.push_back( a * (b - (c + d) ));
		ans.push_back( a * (b - (c - d) ));
		ans.push_back( a * (b - (c * d) ));
		ans.push_back( a * (b * (c + d) ));
		ans.push_back( a * (b * (c - d) ));
		ans.push_back( a * (b * (c * d) ));
}

int main(void)
{
	int t, i, op;
	sf("%d", &t);
	while(t--) {
		ans.clear();
		int a[4];
		FORS(i, 4) sf("%d", &a[i]);
		int tt = 24;
		while(tt--) {
			tahap_1(a[0], a[1], a[2], a[3]);
			tahap_2(a[0], a[1], a[2], a[3]);
			tahap_3(a[0], a[1], a[2], a[3]);
			tahap_4(a[0], a[1], a[2], a[3]);
			tahap_5(a[0], a[1], a[2], a[3]);
			next_permutation(a, a + 4);
		}
		
		sort(ans.begin(), ans.end());
		ans.resize(distance(ans.begin(), unique(ans.begin(), ans.end())));
		pf("%d\n", ans.size());
		FORS(i, ans.size()) {
			pf("%d ", ans[i]);
		}
		nl;
	}
	
	return 0;
}
