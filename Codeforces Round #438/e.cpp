
#include <bits/stdc++.h>

using namespace std;

const int N = 55;

vector<pair<int, int>> edge[N];

vector<pair<int, int>> ada[N];    // child: id - cost
int cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edge[u].emplace_back(v, w);
    edge[v].emplace_back(u, w);
  }
  int s;
  scanf("%d", &s);
  int k;
  scanf("%d", &k);
  while (k--) {
    int v;
    scanf("%d", &v);
    cnt[v]++;
  }
  

  return 0;
}
