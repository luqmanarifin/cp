#include <bits/stdc++.h>

using namespace std;

const int N = 105;

// chat - id: 1 berarti ada
int mention[N][N];

string s[N];
string user[N];
map<string, int> mp;

int dp[N][N], bef[N][N];

bool alphanum(char c) {
  return 'a' <= c && c <= 'z' && 'A' <= c && c <= 'Z' && '0' <= c && c <= '9';
}

string get_name(int i) {
  int at = s[i].find(":");
  return s[i].substr(0, at);
}

// chat - id
void dfs(int i, int j) {
  if (i) {
    dfs(i - 1, bef[i][j]); 
  }
  if (s[i][0] == '?') {
    printf("%s%s\n", user[j].c_str(), s[i].substr(1).c_str());
  } else {
    printf("%s\n", s[i].c_str());
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(mention, 0, sizeof(mention));
    memset(dp, 0, sizeof(dp));
    mp.clear();
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> user[i];
      mp[user[i]] = i;
    }
    int m;
    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; i++) getline(cin, s[i]);
    
    for (int id = 0; id < n; id++) {
      int userlen = user[id].length();
      for (int i = 0; i < m; i++) {
        int len = s[i].length();
        for (int j = 0; j + userlen <= len; j++) {
          bool ok = 1;
          for (int k = 0; k < userlen; k++) {
            if (user[id][k] != s[i][j+k]) {
              ok = 0;
              break;
            }
          }
          if (j >= 1 && alphanum(s[i][j-1])) ok = 0;
          if (j + userlen < len && alphanum(s[i][j+userlen])) ok = 0;
          if (ok) {
            mention[i][id] = 1;
            break;
          }
        }
      }
    }
    if (s[0][0] == '?') {
      for (int i = 0; i < n; i++) {
        if (!mention[0][i]) {
          dp[0][i] = 1;
        }
      }
    } else {
      dp[0][mp[get_name(0)]] = 1;
    }
    for (int i = 1; i < m; i++) {
      if (s[i][0] == '?') {
        for (int j = 0; j < n; j++) {
          if (mention[i][j]) continue;
          for (int k = 0; k < n; k++) {
            if (j == k) continue;
            if (dp[i - 1][k]) {
              dp[i][j] = 1;
              bef[i][j] = k;
            }
          }
        }
      } else {
        int id = mp[get_name(i)];
        for (int k = 0; k < n; k++) {
          if (k == id) continue;
          if (dp[i - 1][k]) {
            dp[i][id] = 1;
            bef[i][id] = k;
          }
        }
      }
    }
    bool done = 0;
    for (int i = 0; i < n; i++) {
      if (dp[m - 1][i]) {
        dfs(m - 1, i);
        done = 1;
        break;
      }
    }
    if (!done) {
      puts("Impossible");
    }
  }

  return 0;
}
