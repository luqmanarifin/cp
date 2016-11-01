#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];
int clef[N], crig[N];
long long lef[N], rig[N];

int main() {
  int n;
  scanf("%d %s", &n, s + 1);
  vector<int> U, D;
  for (int i = 1; i <= n; i++) {
    clef[i] = clef[i - 1] + (s[i - 1] == 'U');
    if (s[i] == 'U') {
      U.push_back(i);
    } else {
      D.push_back(i);
    }
  }
  for (int i = n; i >= 1; i--) {
    crig[i] = crig[i + 1] + (s[i + 1] == 'D');
  }
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'U') {
      lef[i] = i;
    }
    lef[i] += lef[i - 1];
  }
  for (int i = n; i >= 1; i--) {
    if (s[i] == 'D') {
      rig[i] = N - i;
    }
    rig[i] += rig[i + 1];
  }
  for (int i = 1; i <= n; i++) {
    int ada_lef = clef[i];
    int ada_rig = crig[i];
    int k;
    if (s[i] == 'U') {
      k = min(ada_lef + 1, ada_rig);
    } else {
      k = min(ada_lef, ada_rig + 1);
    }
    int asli_lef = min(ada_lef, k);
    int asli_rig = min(ada_rig, k);
    long long ans = 0;
    //printf("%d %d %d\n", asli_lef, asli_rig, k);
    if (asli_lef) {
      int at = lower_bound(U.begin(), U.end(), i) - U.begin() - asli_lef;
      //printf("U[at] %d %I64d\n", U[at], (1LL * asli_lef * i - (lef[i] - lef[U[at] - 1])));
      ans += 2 * abs(1LL * asli_lef * i - (lef[i-1] - lef[U[at] - 1]));
    }
    //cout << ans << endl;
    if (asli_rig) {
      int at = upper_bound(D.begin(), D.end(), i) - D.begin() - 1 + asli_rig;
     // printf("D[at] %d %I64d\n", D[at], abs(1LL * asli_rig * (N - i) - (rig[i] - rig[D[at] + 1])));
      //printf("cok %I64d\n", (rig[i] - rig[D[at] + 1]));
      ans += 2 * abs(1LL * asli_rig * (N - i) - (rig[i+1] - rig[D[at] + 1]));
    }
    //cout << ans << endl;
    if (s[i] == 'U') {
      if (asli_lef == asli_rig) {
        ans += (n + 1) - i;
      } else {
        ans += i;
      }
    } else {
      if (asli_lef == asli_rig) {
        ans += i;
      } else {
        ans += (n + 1) - i;
      }
    }
    printf("%I64d ", ans);
  }

  return 0;
}
