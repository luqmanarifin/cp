#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6;
int n;
LL r, p;
LL dp[N + 5];
LL rek(int x){
	if(x == 1) return 0;
	if(dp[x] != -1) return dp[x];
	LL &ret = dp[x] = 0;
	ret = 1LL * (x-1) * p + r;
	int akar = (int)sqrt(x);
	for(int i = 1; i <= akar; ++i){
		int sisa = x % (i + 1);
		int rek_x_1 = x / (i + 1);
		int rek_x_2 = rek_x_1 + (sisa != 0);
		ret = min(ret, p * i + r + max(rek(rek_x_1), rek(rek_x_2)));
	}
	
	return ret;
}
int main(){
	memset(dp, -1, sizeof dp);
	scanf("%d%lld%lld", &n, &r, &p);
	printf("%lld\n", rek(n));
	return 0;
}
