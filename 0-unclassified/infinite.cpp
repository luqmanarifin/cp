#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int bit[N], n, a[N], b[N];
int arr[N];
vector<int> all;

int id(int num) {
  return lower_bound(all.begin(), all.end(), num) - all.begin();
}

void add(int at) {
  for(; at <= n; at |= at + 1) {
    bit[at]++;
  }
}

int find(int at) {
  int ret = 0;
  for(; at >= 0; at = (at & (at + 1)) - 1) {
    ret += bit[at];
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &a[i], &b[i]);
    all.push_back(a[i]);
    all.push_back(b[i]);
  }
  sort(all.begin(), all.end());
  distance(all.begin(), unique(all.begin(), all.end()));
  n = all.size();
  for(int i = 0; i < n; i++) {
    arr[i] = i;
  }
  for(int i = 0; i < n; i++) {
    swap(arr[id(a[i])], arr[id(b[i])]);
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    add(n - arr[i]);
    ans += find(n - (arr[i] + 1));
  }
  for(int i = 0; i < n; i++) {
    ans += max(0, abs(all[arr[i]] - all[i]) - 1) - max(0, abs(arr[i] - i) - 1);
  }
  cout << ans << endl;
  return 0;
}
