#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], id[N], where[N], should[N];
int n, k;
vector<tuple<int, int, int>> ans;

void transform(int A, int B, int to) {
  assert(a[A] + a[B] == k);
  int d = a[A] - a[to];
  ans.emplace_back(A, B, d);
  swap(id[A], id[to]);
  swap(where[id[A]], where[id[to]]);
  a[A] -= d;
  a[B] += d;
}

void move(int A, int B) {
  transform(n - 1, 0, A);
  transform(A, 0, B);
  transform(B, 0, n - 1);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ans.clear();

    scanf("%d %d", &n, &k);
    int A = -1, B, good = 1;
    vector<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      if (i && a[i-1] > a[i]) {
        good = 0;
      }
      s.emplace_back(a[i], i);
    }
    sort(s.begin(), s.end());
    int ptr = n - 1;
    for (int i = 0; i < s.size() && i < ptr; i++) {
      while (i < ptr && k - s[i].first < s[ptr].first) ptr--;
      if (i < ptr && s[i].first + s[ptr].first == k) {
        A = min(s[i].second, s[ptr].second);
        B = max(s[i].second, s[ptr].second);
        break;
      }
    }
    if (good) {
      puts("0");
      continue;
    }
    if (A == -1) {
      puts("-1");
      continue;
    }
    int idx = 0;
    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++) {
      if (i != A && i != B) {
        p.emplace_back(a[i], idx);
        where[idx] = i;
        id[i] = idx++;
      }
    }
    where[idx] = A;
    id[A] = idx++;
    where[idx] = B;
    id[B] = idx++;
    sort(p.begin(), p.end());
    for (int i = 0; i < p.size(); i++) {
      should[i + 1] = p[i].second;
    }
    if (A > 0) {
      transform(A, B, 0);
      A = 0;
    }
    if (B < n - 1) {
      transform(B, A, n - 1);
      B = n - 1;
    }
    for (int i = 1; i < n - 1; i++) {
      if (id[i] != should[i]) {
        move(i, where[should[i]]);
      }
    }
    ans.emplace_back(0, n - 1, a[0]);
    printf("%d\n", ans.size());
    for (auto it : ans) {
      printf("%d %d %d\n", get<0>(it) + 1, get<1>(it) + 1, get<2>(it));
    }
  }

  return 0;
}
