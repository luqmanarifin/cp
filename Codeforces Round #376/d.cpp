#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

set<pair<int, int>> all;
vector<int> w[N];
int n, c;

void insert(int l, int r) {
  //puts("insert");
  vector<pair<int, int>> rem;
  auto it = all.lower_bound({l, 4 * N});
  if (it != all.begin()) it--;
  while (it != all.end()) {
    if (it->second + 1 < l) continue;
    if (r + 1 < it->first) break;
    rem.push_back(*it);
    l = min(l, it->first);
    r = max(r, it->second);
    ++it;
  }
  for (auto it : rem) all.erase(it);
  all.insert({l, r});
  //puts("insert done");
}

void dfs(int l, int r, int at) {
  //printf("enter %d %d %d\n", l, r, at);
  for (int i = l; i <= r; i++) {
    if (w[i].size() <= at) {
      l = i + 1;
    } else {
      break;
    }
  }
  //puts("sip");
  for (int i = l; i <= r; i++) if (w[i].size() <= at) {
    puts("-1");
    exit(0);
  }
  //puts("good");
  if (l >= r) return;
  //puts("masuk");
  long long mini = w[l][at];
  long long maks = mini;
  //puts("acc");
  for (int i = l; i <= r; i++) {
    if (w[i][at] < maks % c) {
      maks = (maks / c + 1) * c + w[i][at];
    } else {
      maks = (maks / c) * c + w[i][at];
    }
  }
  //puts("lea");
  if (mini + c <= maks) {
    puts("-1");
    exit(0);
  }
  if (mini < maks) insert(mini, maks);
  for (int i = l; i <= r; i++) {
    int j = i;
    //printf("iter %d %d %d\n", l, r, at);
    while (j + 1 <= r && w[j][at] == w[j + 1][at]) j++;
    //printf("iter %d %d %d: %d %d\n", l, r, at, i, j);
    dfs(i, j, at + 1);
    i = j;
  }
}

int main() {
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    while (v--) {
      int a;
      scanf("%d", &a);
      w[i].push_back(--a);
    }
  }
  dfs(0, n - 1, 0);
  //puts("done dfs");
  int ans = 0;
  //for (auto it : all) printf("sem %d %d\n", it.first, it.second);
  if (!all.empty()) {
    auto be = all.begin();
    auto en = all.rbegin();
    int l = be->first;
    int r = en->second;
    if (l + c <= r) {
      puts("-1");
      exit(0);
    }
    ans = (c - l) % c;
  }
  cout << ans << endl;
  return 0;
}