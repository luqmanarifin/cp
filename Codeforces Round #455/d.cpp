#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];
int bef[N], aft[N], n;

void remove(int i) {
  bef[aft[i]] = bef[i];
  aft[bef[i]] = aft[i];
}

bool ok(int i) {
  if (i < 1 || n < i) return 0;
  if (aft[i] <= n && s[i] != s[aft[i]]) return 1;
  if (bef[i] >= 1 && s[i] != s[bef[i]]) return 1;
  return 0;
}

int main() {
  for (int i = 0; i < N; i++) {
    bef[i] = i - 1;
    aft[i] = i + 1;
  }
  
  scanf("%s", s + 1);
  n = strlen(s + 1);
  set<int> need;
  for (int i = 1; i <= n; i++) {
    if (ok(i)) {
      need.insert(i);
    }
  }
  int ans = 0;
  while (!need.empty()) {
    ans++;
    set<int> nex;
    for (auto it : need) remove(it);
    for (auto it : need) {
      if (ok(bef[it]) && !need.count(bef[it])) {
        nex.insert(bef[it]);
      }
      if (ok(aft[it]) && !need.count(aft[it])) {
        nex.insert(aft[it]);
      }
    }
    need = nex;
  }
  cout << ans << endl;
  return 0;
}
