#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9;

string s;
int x, y, z;
int dp[256], found_ans;
string ans[256];

// return -1 if it's wrong
int until(int st) {
  if (st >= s.length()) return inf;
  if (s[st] == '!') return until(st + 1);
  if (s[st] == '&' || s[st] == '|') return inf;
  if (s[st] == 'x' || s[st] == 'y' || s[st] == 'z') return st;
  if (s[st] == ')') return inf;
  int now = 0;
  for (int i = st; i < s.length(); i++) {
    if (s[i] == '(') now++;
    if (s[i] == ')') now--;
    if (now == 0) return i;
  }
  return inf;
}

bool variable(int l, int r, bool single = 0) {
  //printf("variable %d %d\n", l, r);
  if (l > r) return 0;
  if (single) {
    if (s[l] == 'x' || s[l] == 'y' || s[l] == 'z') {
      return l == r;
    }
    if (s[l] == '!') return variable(l + 1, r, 1);
    if (s[l] == '(') return variable(l + 1, r - 1);
  }
  vector<tuple<int, int, int>> emp;   // type (0 operasi - 1 variabel), l, r.
  for (int i = l; i <= r; i++) {
    if (s[i] == '&' || s[i] == '|') {
      emp.emplace_back(0, i, i);
    } else {
      int til = until(i);
      if (til > r) return 0;
      if (s[i] == '(') {
        if (!variable(i + 1, til - 1)) return 0;
      } else {
        if (!variable(i, til, 1)) return 0;
      }
      emp.emplace_back(1, i, til);
      i = til;
    }
  }
  if (emp.size() % 2 == 0) return 0;
  for (int i = 0; i < emp.size(); i++) {
    int par;
    tie(par, ignore, ignore) = emp[i];
    if (par == i % 2) return 0;
  }
  return 1;
}

int get(int l, int r, bool single = 0) {
  //printf("get %d %d\n", l, r);
  if (l > r) assert(0);
  if (single) {
    if (s[l] == 'x') return x;
    if (s[l] == 'y') return y;
    if (s[l] == 'z') return z;
    if (s[l] == '!') return !get(l + 1, r, 1);
    if (s[l] == '(') return get(l + 1, r - 1);
  }
  vector<tuple<char, int, int>> emp;   // var, l, r.
  for (int i = l; i <= r; i++) {
    if (s[i] == '&' || s[i] == '|') {
      emp.emplace_back(s[i], i, i);
    } else {
      int til = until(i);
      if (til > r) return 0;
      int ret = 0;
      if (s[i] == '(') {
        ret = get(i + 1, til - 1);
      } else {
        ret = get(i, til, 1);
      }
      emp.emplace_back(ret, i, til);
      i = til;
    }
  }
  for (int i = 0; i < emp.size(); i += 2) {
    int now = get<0>(emp[i]);
    int j = i;
    while (j + 1 < emp.size() && get<0>(emp[j + 1]) == '&') {
      now &= get<0>(emp[j + 2]);
      j += 2;
    }
    if (now) return 1;
    i = j;
  }
  return 0;
}

void solve() {
  //cout << "solving " << s << endl;
  if (!variable(0, s.length() - 1)) return;
  //cout << "valid!" << endl;
  int num = 0;
  for (int mask = 0; mask < (1 << 3); mask++) {
    x = mask / 4;
    y = (mask / 2) % 2;
    z = mask % 2;
    num = num * 2 + get(0, s.length() - 1);
  }
  if (dp[num] == -1) {
    dp[num] = 1;
    ans[num] = s;
    ++found_ans;
    cerr << found_ans << " FOUND!" << endl;
    int tmp = num;
    //for (int i = 0; i < (1 << 3); i++) printf("%d", tmp % 2), tmp /= 2;
    //printf(" %s\n", ans[num].c_str());
  }
}

string cons = "&|!xyz()";

int main() {
  memset(dp, -1, sizeof(dp));
  sort(cons.begin(), cons.end());
  vector<string> now = {""};
  for (int len = 1; ; len++) {
    vector<string> ok;
    for (auto it : now) {
      for (int i = 0; i < cons.size(); i++) {
        s = it + cons[i];
        solve();
        if (found_ans == 256) goto OUT;
        ok.push_back(s);
      }
    }
    now = ok;
  }
  OUT:;
  for (int i = 0; i < 256; i++) cout << "\"" << ans[i] << "\","<< endl;
  return 0;
}
