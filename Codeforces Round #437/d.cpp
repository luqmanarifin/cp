
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  multiset<int> plus, minus, unused;
  long long ans = 0;
  for (auto x : a) {
    //printf("before %d\n", x);
    //printf("plus: "); for (auto it : plus) printf("%d ", it); printf("\n");
    //printf("minus: "); for (auto it : minus) printf("%d ", it); printf("\n");
    //printf("unused: "); for (auto it : unused) printf("%d ", it); printf("\n");
    //printf("\n");
    
    if (!unused.empty()) {
      int z = *(unused.begin());
      if (z < x) {
        if (!plus.empty() && *(plus.begin()) < z) {
        } else {
          plus.insert(x);
          minus.insert(z);
          unused.erase(unused.find(z));
          ans += x - z;
          continue;
        }
      }
    }
    if (!plus.empty()) {
      int z = *(plus.begin());
      if (z < x) {
        plus.insert(x);
        plus.erase(plus.find(z));
        unused.insert(z);
        ans += x - z;
        continue;
      }
    }
    unused.insert(x);
  }
  cout << ans << endl;
  return 0;
}
