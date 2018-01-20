#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], dp[N], nim[N];
int bit[N];

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
  return ret;
}

void add(int i, int val) {
  for (; i < N; i |= i + 1) bit[i] += val;
}

multiset<int> ada;

void insert(int v) {
  if (!ada.count(v)) {
    add(v, 1);
  }
  ada.insert(v);
}

void erase(int v) {
  ada.erase(ada.find(v));
  if (!ada.count(v)) {
    add(v, -1);
  }
}

int get_nim() {
  int l = 0, r = N - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (find(mid) == mid + 1) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  sort(a + 1, a + 1 + n);
  set<int> awal;
  for (int i = 1; i <= n; i++) {
    int j = i;
    while (j + 1 <= n && a[j + 1] == a[j]) j++;
    awal.insert(i);
    i = j;
  }
  for (int i = n; i >= 1; i--) {
    if (i < n) {
      insert(nim[i + 1]);
      nim[i] = get_nim();
      erase(nim[i + 1]);
    }
    if (awal.count(i)) {
      insert(nim[i]);
    }
  }
  nim[0] = get_nim();
  //for (int i = 0; i <= n; i++) printf("%d ", nim[i]); printf("\n");
  puts(nim[0]? "Conan" : "Agasa");
  return 0;
}
