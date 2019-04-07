#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N];
int a[] = {0, 1, 1, 1, 2, 2, 3, 5, 5, 8};
int b[] = {0, 0, 1, 2, 2, 3, 3, 2, 3, 1};

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%s", s);
    int n = strlen(s);
    printf("Case #%d: ", tt);
    deque<int> p, q;
    for (int i = 0; i < n; i++) {
      p.push_back(a[s[i]-'0']);
      q.push_back(b[s[i]-'0']);
    }
    while (p.front() == 0) p.pop_front();
    while (q.front() == 0) q.pop_front();
    for (int i = 0; i < p.size(); i++) printf("%d", p[i]); printf(" ");
    for (int i = 0; i < q.size(); i++) printf("%d", q[i]); printf("\n");
  }
  return 0;
}
