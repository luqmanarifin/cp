#include <bits/stdc++.h>

using namespace std;

const int N = 1e8 + 5;
const int sm = 3e6 + 5;

// val, id
pair<int, int> num[N];
vector<int> minta[sm];
map<string, int> value;

string s[3][10005];
int a[3][10005];
pair<int, int> ans[10005];
int tc[10005];

int main() {

  int m;
  for(int i = 0; i < 3; i++) {
    cin >> m;
    for(int j = 0; j < m; j++) {
      cin >> s[i][j] >> a[i][j];
      value[s[i][j]] = a[i][j];
    }
  }
  int id = 0;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < m; j++) {
      num[id++] = make_pair(a[0][i] + a[1][j], i * m + j);
    }
  }
  sort(num, num + id);
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) {
    int v = 0;
    for(int j = 0; j < 3; j++) {
      string str;
      cin >> str;
      v += value[str];
    }
    tc[i] = v;
    minta[v + 1].push_back(i);
  }
  int done = 0;
  for(int v = 0; v < sm; v++) {
    int j = 0;
    for(int i = 0; i < m; i++) {
      if(j == minta[v].size()) {
        break;
      }
      int find = v - a[2][i];
      int low = lower_bound(num, num + id, make_pair(find, -1)) - num;
      int upp = upper_bound(num, num + id, make_pair(find, N)) - num;
      for(int it = low; it < upp && j < minta[v].size(); it++) {
        ans[minta[v][j++]] = make_pair(num[it].second, i);
        cerr << ++done << " done!" << endl;
      }
    }
  }
  for(int i = 0; i < q; i++) {
    int fs = ans[i].first;
    int sc = ans[i].second;
    cout << s[0][fs / m] << ' ' << s[1][fs % m] << ' ' << s[2][sc] << endl;
    assert(tc[i] + 1 == a[0][fs / m] + a[1][fs % m] + a[2][sc]);
  }
  
  return 0;
}
