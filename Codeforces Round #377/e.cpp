#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N]; // komputer - colokan
int cnt[N], num[N];
map<int, vector<int>> id_comp;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    id_comp[a[i]].push_back(i);
  }
  vector<pair<int, int>> p;
  for (int i = 1; i <= m; i++) {
    scanf("%d", b + i);
    p.emplace_back(b[i], i);
  }
  sort(p.begin(), p.end());
  int c = 0, u = 0;
  for (auto it : p) {
    int val = it.first;
    int id_col = it.second;
    int cur = 0;
    while (1) {
      if (!id_comp[val].empty()) {
        c++;
        u += cur;
        cnt[id_col] = cur;
        num[id_comp[val].back()] = id_col;
        id_comp[val].pop_back();
        break;
      }
      if (val == 1) break;
      cur++;
      val = (val + 1) / 2;
    }
  }
  printf("%d %d\n", c, u);
  for (int i = 1; i <= m; i++) printf("%d ", cnt[i]); printf("\n");
  for (int i = 1; i <= n; i++) printf("%d ", num[i]); printf("\n");
  
  return 0;
}
