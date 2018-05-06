#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
map<int, int> last, dp;
int back[N];

vector<int> pt;

void print(int now) {
  if (now == -1) return;
  print(back[now]);
  pt.push_back(now);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  memset(back, -1, sizeof(back));
  for (int i = 0; i < n; i++) {
    if (last.count(a[i] - 1)) {
      back[i] = last[a[i] - 1];
      dp[a[i]] = dp[a[i] - 1] + 1;
    } else {
      dp[a[i]] = 1;
    }
    last[a[i]] = i;
  }
  int ans = -1, at = -1;
  for (auto it : dp) {
    if (it.second > ans) {
      ans = it.second;
      at = last[it.first];
    }
  }
  printf("%d\n", ans);
  print(at);
  for (auto it : pt) printf("%d ", it + 1);

  return 0;
}
