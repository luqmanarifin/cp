#include <bits/stdc++.h>

using namespace std;

const string NAME = "binary";

void print(int num, int n) {
  for (int i = n - 1; i >= 0; i--) {
    if (num & (1 << i)) {
      printf("1");
    } else {
      printf("0");
    }
  }
  printf("\n");
}

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif
  
  int m;
  scanf("%d", &m);
  int n = 0;
  while ((1 << n) < m) n++;
  if ((1 << n) == m) {
    for (int i = 0; i < m; i++) {
      print(i, n);
    }
    return 0;
  }
  set<int> s;
  for (int i = 0; i < (1 << n); i++) {
    s.insert(i);
  }
  int udah = 0;
  for (int i = 0; i < m; i++) {
    int need = m - i - 1;
    int ada = s.size() - 2;
    if (need <= ada) {
      print(i, n - 1);
      s.erase((i << 1));
      s.erase((i << 1) + 1);
      udah++;
    } else {
      break;
    }
  }
  int ans = m - udah;
  while (ans--) {
    int now = *(s.begin());
    print(now, n);
    s.erase(now);
  }

#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif

  return 0;
}
