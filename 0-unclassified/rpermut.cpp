#include <bits/stdc++.h>

/**
 * biar terluka
 * biar tersiksa
 * aku cuma bisa
 * mencintaimu..
 *
 * Bandung, 7 Februari 2014
 */

using namespace std;

vector<string> con;
int a[10];

void solve_small(int n, int m) {
  int until = 1;
  for(int i = 1; i <= n; i++) {
    a[i] = i;
    until *= i;
  }
  int ans = 0;
  while(until--) {
    int cur = 0;
    for(int i = 1; i <= n; i++) {
      int mini = 1e9;
      for(int j = i; j <= n; j++) {
        mini = min(mini, a[j]);
        cur += mini;
      }
    }
    string s = "";
    for(int i = 1; i <= n; i++) {
      s.push_back(a[i] + '0');
    }
    if(cur > ans) {
      ans = cur;
      con.clear();
      con.push_back(s);
    } else if(cur == ans) {
      con.push_back(s);
    }
    next_permutation(a + 1, a + 1 + n);
  }
  sort(con.begin(), con.end());
  cout << con.size() << endl;
  for(int i = 0; i < con.size(); i++) {
    cout << i << ' ' << con[i] << endl;
  }
  for(int i = 0; i < n; i++) {
    printf("%c ", con[m - 1][i]);
  }
  printf("\n");
  exit(0);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if(n <= 8) solve_small(n, m);
  for(int i = 1; i <= n - 3; i++) {
    printf("%d ", i);
  }
  switch(m) {
    case 1 : printf("%d %d %d\n", n - 2, n - 1, n); break;
    case 2 : printf("%d %d %d\n", n - 2, n, n - 1); break;
    case 3 : printf("%d %d %d\n", n - 1, n, n - 2); break;
    case 4 : printf("%d %d %d\n", n, n - 1, n - 2); break;
  }
  return 0;
}