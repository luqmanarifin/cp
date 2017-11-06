#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int a[N];
char s[N];

int main() {
  int k;
  scanf("%d %s", &k, s);
  int n = strlen(s);
  vector<pair<char, int>> p;
  for (int i = 0; i < n; i++) {
    if (s[i] != '=') {
      p.emplace_back(s[i], i);
    }
  }
  memset(a, -1, sizeof(a));
  char last = '*';
  int ada = 0;
  for (auto it : p) {
    if (it.first != last) {
      last = it.first;
      ada = 1;
    } else {
      ada++;
    }
    if (ada >= k) {
      puts("-1");
      return 0;
    }
  }
  bool ujung = 0;
  for (int i = 0; i + 1 < p.size(); i++) {
    if (p[i].first == '>' && p[i + 1].first == '<') {
      ujung = 1;
      a[p[i].second + 1] = 0;
    }
    if (p[i].first == '<' && p[i + 1].first == '>') {
      ujung = 1;
      a[p[i].second + 1] = k - 1;
    }
  }
  if (!ujung) {
    if (p.size() && p[0].first == '>') {
      a[0] = k - 1;
    } else {
      a[0] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] != -1 && a[i + 1] == -1) {
      if (s[i] == '>') {
        a[i + 1] = a[i] - 1;
      } else if (s[i] == '=') {
        a[i + 1] = a[i];
      } else {
        a[i + 1] = a[i] + 1;
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i + 1] != -1 && a[i] == -1) {
      if (s[i] == '>') {
        a[i] = a[i + 1] + 1;
      } else if (s[i] == '=') {
        a[i] = a[i + 1];
      } else {
        a[i] = a[i + 1] - 1;
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    assert(a[i] != -1);
    printf("%c", a[i] + 'a');
  }
  
  return 0;
}
