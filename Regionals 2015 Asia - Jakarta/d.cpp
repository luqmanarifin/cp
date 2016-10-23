#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> pos[5];
vector<int> ans;
int a[N], n, l, r;

bool take(int u) {
  if (pos[u + 2].size() && ans.size() + 1 <= r) {
    ans.push_back(pos[u + 2].back());
    pos[u + 2].pop_back();
    return 1;
  }
  return 0;
}

bool take_pair(int u, int v) {
  if (pos[u + 2].size() && pos[v + 2].size() && ans.size() + 2 <= r) {
    take(u);
    take(v);
    return 1;
  }
  return 0;
}

bool bisa_positif() {
  int negatif = pos[0].size() + pos[1].size();
  int positif = pos[3].size() + pos[4].size();
  int pair_negatif = min(negatif / 2, r / 2);
  return pair_negatif * 2 + positif >= l;
}

bool bisa_nol() {
  return pos[2].size() > 0;
}

void positif() {
  while (take_pair(-2, -2));
  while (pos[4].size() > 1) take(2);
  take_pair(-2, -1);
  take(2);
  while (take_pair(-1, -1));
  while (take(1));
}

void nol() {
  take(0);
  for (int i = -2; i <= 2; i++) while (take(i));
}

void negatif() {
  while (take(-1));
  while (take(1));
  while (take(-2));
  while (take(2));
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < 5; i++) pos[i].clear();
    ans.clear();
    
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      pos[a[i] + 2].push_back(i);
    }
    printf("Case #%d:\n", tt);
    if (bisa_positif()) {
      positif();
    } else if (bisa_nol()) {
      nol();
    } else {
      negatif();
    }
    //assert(l <= ans.size() && ans.size() <= r);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
      if (i) printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }

  return 0;
}
