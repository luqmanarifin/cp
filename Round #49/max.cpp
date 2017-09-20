#include <bits/stdc++.h>

using namespace std;

const long long PRIME = 1e9 + 9;
const long long mod = 1e9 + 89;
const int N = 1e5 + 5;

long long h[N];
long long power[N];

long long get(int l, int r) {
  long long tmp = h[r] - h[l - 1] * power[r - l + 1] % mod;
  tmp %= mod;
  if (tmp < 0) tmp += mod;
  return tmp;
}

char s[N];
vector<int> at[N];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    h[i] = (h[i - 1] * PRIME + s[i] - 'a' + 1)% mod;
  }
  power[0] = 1;
  for (int i = 1; i < N; i++) {
    power[i] = power[i - 1] * PRIME % mod;
  }
  for (int i = 1; i <= n; i++) {
    at[s[i] - 'a'].push_back(i);
  }
  int best = -1, p = -1, num = -1;
  for (int c = 0; c < 26; c++) {
    if (at[c].empty()) continue;
    int l = 1, r = n - (int) at[c].back() + 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      long long cur = get(at[c][0], at[c][0] + mid - 1);
      bool same = 1;
      for (auto it : at[c]) {
        long long now = get(it, it + mid - 1);
        if (cur != now) {
          same = 0;
          break;
        }
      }
      if (same) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    //printf("%d %d\n", at[c].size(), num);
    if ((int) at[c].size() > num) {
      num = (int) at[c].size();
      best = l;
      p = c;
    } else if ((int) at[c].size() == num) {
      if (l > best) {
        best = l;
        p = c;
      }
    }
  } 
  //printf("%d %d %d\n", best, p, num);
  for (int i = 0; i < best; i++) {
    printf("%c", s[at[p][0] + i]);
  }
  printf("\n");
  //cout << get(2, 3) << ' ' << get(5, 6) << endl;
  return 0;
}
