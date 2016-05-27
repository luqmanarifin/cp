#include <bits/stdc++.h>

using namespace std;

const int N = 4096;

int low[N][N], hi[N][N];

int main() {
  vector<int> p;
  for(int i = 0; i < 4; i++) {
    int num;
    scanf("%d", &num);
    p.push_back(num);
  }
  sort(p.begin(), p.end());
  int a = p[0];
  int b = p[1];
  int c = p[2];
  int d = p[3];
  for(int i = 1; i <= a; i++) {
    for(int j = i; j <= b; j++) {
      low[j][i ^ j]++;
    }
  }
  for(int i = 1; i <= c; i++) {
    for(int j = i; j <= d; j++) {
      hi[i][i ^ j]++;
    }
  }
  /*
  for(int i = 1; i < N; i++) {
    for(int j = 0; j < N; j++) {
      low[i][j] += low[i - 1][j];
    }
  }
  */
  for(int i = N - 2; i >= 1; i--) {
    for(int j = 0; j < N; j++) {
      hi[i][j] += hi[i + 1][j];
    }
  }
  long long ans = 0;
  for(int i = 1; i <= b; i++) {
    long long cntlow = 0, cnthi = 0;
    for(int j = 0; j < N; j++) {
      cntlow += low[i][j];
      cnthi += hi[i][j];
    }
    for(int j = 0; j < N; j++) {
      /*
      if(low[i][j] * (cnthi - hi[i][j])) {
        printf("%d %d %lld\n", i, j, low[i][j] * (cnthi - hi[i][j]));
      }
      */
      ans += low[i][j] * (cnthi - hi[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}