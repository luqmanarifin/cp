#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int cnt[N];

int main() {
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    int v;
    scanf("%d", &v);
    cnt[v]++;
    sum += v;
  }
  int ans = sum;
  for (int i = 1; i < N; i++) {
    if (cnt[i] >= 2) {
      int del = min(3, cnt[i]);
      ans = min(ans, sum - del * i);
    }
  }
  cout << ans << endl;
  return 0;
}
