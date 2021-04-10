#include <bits/stdc++.h>

using namespace std;

string produce(string a, string b) {
  if (a.size() < b.size()) return b;
  if (a.size() == b.size()) {
    if (a < b) return b;
    if (a >= b) return b + "0";
  }
  if (a.size() > b.size()) {
    string c = a.substr(0, b.size());
    if (c < b) {
      int k = a.size() - b.size();
      while (k--) b += "0";
      return b;
    }
    if (c == b) {
      bool all_nine = true;
      for (int i = b.size(); i < a.size(); i++) if (a[i] != '9') all_nine = false;
      if (!all_nine) {
        for (int i = b.size(); i < a.size(); i++) b += a[i];
        for (int i = a.size() - 1; i >= 0; i--) {
          if (b[i] == '9') {
            b[i] = '0';
          } else {
            b[i]++;
            break;
          }
        }
        return b;
      } else {
        int k = a.size() - b.size() + 1;
        while (k--) b += "0";
        return b;
      } 
    }
    if (c > b) {
      int k = a.size() - b.size() + 1;
      while (k--) b += "0";
      return b;
    }
  }
  return "";
}

char buf[1005];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    string bef = "";
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      string s = string(buf);
      if (i) {
        string nex = produce(bef, s);
        ans += nex.size() - s.size();
        // printf("%s %s -> %s\n", bef.c_str(), s.c_str(), nex.c_str());
        bef = nex;
      } else {
        bef = s;
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }

  return 0;
}
