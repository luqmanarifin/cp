#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

vector<string> daf;
string temp;

int main(void)
{
	ios_base::sync_with_stdio(false);
	int n, i, j;
	cin >> n;
	cin.ignore();
	while(n--) {
		getline(cin, temp);
		//cout << temp << endl;
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		daf.push_back(temp);
		i = daf.size() - 1;
		while(i && daf[i - 1] > daf[i]) {
			swap(daf[i - 1], daf[i]);
			i--;
		}
		pf("%d\n", i + 1);
	}
	
	return 0;
}
