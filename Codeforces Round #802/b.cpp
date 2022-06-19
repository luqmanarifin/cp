#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char buf[N];
int s[N], ans[N], goal[N];

void add(int* a, int i, int val) {
  a[i] += val;
  if (a[i] >= 10) {
    add(a, i + 1, a[i] / 10);
    a[i] %= 10;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(ans, 0, sizeof(ans));
    memset(goal, 0, sizeof(goal));
    memset(s, 0, sizeof(s));

    int n;
    scanf("%d %s", &n, buf);
    reverse(buf, buf + n);
    for (int i = 0; i < n; i++) s[i] = buf[i] - '0';

    goal[n - 1] = s[n - 1];
    add(goal, n - 1, 2);
    int len = (goal[n]? n + 1 : n);
    for (int i = 0; i < len - 1 - i; i++) {
      goal[i] = goal[len - 1 - i];
    }
    for (int i = 0; i < n; i++) {
      if (goal[i] < s[i]) {
        for (int j = i + 1; ; j++) {
          if (goal[j]) {
            goal[j]--;
            break;
          } else {
            goal[j] = 9;
          }
        }
        goal[i] += 10;
      }
      ans[i] = goal[i] - s[i];
    }

    for (int i = n - 1; i >= 0; i--) printf("%d", ans[i]); printf("\n");
  }


  return 0;
}
