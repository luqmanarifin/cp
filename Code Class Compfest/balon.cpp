#include <bits/stdc++.h>

using namespace std;

const int N = 50;

int len[N];
int a[N][N];

string str;
int at[256];

int p[N];

int main() {
  at['m'] = at['k'] = at['b'] = 0;
  at['a'] = at['p'] = 1;
  at['h'] = 2;

  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    printf("Kasus #%d\n", tt);
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
      getline(cin, str);
      len[i] = (str.size() + 1) / 2;
      for (int j = 0; j < str.size(); j += 2) {
        a[i][j / 2] = at[str[j]];
      } 
    }

    memset(p, 0, sizeof(p));
    queue<int> q[3];
    for (int i = 0; i < n; i++) {
      q[a[i][0]].push(i);
    }
    int seller = 0;
    while (!q[0].empty() || !q[1].empty() || !q[2].empty()) {
      if (!q[seller].empty()) {
        int now = q[seller].front();
        q[seller].pop();
        printf("Pembeli #%d\n", now + 1);
        int til = p[now] + 1;
        while (til < len[now] && a[now][til] == a[now][til - 1]) til++;
        int other = 0;
        for (int i = 0; i < 3; i++) {
          other += q[i].size();
        }
        if (other > 0) {
          til = min(til, p[now] + 5);
        }
        p[now] = til;
        if (til < len[now]) {
          q[a[now][til]].push(now);
        }
      }
      seller = (seller + 1) % 3;
    }
  }

  return 0;
}
