
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int bit[N], n;
char s[N];

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
  return ret;
}

void add(int i, int v) {
  for (; i < N; i |= i + 1) bit[i] += v;
}

bool can(int d) {
  memset(bit, 0, sizeof(bit));
  for (int i = 1; i + d - 1 <= n; i++) {
    int now = (s[i] - '0' + find(i)) % 2;
    if (now) {
      add(i, 1);
    }
  }
  int ada = 0;
  for (int i = 1; i <= n; i++) {
    int now = (s[i] - '0' + find(i)) % 2;
    if (now) {
      break;
    } else {
      ada++;
    }
  }
  return ada >= d;
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (can(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
  return 0;
}
