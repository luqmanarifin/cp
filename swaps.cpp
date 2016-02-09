#include <bits/stdc++.h>

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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const int inf = -1 << 30;

int n, k, a[205];
int dp[205][3][12][12];

int go(int id, int sta, int in, int out) {
	if(id == n + 1) {
		if(in == out && sta)
			return 0;
		return inf;
	}
	else if(dp[id][sta][in][out] != -1)
		return dp[id][sta][in][out];
		
	int cur = inf;
	if(sta == 1) {
		cur = max(cur, go(id+1, 1, in, out) + a[id]);	// nambah biasa
		if(in < k)
			cur = max(cur, go(id+1, 1, in+1, out));		// dalem di skip
		cur = max(cur, go(id+1, 2, in, out));				// berhenti
	}
	else if(sta == 0) {
		cur = max(go(id+1, 1, in, out) + a[id], go(id+1, 0, in, out));	// array dibuka
		cur = max(cur, go(id+1, 1, in+1, out));								// buka langsung skip
		if(out < k)
			cur = max(cur, a[id] + go(id+1, 0, in, out+1));					// masukin luar
	}
	else if (sta == 2) {
		cur = max(go(id+1, 2, in, out), (out < k)?(go(id+1, 2, in, out+1) + a[id]) : inf);	// masukin luar atau nggak
	}
	return dp[id][sta][in][out] = cur;
}

int main(void)
{
	sf("%d %d", &n, &k);
	reset(dp, -1); int i;
	FOR(i,1,n) sf("%d", &a[i]);
	
	cout << go(1,0,0,0) << endl;
	
	nl;
	
	return 0;
}