#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long ans[6];

long long d[][6] = {
  {0, 0, 0, 0, 0, 1},
  {0, 0, 0, 0, 1, -1},
  {0, 0, 0, 1, -2, 1},
  {0, 0, 1, -3, 3, -1},
  {0, 1, -4, 6, -4, 1}
};

void compute(int same, vector<int>& s) {
  sort(s.begin(), s.end());
  int done = 0;
  for(int i = 0; i < s.size(); ) {
    int j = i + 1;
    while(j < s.size() && s[i] == s[j]) j++;
    int cnt = j - i;
    done += cnt;
    for(int k = 0; k < 6; k++) {
      ans[k] += 1LL * cnt * (s.size() - done) * d[same][k];
    }
    i = j;
  }
}

int code(char c) {
  if('a' <= c && c <= 'z') return c - 'a';
  if('A' <= c && c <= 'Z') return 26 + c - 'A';
  return 52 + c - '0';
}

int serialize(string& s) {
  int ret = 0;
  for(int i = 0; i < s.size(); i++) {
    ret = ret * 62 + code(s[i]);
  }
  return ret;
}

char buf[N][6];
vector<string> s;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%s", buf[i]);
    s.push_back((string) buf[i]);
  }
  sort(s.begin(), s.end());
  for(int i = 0; i < n; ) {
    int j = i + 1;
    while(j < n && s[i] == s[j]) j++;
    long long cnt = j - i;
    ans[0] += cnt * (cnt - 1) / 2;
    i = j;
  }
  for(int mask = 0; mask < (1 << 5); mask++) {
    vector<pair<int, int>> str(n);
    for(int at = 0; at < n; at++) {
      string tmp;
      for(int i = 0; i < 5; i++) {
        if(mask & (1 << i)) {
          tmp.push_back(s[at][i]);
        }
      }
      str[at].first = serialize(tmp);
    }
    for(int at = 0; at < n; at++) {
      string tmp;
      for(int i = 0; i < 5; i++) {
        if((mask & (1 << i)) == 0) {
          tmp.push_back(s[at][i]);
        }
      }
      str[at].second = serialize(tmp);
    }
    sort(str.begin(), str.end());
    for(int i = 0; i < n; ) {
      int j = i + 1;
      while(j < n && str[j].first == str[j - 1].first) j++;
      vector<int> tmp;
      for(int k = i; k < j; k++) {
        tmp.push_back(str[k].second);
      }
      compute(__builtin_popcount(mask), tmp);
      i = j;
    }
  }
  for(int i = 0; i <= 5; i++) {
    if(i) printf(" ");
    printf("%lld", ans[i]);
  }
  printf("\n");
  return 0;
}
