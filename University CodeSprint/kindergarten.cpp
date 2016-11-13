#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N];
int bit[N];

void add(int i, int v) {
  for (; i < N; i |= i + 1) {
    bit[i] += v;
  }
}

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    ret += bit[i];
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i + n] = a[i];
    a[i + n] += n - i;
    a[i] += 2 * n - i;
  }
  for (int i = 0; i < n; i++) add(a[i], 1);
  
  int best = -1, p = -1;
  int now = 2 * n;
  for (int i = 0; i < n; i++) {
    int cur = find(now);
    if (cur > best) {
      best = cur;
      p = i;
    }
    
    add(a[i], -1);
    add(a[i + n], 1);
    now--;
  }  
  cout << p + 1 << endl;
  return 0;
}
