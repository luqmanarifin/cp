#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int n, h, f[N];
double p, dp[2][N][N][2];
int lf[N], rg[N];

double find(int a, int l, int r, int b) {
  if(l > r) return 0;
  if(dp[a][l][r][b] > -0.5) return dp[a][l][r][b];
  double& ret = dp[a][l][r][b] = 0;
  
  int lef = (a? min(h, abs(f[l] - (f[l - 1] + h))) : min(h, abs(f[l] - f[l - 1])));
  int rig = (b? min(h, abs(f[r] - (f[r + 1] - h))) : min(h, abs(f[r] - f[r + 1])));
  
  ret += (lef + find(0, l + 1, r, b)) * p;
  ret += (rig + find(a, l, r - 1, 0)) * (1 - p);
  
  int at = min(r, lf[l]);
  if(at == r) {
    ret += (f[at] - f[l] + rig) * (1 - p);
  } else {
    ret += ((f[at] - f[l] + h) + find(abs(f[at + 1] - f[at]) < 2*h, at + 1, r, b)) * (1 - p);
  }
  
  at = max(l, rg[r]);
  if(at == l) {
    ret += (f[r] - f[at] + lef) * p;
  } else {
    ret += ((f[r] - f[at] + h) + find(a, l, at - 1, abs(f[at - 1] - f[at]) < 2*h)) * p;
  }
  
  ret /= 2;
  return ret;
}

int main() {
  scanf("%d %d %lf", &n, &h, &p);
  for(int i = 1; i <= n; i++) {
    scanf("%d", f + i);
  }
  sort(f + 1, f + 1 + n);
  for(int i = 1; i <= n; i++) {
    int j = i;
    while(j + 1 <= n && abs(f[j + 1] - f[j]) < h) j++;
    lf[i] = j;
  }
  for(int i = n; i >= 1; i--) {
    int j = i;
    while(j - 1 <= n && abs(f[j - 1] - f[j]) < h) j--;
    rg[i] = j;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = i; j <= n; j++) {
      for(int k = 0; k < 2; k++) {
        for(int l = 0; l < 2; l++) {
          dp[k][i][j][l] = -1;
        }
      }
    }
  }
  f[n + 1] = 1e9;
  f[0] = -1e9;
  printf("%.18f\n", find(0, 1, n, 0));
  return 0;
}