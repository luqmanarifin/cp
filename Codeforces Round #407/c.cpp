#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int inf = 1e9;

vector<int> a;
int* dp_pos;
int* dp_neg;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < k; i++) {
    int v;
    scanf("%d", &v);
    a.push_back(v);
  }
  sort(a.begin(), a.end());
  a.resize(distance(a.begin(), unique(a.begin(), a.end())));
  k = a.size();
  
  vector<int> pos, neg;
  for (int i = 0; i < k; i++) {
    if (a[i] < n) {
      neg.push_back(n - a[i]);
    } else if (a[i] > n) {
      pos.push_back(a[i] - n);
    } else {
      puts("1");
      return 0;
    }
  }
  sort(pos.begin(), pos.end());
  sort(neg.begin(), neg.end());
  if (pos.empty() || neg.empty()) {
    puts("-1");
    return 0;
  }
  
  int SIZE = pos.back() * neg.back() + 1;
  dp_pos = new int[SIZE];
  dp_neg = new int[SIZE];
  for (int i = 0; i < SIZE; i++) {
    dp_pos[i] = inf;
    dp_neg[i] = inf;
  }
  dp_pos[0] = dp_neg[0] = 0;
  for (int i = 0; i < pos.size(); i++) {
    for (int j = pos[i]; j < SIZE; j++) {
      dp_pos[j] = min(dp_pos[j], dp_pos[j-pos[i]] + 1);
    }
  }
  for (int i = 0; i < neg.size(); i++) {
    for (int j = neg[i]; j < SIZE; j++) {
      dp_neg[j] = min(dp_neg[j], dp_neg[j-neg[i]] + 1);
    }
  }
  int ans = inf;
  for (int i = 1; i < SIZE; i++) {
    ans = min(ans, dp_pos[i] + dp_neg[i]);
  }
  cout << ans << endl;
  return 0;
}
