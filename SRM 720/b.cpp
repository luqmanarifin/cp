#include <bits/stdc++.h>

using namespace std;

class DistinctGrid {
public:
  vector<int> findGrid(int n, int k) {
    vector<int> a(n * n);
    int num = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if ((i + j) % n < k - 1) {
          a[i * n + j] = num++;
        }
      }
    }
    return a;
  }
};