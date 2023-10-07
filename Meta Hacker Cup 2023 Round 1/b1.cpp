#include <bits/stdc++.h>

using namespace std;

const int MAGIC = 32000;

bool is[MAGIC];
vector<int> p;

int main() {
  for (int i = 2; i < MAGIC; i++) {
    if (!is[i]) {
      p.push_back(i);
      for (int j = i * i; j < MAGIC; j += i) {
        is[j] = 1;
      }
    }
  }
  // printf("prime %d\n", p.size());

  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    vector<int> facs;
    for (auto it : p) {
      while (n % it == 0) {
        facs.push_back(it);
        n /= it;
      }
    }
    if (n > 1) facs.push_back(n);

    // for (auto it : facs) printf("%d ", it);

    int sum = 0;
    for (auto it : facs) sum += it;
    for (int i = 0; i < 41 - sum; i++) facs.push_back(1);
    printf("Case #%d: ", tt);
    if (sum <= 41) {
      printf("%d ", facs.size());
      for (int i = 0; i < facs.size(); i++) {
        printf("%d%c", facs[i], i + 1 == facs.size()? '\n' : ' ');
      }
    } else {
      printf("-1\n");
    }
  }

  return 0;
}
