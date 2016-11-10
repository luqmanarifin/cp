#include <bits/stdc++.h>

using namespace std;

const int N = 305;
const long long mod = 1e15 + 37;
const long long PRIME = 90000;

int a[N], b[N];
long long tmp[3];

vector<long long> all;

long long dist(int i, int j) {
  return 1LL * (a[i] - a[j]) * (a[i] - a[j]) + 1LL * (b[i] - b[j]) * (b[i] - b[j]); 
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", a + i, b + i);
  vector<long long> p;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      long long d = dist(i, j);
      all.push_back(d);
    }
  }
  sort(all.begin(), all.end());
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        tmp[0] = dist(i, j);
        tmp[1] = dist(j, k);
        tmp[2] = dist(i, k);
        for (int l = 0; l < 3; l++) {
          int at = lower_bound(all.begin(), all.end(), tmp[l]) - all.begin();
          tmp[l] = at;
        }
        sort(tmp, tmp + 3);
        p.push_back(tmp[0] * PRIME * PRIME + tmp[1] * PRIME + tmp[2]);
      }
    }
  }
  sort(p.begin(), p.end());
  long long ans = 0;
  for (int i = 0; i < p.size(); i++) {
    int j = i;
    while (j + 1 < p.size() && p[j + 1] == p[j]) j++;
    int cnt = j - i + 1;
    //printf("cnt %d\n", cnt);
    ans += 1LL * cnt * (cnt - 1) / 2;
    i = j;
  }
  cout << ans << endl;
  return 0;
}
