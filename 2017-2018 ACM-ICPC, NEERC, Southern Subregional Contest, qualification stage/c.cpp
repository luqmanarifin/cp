#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double pi = acos(-1);
const int INT = 1e9;
const int N = 3e5;
int n;
LL k;

int main(){
	scanf("%d%lld", &n, &k);
	if(1LL * n * (n-1) / 2 < k){
		puts("Impossible");
		return 0;
	}
	else{
		LL now = 0;
		LL sisak = k;
		int sisan = n;
		while(sisak && sisan){
			if(sisak >= now){
				printf("(");
				sisak -= now;
				sisan--;
				now++;
			}
			else{
				printf(")");
				now--;
			}
		}
		assert(sisak == 0);
		for(int i = 0;i < now; ++i){
			printf(")");
		}
		for(int i = 0;i < sisan; ++i){
			printf("()");
		}
		puts("");
	}
	return 0;
}