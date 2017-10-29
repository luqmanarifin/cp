#include <bits/stdc++.h>

using namespace std;

int a[101];
bool cek(int x, int n) {
  vector<int> ganjil, genap;
  for (int i = 0; i < n; i++) {
    if (i & 1) 
      ganjil.push_back(x & 1);
    else
      genap.push_back(x & 1);
    x >>= 1;
  }
  bool ok = 1;
  for (int i = 0; i < ganjil.size(); i++)
    ok &= (ganjil[i] == ganjil[(int)ganjil.size()-1-i]);
  if (ok) return 1;
  ok = 1;
  for (int i = 0; i < genap.size(); i++)
    ok &= (genap[i] == genap[(int)genap.size()-1-i]);
  if (ok) return 1;
  return false;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0, cnt = 1; i < (1<<n); i++) {
    if (cek(i, n)) {
      cout << cnt << " ";
      for (int j = n-1; j >= 0; j--)
        cout << ((i & (1 << j)) ? "1" : "0");
      cout << endl;
      cnt++;
    }
  }

  return 0;
}