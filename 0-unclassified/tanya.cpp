#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int ada[256][256];
int cnt[256][256][256];
int need[256][256];
string s[N], awal;
int n;
int ans[N];

bool dfs(int pos, string pref) {
  if(pos == n) {
    return 1;
  }
  int i = lower_bound(s, s + n, pref) - s;
  string temp = s[i];
  while(i < n && pref == temp.substr(0, 2)) {
    if(cnt[s[i][0]][s[i][1]][s[i][2]]) {
      cnt[s[i][0]][s[i][1]][s[i][2]]--;
      ans[pos] = i;
      if(dfs(pos + 1, s[i].substr(1, 2))) {
        return 1;
      }
      cnt[s[i][0]][s[i][1]][s[i][2]]++;
    }
    i = upper_bound(s, s + n, temp) - s;
    temp = s[i];
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    ada[s[i][0]][s[i][1]]++;
    need[s[i][1]][s[i][2]]++;
    cnt[s[i][0]][s[i][1]][s[i][2]]++;
  }
  int st = 0;
  int fn = 0;
  for(int i = 0; i < 256; i++) {
    for(int j = 0; j < 256; j++) {
      if(ada[i][j] == need[i][j]) {
        continue;
      }
      if(ada[i][j] == need[i][j] + 1) {
        awal.push_back((char) i);
        awal.push_back((char) j);
        st++;
      }
      if(ada[i][j] + 1 == need[i][j]) {
        fn++;
      }
    }
  }
  if(!((st == 0 && fn == 0) || (st == 1 && fn == 1))) {
    puts("NO");
    return 0;
  }
  sort(s, s + n);
  if(st == 0 && fn == 0) {
    awal.push_back(s[0][0]);
    awal.push_back(s[0][1]);
  }
  if(!dfs(0, awal)) {
    puts("NO");
    return 0;
  }
  
  puts("YES");
  printf("%s", s[ans[0]].c_str());
  for(int i = 1; i < n; i++) {
    printf("%c", s[ans[i]][2]);
  }
  printf("\n");
  return 0;
}