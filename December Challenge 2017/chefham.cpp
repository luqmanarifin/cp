#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int cnt[N], a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof(cnt));
    int n;
    scanf("%d", &n);
    vector<int> one, two;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      if (cnt[a[i]] == 0) {
        one.push_back(i);
      } else {
        two.push_back(i);
      }
      cnt[a[i]]++;
    }
    if (two.size() == 1) {
      one.clear();
      two.clear();
      for (int i = 0; i < n; i++) {
        if (cnt[a[i]] == 1) {
          one.push_back(i);
        } else {
          two.push_back(i);
        }
      }
      for (auto it : one) two.push_back(it);
      for (int i = 0; i < two.size(); i++) {
        b[two[i]] = a[two[(i + 2) % two.size()]];
      }
    } else {
      for (int i = 0; i < one.size(); i++) {
        b[one[i]] = a[one[(i + 1) % one.size()]];
      }
      for (int i = 0; i < two.size(); i++) {
        b[two[i]] = a[two[(i + 1) % two.size()]];
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += (a[i] != b[i]);
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) printf("%d%c", b[i], " \n"[i == n - 1]);
  }

  return 0;
}
