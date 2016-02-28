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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

vector<int> start; 
int ans[N], a[N];

int main(void)
{
	int n, i;
	sf("%d", &n);
	FORS(i, n) sf("%d", a + i);
	if(a[0] <= a[1]) start.push_back(0);
	if(a[n-2] >= a[n-1]) start.push_back(n-1);
	FOR(i, 1, n-2)
		if(a[i-1] >= a[i] && a[i] <= a[i+1])
			start.push_back(i);
	FORS(i, start.size()) {
		int now = start[i];
		int j = now+1;
		ans[now] = max(ans[now], 1);
		int cur = 2;
		while(a[j-1] < a[j] && j < n) {
			ans[j] = max(cur, ans[j]);
			cur++;
			j++;
		}
		j = now-1;
		cur = 2;
		while(a[j] > a[j+1] && j >= 0) {
			ans[j] = max(cur, ans[j]);
			cur++;
			j--;
		}
	}
	LL jawab = 0;
	FORS(i, n) {
		cout << ans[i] << ' ';
		if(ans[i])
			jawab += 1LL*ans[i];
		else jawab++;
	} nl;
	cout << jawab << endl;
	return 0;
}
