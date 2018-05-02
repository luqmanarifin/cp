#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int inf = 1e9;
const double eps = 1e-7;

int c[N];
pair<int, int> p[N];

bool ok[N];

int bit[N];
double b[N];
int first[N];

void add(int i, int val) {
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    bit[i] = min(bit[i], val);
  }
}

int find(int i) {
  int ret = inf;
  for (; i < N; i |= i + 1) ret = min(ret, bit[i]);
  return ret;
}

int main() {
  int n, x1, x2;
  scanf("%d %d %d", &n, &x1, &x2);
  for (int i = 1; i <= n; i++) {
    scanf("%d", c + i);
    p[i] = make_pair(c[i], i);
  }
  sort(p + 1, p + 1 + n);

  for (int i = n; i >= 1; i--) {
    int ada = n - i + 1;
    if (1LL * p[i].first * ada >= x2) {
      ok[i] = 1;
    }
  }
  for (int i = n; i >= 1; i--) {
    ok[i] |= ok[i + 1];
  }
  for (int i = 1; i <= n; i++) {
    b[i] = (double) x2 / (n - i + 1);
  }
  fill(bit, bit + N, inf);
  for (int i = n; i >= 1; i--) {
    int at = lower_bound(b + 1, b + 1 + n, p[i].first + eps) - b - 1;
    at -= i - 1;
    if (at >= 1) {
      add(at, i);
    }
  }
  for (int i = 1; i <= n; i++) {
    first[i] = find(i);
  }

  int st = n;
  for (int server = 1; server < n; server++) {
    while (st - 1 >= 1 && x1 <= 1LL * server * p[st - 1].first) st--;
    if (x1 <= 1LL * server * p[st].first) {
      if (st + server - 1 > n) continue;
      if (ok[st + server]) {
        puts("Yes");
        vector<int> a1, a2;
        for (int i = st; i <= st + server - 1; i++) a1.push_back(p[i].second);
        for (int i = n; i >= 1; i--) {
          int ada = n - i + 1;
          if (1LL * p[i].first * ada >= x2) {
            for (int j = 0; j < ada; j++) {
              a2.push_back(p[n - j].second);
            }
            break;
          }
        }
        printf("%d %d\n", a1.size(), a2.size());
        for (auto it : a1) printf("%d ", it); printf("\n");
        for (auto it : a2) printf("%d ", it); printf("\n");
        return 0;
      }
      if (first[1 + server] < st) {
        puts("Yes");
        vector<int> a1, a2;
        for (int i = st; i <= st + server - 1; i++) a1.push_back(p[i].second);
        for (int i = first[1 + server]; i <= n; i++) {
          if (st <= i && i <= st + server - 1) continue;
          a2.push_back(p[i].second);
        }
        printf("%d %d\n", a1.size(), a2.size());
        for (auto it : a1) printf("%d ", it); printf("\n");
        for (auto it : a2) printf("%d ", it); printf("\n");
        return 0;
      }
    }
  }
  puts("No");
  return 0;
}
