#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char s[N];
int n;
vector<int> ans;

vector<pair<int, int>> get_counting() {
  vector<pair<int, int>> p;
  for (int i = 0; i < 3 * n; i++) {
    int j = i;
    while (j + 1 < 3 * n && s[j + 1] == s[j]) j++;
    p.emplace_back(i, j - i + 1);
    i = j;
  }
  return p;
}

void solve() {
  printf("%d\n", (int) ans.size());
  for (auto it : ans) printf("%d ", it + 1);
  printf("\n");
  exit(0);
}

int main() {
  scanf("%s", s);
  n = strlen(s) / 3;
  for (int i = 0; i < 3 * n; i++) s[i] -= '0';
  
  
  // 4 dihancurkan
  //~ puts("4 hancur");
  for (int i = 0; i < 3 * n; i++) {
    int j = i;
    while (j + 1 < 3 * n && s[j + 1] == s[j]) j++;
    int len = j - i + 1;
    if (len >= 4) {
      for (int k = i + 1; k + 2 <= j; k += 3) {
        if (ans.size() + 1 > n) solve();
        ans.push_back(k);
        s[k] ^= 1;
        s[k + 1] ^= 1;
      }
    }
    i = j;
  }
  if (get_counting().size() >= 2 * n) solve();
  //~ cout << " 4 hancur " << ans.size() << endl;
  
  // 2 2 sebelahan
  //~ puts("2 sebelahan");
  vector<pair<int, int>> p = get_counting();
  for (int i = 1; i < p.size(); i++) {
    if (p[i-1].second >= 2 && p[i].second >= 2) {
      if (ans.size() + 1 > n) solve();
      ans.push_back(p[i].first - 1);
      s[p[i].first] ^= 1;
      s[p[i].first - 1] ^= 1;
      p[i].second--;
    }
  }
  //~ cout << "2 sebelahan " << ans.size() << endl;
  if (get_counting().size() >= 2 * n) solve();
  
  // 3 ujung
  p = get_counting();
  if (p[0].second == 3) {
    if (ans.size() + 1 > n) solve();
    ans.push_back(0);
    s[0] ^= 1;
    s[1] ^= 1;
  }
  if (p.back().second == 3 && p.size() > 1) {
    if (ans.size() + 1 > n) solve();
    ans.push_back(3 * n - 2);
    s[3 * n - 2] ^= 1;
    s[3 * n - 1] ^= 1;
  }
  if (get_counting().size() >= 2 * n) solve();
  //~ cout << " 3 ujung " << ans.size() << endl;
  
  // 3 sebelum ujung
  p = get_counting();
  if (p.size() >= 3 && p[1].second == 3) {
    if (ans.size() + 1 > n) solve();
    ans.push_back(0);
    s[0] ^= 1;
    s[1] ^= 1;
  }
  if (p.size() >= 4 && p[p.size() - 2].second == 3) {
    if (ans.size() + 1 > n) solve();
    ans.push_back(3 * n - 2);
    s[3 * n - 2] ^= 1;
    s[3 * n - 1] ^= 1;
  }
  if (get_counting().size() >= 2 * n) solve();
  //~ cout << " 3 sebelum ujung " << ans.size() << endl;
  
  // brute force
  for (int i = 0; i + 1 < 3 * n; i++) {
    int dif = 0;
    if (i && s[i-1] == s[i]) dif++;
    if (i && s[i-1] != s[i]) dif--;
    if (i + 2 < 3 * n && s[i + 2] == s[i + 1]) dif++;
    if (i + 2 < 3 * n && s[i + 2] != s[i + 1]) dif--;
    if (dif > 0) {
      if (ans.size() + 1 > n) solve();
      ans.push_back(i);
      s[i] ^= 1;
      s[i + 1] ^= 1;
    }
  }
  if (get_counting().size() >= 2 * n) solve();
  //~ cout << "bruteforce " << ans.size() << endl;
  
  // brute force 2 sebelahan
  for (int i = 0; i + 3 < 3 * n; i++) {
    int dif = 0;
    if (i && s[i-1] == s[i]) dif++;
    if (i && s[i-1] != s[i]) dif--;
    if (i + 4 < 3 * n && s[i + 4] == s[i + 3]) dif++;
    if (i + 4 < 3 * n && s[i + 4] != s[i + 3]) dif--;
    if (dif > 0) {
      if (ans.size() + 2 > n) solve();
      ans.push_back(i);
      ans.push_back(i + 2);
      s[i] ^= 1;
      s[i + 1] ^= 1;
      s[i + 2] ^= 1;
      s[i + 3] ^= 1;
    }
  }
  assert(get_counting().size() >= 2 * n);
  //~ cout << "bf 2 sebelahan " << ans.size() << endl;
  solve();
    
  return 0;
}
