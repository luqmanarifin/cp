#include <bits/stdc++.h>

using namespace std;

const int N = 55;

string a[N];
string ans[N];

string get(int p) {
  string s;
  if (p < 26) {
    s.push_back(p + 'A');
  } else {
    s.push_back(p / 26 + 'A');
    s.push_back(p % 26 + 'a');
  }
  return s;
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) ans[i] = get(i);
  for (int i = 0; i < n - k + 1; i++) cin >> a[i];
  for (int i = 0; i < n - k + 1; i++) {
    if (a[i] == "NO") {
      ans[i+k-1] = ans[i];
    }
  }
  for (int i = 0; i < n - k + 1; i++) {
    set<string> all;
    for (int j = 0; j < k; j++) {
      all.insert(ans[i+j]);
    }
    if (a[i] == "YES") {
      assert(all.size() == k);
    } else {
      assert(all.size() < k);
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i] << ' ';

  return 0;
}
