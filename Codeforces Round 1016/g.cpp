#include <bits/stdc++.h>

using namespace std;

const int MAX = 6500000;
const int N = 2e5 + 5;

struct Node {
  int child[2];
  int val;
};

Node node[MAX];
int node_max;

int create() {
  node_max++;
  node[node_max].child[0] = 0;
  node[node_max].child[1] = 0;
  node[node_max].val = -1;
  return node_max;
}

void dfs(int cur, int x, int at) {
  for (int i = 30; i >= 0; i--) {
    int p = ((x & (1 << i))? 1 : 0);
    if (node[cur].child[p] == 0) {
      node[cur].child[p] = create();
    }
    cur = node[cur].child[p];
    node[cur].val = max(node[cur].val, at);
  }
}

int find(int cur, int x, int k) {
  int ans = -1, out = 0;
  for (int i = 30; i >= 0; i--) {
    int px = ((x & (1 << i))? 1 : 0);
    int pk = ((k & (1 << i))? 1 : 0);
    if (pk == 0) {
      int c = node[cur].child[px^1];
      if (c != 0) {
        ans = max(ans, node[c].val);
      }
    }
    cur = node[cur].child[px^pk];
    if (cur == 0) {
      out = 1;
      break;
    }
  }
  if (!out) {
    ans = max(ans, node[cur].val);
  }
  return ans;
}

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    node_max = 0;
    int root = create();

    int n, k;
    scanf("%d %d", &n, &k);
    int nearest = N;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      dfs(root, a[i], i);
      int best = find(root, a[i], k);
      if (best != -1) {
        nearest = min(nearest, i - best + 1);
      }
    }
    if (nearest == N) {
      nearest = -1;
    }
    printf("%d\n", nearest);
  }

  return 0;
}
