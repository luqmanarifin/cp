
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> el[N];
int par[N];

bool done[N];

void merge(int u, int v) {
  if (par[u] != par[v]) {
    if (el[par[u]].size() < el[par[v]].size()) {
      swap(u, v);
    }
    for (auto it : el[par[v]]) {
      el[par[u]].push_back(it);
      par[it] = par[u];
    }
  }
}

int main() {
  for (int i = 0; i < N; i++) {
    par[i] = i;
    el[i].push_back(i);
  }
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int p;
    scanf("%d", &p);
    merge(i, p);
  }
  vector<int> num;
  for (int i = 1; i <= n; i++) {
    if (!done[par[i]]) {
      num.push_back(el[par[i]].size());
      done[par[i]] = 1;
    }
  }
  sort(num.begin(), num.end());
  if (num.size() >= 2) {
    int i = num.back(); num.pop_back();
    int j = num.back(); num.pop_back();
    num.push_back(i + j);
  }
  long long ans = 0;
  for (auto it : num) ans += 1LL * it * it;
  cout << ans << endl;
  return 0;
}
