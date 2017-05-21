#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int inf = 1e9;

string s[N];
map<string, int> mp;
int d[N][N];

int main() {
  int t;
  cin >> t;
  cin.ignore();
  cin.ignore();
  while (t--) {
    mp.clear();
    
    string buf;
    int n = 0;
    while (getline(cin, buf)) {
      if (buf == "*") break;
      s[n] = buf;
      mp[buf] = n;
      n++;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        d[i][j] = inf;
        if (i != j) {
          if (s[i].length() == s[j].length()) {
            int dif = 0;
            for (int k = 0; k < s[i].length(); k++) {
              if (s[i][k] != s[j][k]) {
                dif++;
              }
            }
            if (dif == 1) d[i][j] = 1;
          }
        }
      }
      d[i][i] = 0;
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
    while (getline(cin, buf)) {
      if (buf.empty()) break;
      stringstream ss(buf);
      string a, b;
      ss >> a >> b;
      //printf("%d %d\n", mp[a], mp[b]);
      printf("%s %s %d\n", a.c_str(), b.c_str(), d[mp[a]][mp[b]]);
    }
    if (t) puts("");
  }

  return 0;
}
