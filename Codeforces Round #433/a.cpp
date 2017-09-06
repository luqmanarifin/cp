#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

long long c[N];
int ans[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", c + i);
  }
  priority_queue<pair<long long, int>> pq;
  for (int i = 1; i <= k; i++) {
    pq.emplace(c[i], i);
  }
  long long cost = 0;
  for (int i = k + 1; i <= k + n; i++) {
    if (i <= n) {
      pq.emplace(c[i], i);
    }
    auto it = pq.top();
    pq.pop();
    cost += it.first * (i - it.second);
    ans[it.second] = i;
  }
  cout << cost << endl;
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}