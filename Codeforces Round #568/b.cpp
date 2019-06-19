#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char a[N], b[N];
int to[N][26];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s", a, b);
    vector<pair<int, int>> va, vb;
    int na = strlen(a);
    int nb = strlen(b);
    for (int i = 0; i < na; i++) {
      int j = i;
      while (j + 1 < na && a[j + 1] == a[j]) j++;
      va.emplace_back(a[i], j - i + 1);
      i = j;
    }
    for (int i = 0; i < nb; i++) {
      int j = i;
      while (j + 1 < nb && b[j + 1] == b[j]) j++;
      vb.emplace_back(b[i], j - i + 1);
      i = j;
    }
    // for (auto it : va) printf("A %d %d\n", it.first, it.second); printf("\n");
    // for (auto it : vb)printf("B %d %d\n", it.first, it.second);
    bool ok = 1;
    if (va.size() != vb.size()) {
      ok = 0;
    } else {
      for (int i = 0; i < va.size(); i++) {
        if (va[i].first != vb[i].first) {
          ok = 0;
        } 
        if (va[i].second > vb[i].second) {
          ok = 0;
        } 
      }
    }
    puts(ok? "YES" : "NO");
  }

  return 0;
}
