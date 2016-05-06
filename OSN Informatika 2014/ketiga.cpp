#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

char junk[20];
int cnt[N];
long long s[N];

long long find(int l, int r) {
  return s[r] - (l > 0? s[l - 1] + 1LL * cnt[l - 1] * (r - l + 1) : 0);
}

int main() {
  scanf("%s", junk);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    cnt[num]++;
  }
  for(int i = 1; i < N; i++) {
    cnt[i] += cnt[i - 1];
    s[i] = s[i - 1] + cnt[i - 1];
  }
  long long ans = 1e18;
  for(int i = 1; i < N; i += 2) {
    long long cur = 0;
    int bef = -1;
    for(int j = i; j < N; j *= 2) {
      cur += find(bef + 1, j);
      bef = j;
    }
    ans = min(ans, cur);
  }
  cout << ans << endl;
  return 0;
}
