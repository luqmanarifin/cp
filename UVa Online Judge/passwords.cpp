#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][300];
char sr[1005][300];
int len[1005], n, m;

vector<string> all;
string st[1005];

void dfs(int brp, int dmn) {
  if (dmn == len[brp]) {
    string str;
    for (int j = 0; j < dmn; j++) {
      printf("%s", st[j].c_str());
    }
    printf("\n");
    return;
  }
  if (sr[brp][dmn] == '0') {
    for (int j = 0; j < 10; j++) {
      st[dmn] = "";
      st[dmn].push_back(j + '0');
      dfs(brp, dmn + 1);
    }
  } else {
    for (int j = 0; j < n; j++) {
      st[dmn] = s[j];
      dfs(brp, dmn + 1);
    }
  }
}

int main() {
  string a = "a";
  a += "asu";
  a += '0';
  cout << a << endl;
  
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      scanf("%s", sr[i]);
      len[i] = strlen(sr[i]);
    }
    puts("--");
    for (int i = 0; i < m; i++) {
      dfs(i, 0);
    }    
  }

  return 0;
}
