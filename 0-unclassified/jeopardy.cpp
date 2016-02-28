#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = b; i >= a; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n-1; i >= 0; --i)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

vector<int> auc;

int main(void)
{
	LL up, down, ans, sum = 0, que[105];
	int n, m, i, x;
	sf("%d %d", &n, &m);
	FOR(i,1,n) {
		cin >> que[i];
		sum += que[i];
	}
	while(m--) {
		sf("%d", &x);
		auc.push_back(que[x]);
		sum -= que[x];
	}
	sort(auc.begin(), auc.end());
	up = sum, down = sum;
	FORS(i,auc.size()) {
		if(up > auc[i])
			up *= 2;
		else
			up += auc[i];
	}
	FORM(i,auc.size()) {
		if(down > auc[i])
			down *= 2;
		else
			down += auc[i];
	}
	cout << max(down, up) << endl;
	
	return 0;
}