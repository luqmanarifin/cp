#include <bits/stdc++.h>

using namespace std;

class FourStrings {
public:
  string a, b, c, d;
  
  bool can(int len) {
    vector<int> cnt(len);
    vector<char> all;
    all.resize(len, '*');
    bool ada;
    for(int i = 0; i + a.length() <= len; i++) {
      for(int t = 0; t < a.length(); t++) {
        all[i + t] = a[t];
        cnt[i + t]++;
      }
      for(int j = 0; j + b.length() <= len; j++) {
        for(int t = 0; t < b.length(); t++) {
          if(all[j + t] != '*' && all[j + t] != b[t]) {
            goto BCONT;
          }
        }
        for(int t = 0; t < b.length(); t++) {
          all[j + t] = b[t];
          cnt[j + t]++;
        }
        for(int k = 0; k + c.length() <= len; k++) {
          for(int t = 0; t < c.length(); t++) {
            if(all[k + t] != '*' && all[k + t] != c[t]) {
              goto CCONT;
            }
          }
          for(int t = 0; t < c.length(); t++) {
            all[k + t] = c[t];
            cnt[k + t]++;
          }
          for(int l = 0; l + d.length() <= len; l++) {
            for(int t = 0; t < d.length(); t++) {
              if(all[l + t] != '*' && all[l + t] != d[t]) {
                goto DCONT;
              }
            }
            for(int t = 0; t < d.length(); t++) {
              all[l + t] = d[t];
              cnt[l + t]++;
            }
            ada = 0;
            for(int i = 0; i < len; i++) {
              if(all[i] == '*') {
                ada = 1;
                break;
              }
            }
            if(!ada) return 1;
            for(int t = 0; t < d.length(); t++) {
              cnt[l + t]--;
              if(cnt[l + t] == 0) all[l + t] = '*';
            }
            DCONT:;
          }
          for(int t = 0; t < c.length(); t++) {
            cnt[k + t]--;
            if(cnt[k + t] == 0) all[k + t] = '*';
          }
          CCONT:;
        }
        for(int t = 0; t < b.length(); t++) {
          cnt[j + t]--;
          if(cnt[j + t] == 0) all[j + t] = '*';
        }
        BCONT:;
      }
      for(int t = 0; t < a.length(); t++) {
        cnt[i + t]--;
        if(cnt[i + t] == 0) all[i + t] = '*';
      }
    }
    return 0;
  }
  int shortestLength(string _a, string _b, string _c, string _d) {
    a = _a; b = _b; c = _c; d = _d;
    int l = max(max(a.length(), b.length()), max(c.length(), d.length()));
    for(int i = l; ; i++) {
      if(can(i)) return i;
    }
  }
};
/*
int main() {
  FourStrings FourStrings;
  cout << FourStrings.shortestLength("aaaaaaaaaa", "bbbbbbbbbb", "cccccccccc", "dddddddddd") << endl;
  
  return 0;
}
*/