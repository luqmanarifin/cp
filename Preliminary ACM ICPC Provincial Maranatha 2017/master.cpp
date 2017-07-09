#include <bits/stdc++.h>

using namespace std;

const int SIZE = 26;
const int N = 50000;

// index - length
set<long long> pos[N][15];
int pt;

void entry(string s) {
  for (int i = 0; i < s.length(); i++) {
    long long now = 0;
    for (int j = i; j < i + 10 && j < s.length(); j++) {
      now = now * 26 + s[j] - 'a';
      pos[pt][j - i + 1].insert(now);
    }
  }
}

char que[N];
int dp[12][12];

int main() {
  ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    string line;
    pt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 15; j++) {
        pos[i][j].clear();
      }
    }    
    
    cin.ignore();
    while (getline(cin, line)) {
      if (line == "--") break;
      for (int i = 0; i < line.size(); i++) {
        if ('a' <= line[i] && line[i] <= 'z') {
          
        } else if ('A' <= line[i] && line[i] <= 'Z') {
          line[i] = line[i] - 'A' + 'a'; 
        } else {
          line[i] = ' ';
        }
      }
      stringstream ss(line);
      string tok;
      while (ss >> tok) {
        pt++;
        //cout << tok << endl;
        entry(tok);
        reverse(tok.begin(), tok.end());
        entry(tok);
      }
    }
    int n, k;
    cin >> n >> k;
    int ans = 0;
    while (n--) {
      cin >> (que + 1);
      int len = strlen(que + 1);
      for (int i = 1; i <= len; i++) {
        if ('A' <= que[i] && que[i] <= 'Z') {
          que[i] = que[i] - 'A' + 'a';
        }
      }
      
      for (int idx = 1; idx <= pt; idx++) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < len; i++) {
          for (int j = 0; j < k; j++) {
            if (dp[i][j] == 0) continue;
            long long now = 0;
            for (int en = i + 1; en <= len && en <= i + 10; en++) {
              now = now * 26 + que[en] - 'a';
              if (pos[idx][en - i].count(now)) {
                dp[en][j + 1] = 1;
              }
            }
          }
        }
        bool ada = 0;
        for (int i = 0; i <= k; i++) {
          if (dp[len][i]) {
            ada = 1;
          }
        }
        if (ada) {
          ans++;
        }
      }
    }
    printf("Case %d: %d\n", tt, ans);
  }
  

  return 0;
}
