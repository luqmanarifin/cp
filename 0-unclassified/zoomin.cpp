#include <bits/stdc++.h>

using namespace std;

const int N = 256;

vector<string> str[N];

int main() {
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> m >> n >> k;
  cin.ignore();
  for(int i = 0; i < k; i++) {
    string c;
    getline(cin, c);
    for(int i = 0; i < n; i++) {
      string buf;
      getline(cin, buf);
      str[c[0]].push_back(buf);
    }
  }
  int q;
  cin >> q;
  cin.ignore();
  while(q--) {
    string s;
    getline(cin, s);
    for(int row = 0; row < n; row++) {
      for(int i = 0; i < s.length(); i++) {
        for(int j = 0; j < m; j++) {
          if(row < str[s[i]].size()) {
            if(j < str[s[i]][row].size()) {
              printf("%c", str[s[i]][row][j]);
            } else {
              printf(" ");
            }
          } else {
            printf(" ");
          }
        }
      }
      printf("\n");
    }
  }
  
  return 0;
}
