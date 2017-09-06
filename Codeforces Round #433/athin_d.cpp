#include <bits/stdc++.h>

using namespace std;

int i,n,j;
int mem[300007][57];
int a[300007],bagi[300007];

int DP(int pos, int sisa) {
	if (pos == n) return 0;
	if (mem[pos][sisa] != -1) return mem[pos][sisa];
	
	int ans = a[pos]+DP(pos+1,min(sisa+bagi[pos],50));
	int pake = min(sisa,a[pos]);
	ans = min(ans,a[pos]-pake+DP(pos+1,sisa-pake));
	return mem[pos][sisa] = ans;
}

int main() {
	scanf("%d",&n);
	for (i=0 ; i<n ; i++) {
		scanf("%d",&a[i]);
		a[i] /= 100;
		bagi[i] = a[i] / 10;
	}
	
	for (i=0 ; i<=n ; i++) {
		for (j=0 ; j<=50 ; j++) {
			mem[i][j] = -1;
		}
	}
	
	printf("%d\n",DP(0,0)*100);
}