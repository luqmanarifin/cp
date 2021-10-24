#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int VAL = (1 << 13);

vector<int> g[VAL];
int r[VAL];
bool ans[VAL];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < VAL; i++) {
    g[i].push_back(0);
    r[i] = VAL;
  }
  ans[0] = 1;
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    for (auto it : g[v]) {
      int to = v ^ it;
      ans[to] = 1;
      // printf("%d: transferred %d\n", i, to);
      while (r[to] > v) {
        r[to]--;
        if (r[to] > v) {
          g[r[to]].push_back(to);
        }
      }
    }
    g[v].clear();
  }

  vector<int> v;
  for (int i = 0; i < VAL; i++) {
    if (ans[i]) {
      v.push_back(i);
    }
  }
  printf("%d\n", v.size());
  for (int i = 0; i < v.size(); i++) {
    printf("%d%c", v[i], i + 1 == v.size()? '\n' : ' ');
  }

  return 0;
}
