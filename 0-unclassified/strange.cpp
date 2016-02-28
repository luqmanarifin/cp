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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool done[15];
vector<int> ans, temp;

int at(int a) {
	if(a == 0) return 0;
	if(a < 10) return 1;
	if(10 <= a && a <= 99 && a % 10 == 0) return 2;
	if(a == 100) return 3;
	return -1;
}

int main(void)
{
	//open;
	int a, n, i, j;
	sf("%d", &n);
	while(n--) {
		sf("%d", &a);
		if(at(a) != -1 && !done[at(a)]) ans.push_back(a), done[at(a)] = 1;
		else temp.push_back(a);
	}
	if((ans.empty() || (ans.size() == 1 && ans[0] == 0) || done[1] + done[2] == 0) && temp.size()) {
		ans.push_back(temp[0]);
	}
	cout << ans.size() << endl;
	for(auto it : ans) pf("%d ", it); nl;
	
	//close;
	return 0;
}
