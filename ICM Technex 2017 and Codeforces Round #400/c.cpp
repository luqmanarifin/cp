#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e17;

map<long long, int> cnt;
int a[N];

int main() {
  int n, k;
  long long sum = 0;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
    cnt[sum]++;
  }
  long long now = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long power = 1;
    int kali = 0;
    while (abs(power) <= inf) {
      ans += cnt[now + power];
      power *= k;
      kali++;
      if (kali == 1 && k == 1) break;
      if (kali == 2 && k == -1) break;
    }
    now += a[i];
    cnt[now]--;
  }
  cout << ans << endl;
  return 0;
}