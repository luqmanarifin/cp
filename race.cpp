#include <bits/stdc++.h>

using namespace std;

const int N = -600000;

int dp[2][310][310];
int asal[310][310];
int i,j,k,n;

void update(int k, int i, int j) {
	int a = max(dp[!(k%2)][i][j-1], dp[!(k%2)][i][j]);
	int b = max(dp[!(k%2)][i-1][j], dp[!(k%2)][i-1][j-1]);
	dp[k%2][i][j] = max(a,b);
}

int main()
{
	for(i = 0; i < 310; ++i)
		for(j = 0; j < 310; ++j) {
			asal[i][j] = N;
			dp[0][i][j] = N;
			dp[1][i][j] = N;
		}
	
	scanf("%d", &n);
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= n; ++j)
			scanf("%d", &asal[i][j]);
		
	dp[0][1][1] = asal[1][1];
	for(k = 3; k <= 2*n; ++k)
		for(i = 1; i <= min(n,k); ++i)
			for(j = i; j <= min(n,k); ++j) {
				update(k, i, j);
				dp[k%2][i][j] += asal[i][k-i];
				if(i != j) dp[k%2][i][j] += asal[j][k-j];
			}

	cout << dp[0][n][n] << endl;
	
	return 0;
}