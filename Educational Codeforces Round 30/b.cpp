#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int offset = 1e5;

int first[N], last[N];
char s[N];

int main() {
  memset(first, -1, sizeof(first));
  
  int n;
  scanf("%d %s", &n, s);
  int now = offset;
  first[now] = last[now] = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      now++;
    } else {
      now--;
    }
    if (first[now] == -1) {
      first[now] = i + 1;
    }
    last[now] = i + 1;
  }
  int ans = 0;
  for (int i = 0; i < N; i++) if (first[i] != -1) ans = max(ans, last[i] - first[i]);
  cout << ans << endl;
  return 0;
}
