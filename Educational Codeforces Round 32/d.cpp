
#include <bits/stdc++.h>

using namespace std;

long long c(int n, int k) {
  k = min(k, n - k);
  long long ans = 1;
  for (int i = 0; i < k; i++) {
    ans *= (n - i);
    ans /= i + 1;
  }
  return ans;
}

int gain[5], a[10];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  
  for (int len = 1; len <= 4; len++) {
    for (int i = 0; i < len; i++) a[i] = i;
    do {
      bool good = 1;
      for (int i = 0; i < len; i++) if (a[i] == i) good = 0;
      if (good) gain[len]++;
    } while (next_permutation(a, a + len));
  }
  
  long long ret = 1;
  for (int i = 2; i <= k; i++) ret += gain[i] * c(n, i);
  cout << ret << endl;
  return 0;
}
