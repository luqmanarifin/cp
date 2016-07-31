#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

map<long long, int> cnt;
vector<int> num;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i <= 30; i++) {
    num.push_back(1 << i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (auto it : num) {
      long long need = (long long) it - a[i];
      ans += cnt[need];
    }
    cnt[a[i]]++;
  }
  cout << ans << endl;
  return 0; 
}
