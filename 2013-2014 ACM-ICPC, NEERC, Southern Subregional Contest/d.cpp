#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int a[N];

void ask(vector<int>& p) {
  printf("%d\n", p.size());
  for (int i = 0; i < p.size(); i++) {
    printf("%d%c", p[i], " \n"[i + 1 == p.size()]);
  }
  fflush(stdout);
}

int read() {
  int v;
  scanf("%d", &v);
  return v;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    vector<int> one, zer;
    
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      vector<int> p = {i};
      ask(p);
      int v = read();
      if (v == 1) {
        one.push_back(i);
      } else {
        zer.push_back(i);
      }
    }
    int n1 = one.size();
    int n0 = zer.size();
    for (auto it : one) {
      zer.push_back(it);
      ask(zer);
      int v = read();
      if (v > 0) {
        a[it] = 1;
      } else {
        a[it] = 3;
      }
      zer.pop_back();
    }
    for (auto it : zer) {
      one.push_back(it);
      ask(one);
      int v = read();
      if (v == n1 + 1) {
        a[it] = 3;
      } else {
        a[it] = 2;
      }
      one.pop_back();
    }
    printf("-1\n");
    for (int i = 1; i <= n; i++) {
      printf("%d%c", a[i], " \n"[i == n]);
    }
    fflush(stdout);
  }

  return 0;
}
