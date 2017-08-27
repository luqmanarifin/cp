#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int INF = 1e9;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int N = 1e5;
LL fact[N + 5];
LL factpow[N + 5];
LL sqr(LL a){
	return (a * a) % MOD;
}
LL modpow(LL a, LL b){
	if(b == 0) return 1;
	if(b == 1) return a % MOD;
	LL tmp = sqr(modpow(a , b >> 1));
	if(b&1) tmp = (tmp * a) % MOD;
	return tmp;
}

void init(){
	fact[0] = fact[1] = 1;
	for(int i = 2;i <= N; ++i){
		fact[i] = (fact[i-1] * i) % MOD;
	}
	for(int i = 0;i <= N; ++i){
		factpow[i] = modpow(fact[i], MOD - 2);
	}
}

LL C(int a, int b){
	return (((fact[a] * factpow[b]) % MOD) * factpow[a - b]) % MOD;
}
int main(){
	init();
	int t;
	scanf("%d", &t);
	while(t--){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%lld\n", (2 * C(a-1, b))% MOD);
	}
	return 0;
}