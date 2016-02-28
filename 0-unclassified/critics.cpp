#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int add[N];
vector<int> b;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int bef = -1;
  for(int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    if(bef != a) {
      b.push_back(a);
    }
    bef = a;
  }
  if(b.size() == 1) {
    cout << b[0] << endl;
    return 0;
  }
  int tot = b.size() - 1, ans = -1;
  add[b[0]]--;
  add[b.back()]--;
  for(int i = 1; i < b.size() - 1; i++) {
    add[b[i]] -= 2;
    if(b[i + 1] != b[i - 1]) {
      add[b[i]]++;
    }
  }
  int cos = 1e9;
  for(int i = 1; i <= k; i++) {
    if(tot + add[i] < cos) {
      cos = tot + add[i];
      ans = i;
    }
  }  
  cout << ans << endl;
  return 0;
}