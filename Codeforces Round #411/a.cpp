#include <bits/stdc++.h>

using namespace std;

int main() { 
  int n;
  scanf("%d", &n);
  int k = (n + 1) / 2;
  cout << max(0, k - 1) << endl;
  return 0;
}
