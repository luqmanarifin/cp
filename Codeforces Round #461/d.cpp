
#include <bits/stdc++.h>

using namespace std;

struct item {
  string str;
  long long s, h;
  bool operator<(item other) const {
    return s * other.h > h * other.s;
  }
};

const int N = 1e5 + 5;

item a[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].str;
    for (int j = 0; j < a[i].str.size(); j++) {
      if (a[i].str[j] == 's') {
        a[i].s++;
      } else {
        a[i].h++;
      }
    }
  }
  sort(a, a + n);
  string all;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a[i].str.size(); j++) {
      all.push_back(a[i].str[j]);
    }
  }
  long long ans = 0, s = 0;
  for (int i = 0; i < all.size(); i++) {
    if (all[i] == 's') {
      s++;
    } else {
      ans += s;
    }
  }
  cout << ans << endl;
  return 0;
}
