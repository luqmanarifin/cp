#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N];
int to[N];

int ans[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    to[v]++;
  }
  priority_queue<int> pq;
  for (int i = 1; i <= n; i++) {
    if (to[i] == 0) {
      pq.push(-i);
    }
  } 
  int cnt = 0;
  while (!pq.empty()) {
    int now = -pq.top();
    pq.pop();
    cnt++;
    ans[now] = cnt;
    for (auto it : edge[now]) {
      to[it]--;
      if (to[it] == 0) {
        pq.push(-it);
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
