#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long bit[N], sum[N];

void add_bit(int i, long long val, long long tval) {
  for (; i < N; i |= i + 1) {
    bit[i] += val;
    sum[i] += tval;
  }
}

long long find_bit(int i) {
  long long val = 0, tval = 0, at = i;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    val += bit[i];
    tval += sum[i];
  }
  return val * at + tval;
}

void add(int l, int r, long long val) {
  add_bit(l, val, -(l - 1) * val);
  add_bit(r + 1, -val, r * val);
}

long long find(int l, int r) {
  return find_bit(r) - find_bit(l - 1);
}

int main() {
  int n = 200000;
  for (int i = 1; i <= n; i++) {
    int now = 1;
    while (now <= i) {
      int l = now, r = i;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (i / now == i / mid) {
          l = mid;
        } else {
          r = mid = 1;
        }
      }
      add(now, l, i / now);
      now = l + 1;
    }
  }

  return 0;
}
