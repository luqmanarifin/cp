#include <bits/stdc++.h>

using namespace std;

const int N = 405;

int par[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

string rem(string a) {
  string ret;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 'k') {
      int j = i;
      while (j + 1 < a.size() && a[j + 1] == 'k') j++;
      if (j + 1 < a.size() && a[j + 1] == 'h') {
        ret.push_back('h');
        i = j + 1;
      } else {
        ret.push_back(a[i]);
      }
    } else {
      ret.push_back(a[i]);
    }
  }
  return ret;
}

string asu(string s) {
  string ret;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'u') {
      ret.push_back('o');
      ret.push_back('o');
    } else {
      ret.push_back(s[i]);
    }
  }
  return ret;
}

bool same(string a, string b) {
  a = rem(a);
  b = rem(b);
  return asu(a) == asu(b);
}

string s[N];
bool done[N];

int main() {
  for (int i = 0; i < N; i++) par[i] = i;
  
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (same(s[i], s[j])) {
        merge(i, j);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int u = find(i);
    if (!done[u]) {
      done[u] = 1;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
