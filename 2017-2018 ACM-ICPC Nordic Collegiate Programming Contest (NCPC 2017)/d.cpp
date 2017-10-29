#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int BIG = 1 << 20;
const int inf = 1e9;

char s[N][25];
vector<int> edge[BIG];
int dist[BIG];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int mask = 0; mask < (1 << k); mask++) {
    for (int i = 0; i < k; i++) {
      edge[mask].push_back(mask ^ (1 << i));
    }
  }
  fill(dist, dist + BIG, inf);
  queue<int> q;
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = 0; j < k; j++) {
      if (s[i][j] == '1') {
        cur += (1 << j);
      }
    }
    if (dist[cur] == inf) {
      dist[cur] = 0;
      q.push(cur);
    }
  }
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto it : edge[now]) {
      int cur = dist[now] + 1;
      if (dist[it] > cur) {
        dist[it] = cur;
        q.push(it);
      }
    }
  }
  int best = -1, p = -1;
  for (int i = 0; i < (1 << k); i++) {
    if (dist[i] > best) {
      best = dist[i];
      p = i;
    }
  }
  for (int i = 0; i < k; i++) {
    printf("%d", p % 2);
    p /= 2;
  }
  printf("\n");
  return 0;
}