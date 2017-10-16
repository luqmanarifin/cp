#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
int nor[N][20], rmq[N][20];

int find_or(int l, int r) {
  int g = __builtin_clz(r - l + 1) ^ 31;
  return nor[l][g] | nor[r-(1<<g)+1][g];
}

int find_max(int l, int r) {
  int g = __builtin_clz(r - l + 1) ^ 31;
  return max(rmq[l][g], rmq[r-(1<<g)+1][g]);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    nor[i][0] = rmq[i][0] = a[i];
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
      nor[i][j] = (nor[i][j-1] | nor[i+(1<<(j-1))][j-1]);
      rmq[i][j] = max(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int j = i - 1;
    while (j >= 0) {
      int now_or = find_or(j, i);
      
      int l = 0, r = j;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (find_or(mid, i) == now_or) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      int p = l;
      
      l = p; r = j;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (find_max(mid, i) >= now_or) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      //printf("wow %d %d %d %d\n", p, l, j, i);
      if (find_max(l, i) < now_or) {
        //printf("nambah %d\n", j - l);
        ans += j - l + 1;
      }
      j = p - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
