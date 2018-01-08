#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

vector<int> edge[N];
int leaf[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int v;
    scanf("%d", &v);
    edge[v].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    bool leaf = (edge[i].empty());
    int leafChild = 0;
    for (auto it : edge[i]) {
      if (edge[it].empty()) {
        leafChild++;
      }
    }
    if (!leaf && leafChild < 3) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}
