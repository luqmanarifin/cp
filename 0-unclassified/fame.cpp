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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int cnt[26];

void check(string s) {
	int n = s.length(), i, j;
	FORS(i, n) {
		int sm = s[i] - 'a';
		int bg = s[i] - 'A';
		if(0 <= sm && sm <= 25) cnt[sm]++;
		if(0 <= bg && bg <= 25) cnt[bg]++;
	}
}

bool cmp(pair<int,int> l, pair<int,int> r) {
	if(l.first != r.first) return l.first > r.first;
	return l.second > r.second; 
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	int t, tt, i, j;
	cin >> t;
	FOR(tt, 1, t) {
		reset(cnt, 0);
		string s;
		cin >> s;
		while(s != "*") {
			check(s);
			cin >> s;
		}
		vector<pair<int,int> > num;
		FORS(i, 26) {
			if(cnt[i])
				num.push_back(mp(cnt[i], i));
		}
		if(num.size() < 5) {
			cout << "Case " << tt << ": Ineffective" << '\n';
			continue;
		}
		sort(num.begin(), num.end(), cmp);
		int sum = 0;
		FORS(i, 5) {
			sum += num[i].second;
			//pf("%c muncul %d\n", num[i].second + 'A', num[i].first);
		}
		cout << "Case " << tt << ": ";
		cout << (sum > 62? "Effective" : "Ineffective") << '\n';
	}
	
	return 0;
}
