#include <bits/stdc++.h>

using namespace std;

const int N = 2e7 + 5;
const long long inf = 1e18;

long long d[N];

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);

  for (int i = 0; i < N; i++) d[i] = inf;
  priority_queue<pair<long long, int>> pq;
  d[0] = 0;
  pq.emplace(0, 0);
  while (!pq.empty()) {
    long long cost; int i;
    tie(cost, i) = pq.top();
    cost = -cost;
    pq.pop();
    if (i == n) {
      cout << cost << endl;
      return 0;
    }
    if (i + 1 < N) {
      if (cost + a < d[i + 1]) {
        d[i + 1] = cost + a;
        pq.emplace(-d[i + 1], i + 1);
      }
    }
    if (i - 1 >= 0) {
      if (cost + a < d[i - 1]) {
        d[i - 1] = cost + a;
        pq.emplace(-d[i - 1], i - 1);
      }
    }
    if (i * 2 < N) {
      if (cost + b < d[i * 2]) {
        d[i * 2] = cost + b;
        pq.emplace(-d[i * 2], i * 2);
      }
    }
  }
  assert(0);
  return 0;
}
