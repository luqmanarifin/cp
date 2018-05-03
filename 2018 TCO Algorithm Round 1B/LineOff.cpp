#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int aft[N], bef[N], n;
char s[N];

class LineOff {
public:
  bool ok(int i) {
    return aft[i] <= n && s[i] == s[aft[i]];
  }
  void remove(int i) {
    aft[bef[i]] = aft[i];
    bef[aft[i]] = bef[i];
  }
  int movesToDo(string _s) {
    n = _s.size();
    for (int i = 0; i < n; i++) s[i + 1] = _s[i];
    for (int i = 0; i <= n; i++) {
      bef[i] = i - 1;
      aft[i] = i + 1;
    }
    int ans = 0;
    int p = 1;
    while (p <= n) {
      //printf("%d\n", p);
      if (p == 0) {
        p = aft[p];
        continue;
      }
      if (ok(p)) {
        int q = aft[p];
        ans++;
        remove(p);
        remove(q);
        p = bef[p];
      } else {
        p = aft[p];
      }
    }
    return ans;
  }
};

// int main() {
//   LineOff LineOff;
//   cout << LineOff.movesToDo("abba") << endl;

//   return 0;
// }
