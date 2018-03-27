#include <bits/stdc++.h>

using namespace std;

const string NAME = "caption";
const int inf = 1e8;
const int N = 2005;
const int LETTER = 35;

void mini(int& at, int val) {
  at = min(at, val);
}

vector<string> split(string s) {
  vector<string> ret;
  stringstream ss(s);
  string buf;
  while (ss >> buf) {
    ret.push_back(buf);
  }
  return ret;
}


vector<string> mp[26];
string bef, aft, buf;
char MAP[LETTER][N];
int space[LETTER];
int m, n, k, smin, smax;

int s[N];               // clean chars become space
int cost[N][26];        // starting - alfabet
int dp[N][LETTER];      // pos - LETTER
int backtrack[N][LETTER];

void dfs(int pos, int letter) {
  if (letter == 0) return;
  dfs(backtrack[pos][letter], letter - 1);
  //printf("%d %d: %d\n", pos, letter, dp[pos][letter]);
  printf("%d", pos - backtrack[pos][letter] - k);
  if (letter < aft.size()) {
    printf(" ");
  } else {
    printf("\n");
  }
}

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif
  

  cin >> m >> n >> k >> smin >> smax;
  cin.ignore();
  getline(cin, buf);
  vector<string> ret = split(buf);
  for (int i = 1; i < ret.size(); i += 2) {
    int c = ret[i-1][0] - 'A';
    mp[c].push_back(ret[i]); 
  }
  for (int it = 1; it < m; it++) {
    for (int i = 1; i < ret.size(); i += 2) {
      int c = ret[i-1][0] - 'A';
      cin >> buf;
      assert(buf.size() == k);
      mp[c].push_back(buf);
    }
    cin.ignore();
  }
  // for (int i = 0; i < 26; i++) {
  //   if (mp[i].empty()) continue;
  //   printf("huruf %c:\n", i + 'A');
  //   for (auto it : mp[i]) cout << it << endl;
  // }
  getline(cin, bef);
  for (int i = 0; i < bef.size(); i++) cin >> space[i];
  cin.ignore();
  getline(cin, aft);

  // cout << "bef " << bef << endl;
  // cout << "aft " << aft << endl; 

  // generate cleaning and MAP
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < LETTER; j++) {
      MAP[j][i] = '.';
    }
  }
  int now = 0;
  for (int it = 0; it < bef.size(); it++) {
    now += space[it];
    if ('A' <= bef[it] && bef[it] <= 'Z') {
      int c = bef[it] - 'A';
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
          if (mp[c][i][j] == '*') {
            s[now + 1 + j]++;
            MAP[i][now + 1 + j] = '*';
          }
        }
      }
    }
    now += k;
  }
  for (int i = 1; i < N; i++) s[i] += s[i-1];
  // for (int i = 1; i <= n; i++) printf("%d ", s[i] - s[i-1]); printf("\n");

  // generate cost
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 26; j++) {
      cost[i][j] = inf;
    }
  }
  // starting at where - huruf apa
  for (int i = 1; i + k - 1 <= n; i++) {
    for (int j = 0; j < 26; j++) {
      if (mp[j].empty()) continue;
      cost[i][j] = 0;
      for (int it = 0; it < m; it++) {
        for (int jt = 0; jt < k; jt++) {
          if (MAP[it][i + jt] != mp[j][it][jt]) {
            cost[i][j]++;
          }
        }
      }
      // printf("cost huruf %c starting at %d: %d\n", j + 'A', i, cost[i][j]);
    }
  }
  // for (int i = 0; i < m; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     printf("%c", MAP[i][j]);
  //   }
  //   printf("\n");
  // }

  // generate dp
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < LETTER; j++) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 0;
  for (int letter = 0; letter < aft.size(); letter++) {
    int l, r;
    if (letter == 0) {
      l = 0;
      r = n;
    } else {
      l = smin;
      r = smax;
    }
    for (int sp = l; sp <= r; sp++) {
      for (int i = 0; i + sp + k <= n; i++) {
        int add = s[i + sp] - s[i];
        int c = (aft[letter] == ' '? inf : (aft[letter] - 'A'));
        if (c == inf) {
          add += s[i + sp + k] - s[i + sp];
        } else {
          add += cost[i + sp + 1][c];
        }
        if (dp[i + sp + k][letter + 1] > dp[i][letter] + add) {
          dp[i + sp + k][letter + 1] = dp[i][letter] + add;
          backtrack[i + sp + k][letter + 1] = i;
        }
      }
    }
  }

  // finalize dp with remaining space && look answer
  int ans = inf, niki = -1;
  for (int i = 1; i <= n; i++) {
    dp[i][aft.size()] += s[n] - s[i];
    if (ans > dp[i][aft.size()]) {
      ans = dp[i][aft.size()];
      niki = i;
    }
  }
  // cout << ans << endl;
  // cerr << dp[24][1] << endl;
  // cerr << "cost R " << cost[40]['R' - 'A'] << endl;
  // cerr << "cost C " << cost[46][2] << endl;
  // printf("nikichan %d\n", niki);
  dfs(niki, aft.size());

#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif

  return 0;
}
