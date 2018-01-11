#include <bits/stdc++.h>

using namespace std;

const int E = 0;
const int T = 1;
const int F = 2;

struct item {
  item() {}
  item(string _s) : s(_s) {}
  bool operator< (const item& other) const {
    if (s.size() != other.s.size()) return s.size() < other.s.size();
    return s < other.s;
  }
  bool operator==(const item& other) const {
    return s == other.s;
  }
  string s;
};

int to_int(const string& s) {
  int num = 0;
  for (int i = 0; i < s.size(); i++) {
    num = num * 2 + s[i] - '0';
  }
  return num;
}

string dp[3][1 << 8];

set<tuple<item, int, int>> pq;

void update(int i, int mask, const string& str) {
  if (dp[i][mask].empty()) {
    dp[i][mask] = str;
    pq.insert(make_tuple(item(dp[i][mask]), i, mask));
  } else if (item(str) < item(dp[i][mask])) {
    pq.erase(make_tuple(item(dp[i][mask]), i, mask));
    dp[i][mask] = str;
    pq.insert(make_tuple(item(dp[i][mask]), i, mask));
  }
}

char s[20];

int main() {
  update(F, to_int("00001111"), "x");
  update(F, to_int("00110011"), "y");
  update(F, to_int("01010101"), "z");
  int cnt = 0;
  while (!pq.empty()) {
    //for (auto it : pq) printf("%s %d %d\n", get<0>(it).s.c_str(), get<1>(it), get<2>(it)); printf("\n");
    cnt++;
    auto it = *(pq.begin());
    pq.erase(it);
    item tem; int at, mask;
    tie(tem, at, mask) = it;
    string now = tem.s;
    //printf("%d %d %s\n", at, mask, now.c_str());
    if (at == E) {
      update(F, mask, "(" + now + ")");
      for (int i = 0; i < (1 << 8); i++) {
        if (dp[T][i].empty()) continue;
        int to = (mask | i);
        update(E, to, now + "|" + dp[T][i]);
      }
    } else if (at == T) {
      for (int i = 0; i < (1 << 8); i++) {
        if (dp[E][i].empty()) continue;
        int to = (i | mask);
        update(E, to, dp[E][i] + "|" + now);
      }
      update(E, mask, now);
      for (int i = 0; i < (1 << 8); i++) {
        if (dp[F][i].empty()) continue;
        int to = (mask & i);
        update(T, to, now + "&" + dp[F][i]);
      }
    } else if (at == F) {
      for (int i = 0; i < (1 << 8); i++) {
        if (dp[T][i].empty()) continue;
        int to = (i & mask);
        update(T, to, dp[T][i] + "&" + now);
      }
      update(T, mask, now);
      update(F, ((1<<8)-1) ^ mask, "!" + now);
    } else {
      assert(0);
    }
  }
  for (int i = 0; i < (1 << 8); i++) {
    item ans = item(dp[0][i]);
    for (int j = 0; j < 3; j++) {
      ans = min(ans, item(dp[j][i]));
    }
    printf("\"%s\",\n", ans.s.c_str());
  }
  return 0;
}
