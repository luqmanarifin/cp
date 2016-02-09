#include <bits/stdc++.h>

using namespace std;

const int N = 2505;

int a[N][N], n, m, k;
char s[N][N];
long long ans;

int get(int a1, int b1, int a2, int b2) {
  return a[a2][b2] - a[a2][b1-1] - a[a1-1][b2] + a[a1-1][b1-1];
}

void dfs(int a1, int b1, int a2, int b2) {
  if(a1 == a2 && b1 == b2) {
    ans += get(a1, b1, a2, b2) == k;
    return;
  }
  if(b2 - b1 > a2 - a1) {
    int mid = (b1 + b2) >> 1;
    for(int i = a1; i <= a2; i++) {
      int cnt[2][7] = {};
      for(int j = a2; j >= i; j--) {
        for(int c = 0; c <= k; c++) {
          while(cnt[0][c] <= mid-b1 && get(i, mid-cnt[0][c], j, mid) <= c) cnt[0][c]++;
          while(cnt[1][c] < b2-mid && get(i, mid+1, j, mid+1+cnt[1][c]) <= c) cnt[1][c]++;
        }
        for(int c = 0; c <= k; c++) {
          ans += (cnt[0][c] - (c? cnt[0][c-1] : 0)) * (cnt[1][k-c] - (k-c? cnt[1][k-c-1] : 0));
        }
      }
    }
    dfs(a1, b1, a2, mid);
    dfs(a1, mid + 1, a2, b2);
  } else {
    int mid = (a1 + a2) >> 1;
    for(int i = b1; i <= b2; i++) {
      int cnt[2][7] = {};
      for(int j = b2; j >= i; j--) {
        for(int c = 0; c <= k; c++) {
          while(cnt[0][c] <= mid-a1 && get(mid-cnt[0][c], i, mid, j) <= c) cnt[0][c]++;
          while(cnt[1][c] < a2-mid && get(mid+1, i, mid+1+cnt[1][c], j) <= c) cnt[1][c]++;
        }
        for(int c = 0; c <= k; c++) {
          ans += (cnt[0][c] - (c? cnt[0][c-1] : 0)) * (cnt[1][k-c] - (k-c? cnt[1][k-c-1] : 0));
        }
      }
    }
    dfs(a1, b1, mid, b2);
    dfs(mid + 1, b1, a2, b2);
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    for(int j = 1; j <= m; j++) {
      a[i][j] = (s[i][j] == '1') + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
    }
  }
  dfs(1, 1, n, m);
  cout << ans << endl;
  return 0;
}
