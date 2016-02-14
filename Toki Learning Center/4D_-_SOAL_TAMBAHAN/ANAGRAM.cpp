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
const int N = 1e4 + 5;

map<string, int> id;
set<string> kamus;
vector<string> ana[N];
int pol;

int main(void)
{
	ios_base::sync_with_stdio(false);
	int i, j, n;
	cin >> n;
	while(n--) {
		string kata, urut;
		cin >> kata;
		urut = kata;
		sort(urut.begin(), urut.end());
		if(kamus.find(urut) == kamus.end()) {
			id[urut] = pol;
			kamus.insert(urut);
			ana[pol].push_back(kata);
			pol++;
		} else {
			ana[id[urut]].push_back(kata);
		}
	}
	int ans = 0;
	string ban = "asu";
	FORS(i, pol) {
		sort(ana[i].begin(), ana[i].end());
		if(ana[i].size() > ans) {
			ans = ana[i].size();
			ban = ana[i][0];
		} else if(ana[i].size() == ans) {
			ban = min(ban, ana[i][0]);
		}
	}
	if(ans == 1) {
		puts("TIDAK ADA");
		return 0;
	}
	pf("%d\n", ans);
	FORS(i, pol) {
		if(ana[i][0] == ban) {
			FORS(j, ana[i].size()) {
				pf("%s\n", ana[i][j].c_str());
			}
		}
	}
	
	return 0;
}
