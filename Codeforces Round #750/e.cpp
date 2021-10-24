#include <bits/stdc++.h>

using namespace std;

const int MAGIC = 450;
const int N = 1e5 + 5;

struct Bit {
  Bit(int n = 0) : n(n) {
    num.resize(n + 1);
  }
  void update(int i, long long v) {
    num[i] = max(num[i], v);
  }
  int find(int i) {
    return num[i];
  }
  vector<long long> num;
  int n;
};

Bit bit[MAGIC];
long long a[N], s[N];

long long get_sum(int l, int r) {
  return s[r] - s[l - 1];
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      s[i] = s[i - 1] + a[i];
    }
    int max_k = 0;
    for (int i = 1; ; i++) {
      if (i * (i + 1) / 2 > n) {
        max_k = i;
        break;
      }
    }

    for (int i = 1; i < max_k; i++) {
      bit[i] = Bit(n);
    }
    int ans = 1;
    for (int i = n; i >= 1; i--) {
      bit[1].update(i, a[i]);
      for (int len = ans; len >= 1; len--) {
        if (i + len + 1 <= n) {
          long long prev_sum = bit[len].find(i + len + 1);
          long long now_sum = get_sum(i, i + len);
          if (now_sum < prev_sum) {
            ans = max(ans, len + 1);
            bit[len + 1].update(i, now_sum);
          }
        }
      }
      for (int len = ans; len >= 1; len--) {
        if (i + 1 <= n) {
          bit[len].num[i] = max(bit[len].num[i], bit[len].num[i+1]);
        }
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
