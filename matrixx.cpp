#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int dx[N * N], dy[N * N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        int a;
        scanf("%d", &a);
        dx[a] = i, dy[a] = j;
      }
    }
    int ans = 0;
    for(int i = 2; i <= n * n; i++) {
      ans += abs(dx[i] - dx[i - 1]) + abs(dy[i] - dy[i - 1]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
