#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], ma[N], b[N], p[N];
vector<int> q[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < m; i++) scanf("%d", b + i);
  for (int i = 0; i < m; i++) scanf("%d", p + i);
  ma[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    ma[i] = max(ma[i + 1], a[i]);
  }
  for (int i = 0; i < m; i++) {
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (ma[mid] >= b[i]) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    if (ma[l] >= b[i]) {
      q[l].push_back(p[i]);
    }
  }
  long long sum = 0;
  priority_queue<int> pq;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    for (auto it : q[i]) {
      if (sum >= it) {
        pq.push(it);
        sum -= it;
      } else {
        if (!pq.empty() && pq.top() > it) {
          sum += pq.top();
          pq.pop();
          sum -= it;
          pq.push(it);
        }
      }
    }
  }
  cout << pq.size() << endl;
  return 0;
}