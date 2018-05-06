
#include <bits/stdc++.h>

using namespace std;

string a, b;
int cnt[10];
int ans[20];

// return 1 if can
bool dfs(int now, bool free = 0) {
  if (now == a.size()) return 1;
  if (free) {
    for (int i = now; i < a.size(); i++) {
      for (int j = 9; j >= 0; j--) {
        if (cnt[j]) {
          ans[i] = j;
          cnt[j]--;
          break;
        }
      }
    }
    return 1;
  }
  if (cnt[b[now] - '0']) {
    cnt[b[now] - '0']--;
    ans[now] = b[now] - '0';
    if (dfs(now + 1)) return 1;
    cnt[b[now] - '0']++;
  }
  for (int j = b[now] - '0' - 1; j >= 0; j--) {
    if (cnt[j]) {
      cnt[j]--;
      ans[now] = j;
      if (dfs(now + 1, 1)) return 1;
      cnt[j]++;
    }
  }
  return 0;
}

int main() {
  cin >> a >> b;
  if (a.size() < b.size()) {
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    cout << a << endl;
    return 0;
  }
  for (int i = 0; i < a.size(); i++) cnt[a[i] - '0']++;
  dfs(0);
  for (int i = 0; i < a.size(); i++) printf("%d", ans[i]);
  return 0;
}
