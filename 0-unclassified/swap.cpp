#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(cok,n) memset(cok, n, sizeof(cok))
#define open freopen("input2.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

bool is[maxn];
int pos[maxn], num[maxn], dif[maxn];
vector<pair<int,int> > ans;
vector<int> prime;

int main(void)
{
	//open;
	int i, j, n;
	reset(is, true);
	is[1] = false;
	sf("%d", &n);
	
	// generating prime number with sieve eratosthenes
	FOR(i,2,n)
		if(is[i]) {
			prime.push_back(i);
			if(1LL*i*i <= n)
				for(j = i*i; j <= n; j += i)
					is[j] = false;
		}
	
	FOR(i,1,n) {
		sf("%d", &num[i]);
		pos[num[i]] = i;
		dif[num[i]] = abs(num[i] - i);
	}
	
	FOR(i,1,n)
		if(dif[i]) {
			// searching prime number near dif[i] to swap
			j = dif[i];
			while(j) {
				int l = 0, r = prime.size()-1;
				while(l < r) {
					int mid = (l + r + 1) >> 1;
					if(j+1 < prime[mid]) r = mid - 1;
					else l = mid;
				}
				//pf("%d %d %d",i,j,prime[l]); nl;
				j -= prime[l]-1;
				ans.push_back( mp(i+j, i+j+prime[l]-1) );
				swap(num[i+j], num[i+j+prime[l]-1]);
				swap(pos[num[i+j]], pos[num[i+j+prime[l]-1]]);
				dif[num[i+j+prime[l]-1]] = abs(i+j+prime[l]-1 - num[i+j+prime[l]-1]);
			}
		}
	
	cout << ans.size() << endl;
	if(ans.size())
		FORS(i, ans.size())
			pf("%d %d\n", ans[i].first, ans[i].second);
	//close;
	return 0;
}
