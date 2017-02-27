#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int n, m;
map<string, int> mp;
bool type[N];
vector<string> a[N];
int u[N], v[N];

int amin[N], amak[N];
int num[N];

int get(int p, int val) {
  num[0] = val;
  for (int i = 1; i <= n; i++) {
    if (type[i] == 0) {
      num[i] = a[i][2][p] - '0';
    } else {
      if (a[i][3] == "AND") {
        num[i] = (num[u[i]] & num[v[i]]);
      } else if (a[i][3] == "OR") {
        num[i] = (num[u[i]] | num[v[i]]);
      } else {
        num[i] = (num[u[i]] ^ num[v[i]]);
      }
    }
  }
  int ret = 0;
  for (int i = 1; i <= n; i++) ret += num[i];
  return ret;
}

int main() {
  cin >> n >> m;
  cin.ignore();
  for (int i = 1; i <= n; i++) {
    string str, buf;
    getline(cin, str);
    stringstream ss(str);
    while (ss >> buf) {
      a[i].push_back(buf);
    }
    type[i] = (a[i].size() == 5);
    mp[a[i][0]] = i;
    if (type[i]) {
      u[i] = mp[a[i][2]];
      v[i] = mp[a[i][4]];
    }
  }
  for (int j = 0; j < m; j++) {
    int nol = get(j, 0);
    int sat = get(j, 1);
    if (nol < sat) {
      amin[j] = 0;
      amak[j] = 1;
    } else if (nol == sat) {
      amin[j] = amak[j] = 0;
    } else {
      amin[j] = 1;
      amak[j] = 0;
    }
  }
  for (int j = 0; j < m; j++) printf("%d", amin[j]); printf("\n");
  for (int j = 0; j < m; j++) printf("%d", amak[j]); printf("\n");
  return 0;
}
