#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;

tuple<string, int, int> s[N];
string sa[N];
int sb[N], sc[N];

int find(string l, string r) {
  int ret = 0;
  for(int i = 0; i < n; i++) {
    if(l[i] == r[i]) {
      ret++;
    } else {
      break;
    }
  }
  return ret;
}

int p[N];
int b[N], f[N];

int dp[N][3];
int to[N][3];

int main() {
  ios_base::sync_with_stdio(false);
  
  cin >> n;
  int n;
  for(int i = 0; i < n; i++) {
    string str;
    cin >> str;
    s[i] = make_tuple(str, 0, i);
  }
  for(int i = 0; i < n; i++) {
    string str;
    cin >> str;
    s[i] = make_tuple(str, 1, i);
  }
  sort(s, s + 2 * n);
  for(int i = 0; i < 2 * n; i++) {
    tie(sa[i], sb[i], sc[i]) = s[i];
  }
  
  int now = -1, h = 0;
  for(int i = 0; i < 2 * n; i++) {
    string str; int t, num;
    tie(str, t, num) = s[i];
    if(t == 0) {
      b[h] = now;
      p[h++] = i;
    } else {
      now = i;
    }
  }
  now = -1, h = n - 1;
  for(int i = 2 * n - 1; i >= 0; i--) {
    string str; int t, num;
    tie(str, t, num) = s[i];
    if(t == 0) {
      b[h] = now;
    } else {
      now = i;
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 3; j++) {
      dp[i][j] = -inf;
    }
  }
  for(int i = 0; i < n; i++) {
    int get_back = (b[i] == -1? 0 : find(sa[p[i]], sa[b[i]]));
    int get_front = (f[i] == -1? 0 : find(sa[p[i]], sa[f[i]]));
    if(i == 0) {
      dp[i][0] = 0;
      dp[i][1] = get_back;
      dp[i][2] = get_front;
    }
    for(int j = 0; j < 3; j++) {
      if(dp[i - 1][j] > dp[i][0]) {
        dp[i][0] = dp[i - 1][j];
        to[i][0] = j;
      }
      if(j != 2 || b[i] != f[i - 1] && dp[i - 1][j] + get_back > dp[i][1]) {
        dp[i][1] = dp[i - 1][j] + get_back;
        to[i][1] = j;
      }
      if(dp[i - 1][j] + get_front > dp[i][2]) {
        dp[i][2] = dp[i - 1][j] + get_front;
        to[i][2] = j;
      }
    }
  }
  int ans = -inf, st = -1;
  for(int j = 0; j < 3; j++) {
    if(dp[n - 1][j] > ans) {
      ans = dp[n - 1][j];
      st = j;
    }
  }
  vector<int> pans;
  int pos = n - 1;
  while(pos >= 0) {
    if(st == 1 && b[pos] != -1) {
      
    }
    if(st == 2 && f[pos] != -1) {
      
    }
    st = to[pos][st];
    pos--;
  }
  return 0;
}
