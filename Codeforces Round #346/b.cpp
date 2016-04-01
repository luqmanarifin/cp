#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

struct orang {
  orang(string name, int sc) : name(name), score(sc) {
    
  }
  string name;
  int score;
};

bool cmp(orang l, orang r) {
  return l.score > r.score;
}

vector<orang> a[N];

int main() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    int id, s;
    string name;
    cin >> name >> id >> s;
    a[id].push_back(orang(name, s));
  }
  for(int i = 1; i <= m; i++) {
    sort(a[i].begin(), a[i].end(), cmp);
    if(a[i].size() > 2 && a[i][1].score == a[i][2].score) {
      puts("?");
      continue;
    }
    printf("%s %s\n", a[i][0].name.c_str(), a[i][1].name.c_str());
  }
  return 0;
}
