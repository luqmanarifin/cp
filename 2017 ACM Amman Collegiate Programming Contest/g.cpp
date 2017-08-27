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
const LL MAXDIV = 2000000000000LL;
const int N = 2000;
int ar[N + 5];
int n;
LL gcd(LL a, LL b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &ar[i]);
		}
		int res = 0;
		for(int i = 0;i < n; ++i){
			LL tot = 0;
			LL lcm = 1;
			for(int j = i; j < n; ++j){
				tot += ar[j];
				LL lcmdiv = lcm / gcd(lcm, ar[j]);
				if((MAXDIV / lcmdiv) < (LL)ar[j])break;
				else{
					lcm = lcmdiv * ar[j];
				}
				if(tot % lcm == 0) res++;
			}
		}
		printf("%d\n", res);
	}

	return 0;
}