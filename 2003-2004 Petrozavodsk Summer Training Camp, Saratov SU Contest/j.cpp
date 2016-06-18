#include <bits/stdc++.h>

using namespace std;

void file_io(string str) {
  freopen((str + ".in").c_str(), "r", stdin);
  freopen((str + ".out").c_str(), "w", stdout);
}

char s[15][15];
bool done[15][15];

int da[] = {0, 0, -1, 1, 1, 1, -1, -1};
int db[] = {1, -1, 0, 0, -1, 1, -1, 1};

bool valid(int i, int j) {
  return 0 <= i && i < 10 && 0 <= j && j < 10;
}

vector<pair<int, int>> dfs(int i, int j) {
  vector<pair<int, int>> ret;
  if(!valid(i, j) || s[i][j] != '*' || done[i][j]) {
    return ret;
  }
  done[i][j] = 1;
  ret.emplace_back(i, j);
  for(int k = 0; k < 8; k++) {
    auto v = dfs(i + da[k], j + db[k]);
    for(auto it : v) {
      ret.push_back(it);
    }
  }
  return ret;
}

vector<int> source = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};

int main() {
  file_io("sea");
  
  int t;
  scanf("%d", &t);
  while(t--) {
    for(int i = 0; i < 10; i++) scanf("%s", s[i]);
    memset(done, 0, sizeof(done));
    bool valid = 1;
    vector<int> all;
    for(int i = 0; i < 10; i++) {
      for(int j = 0; j < 10; j++) {
        if(!done[i][j] && s[i][j] == '*') {
          auto ret = dfs(i, j);
          sort(ret.begin(), ret.end());
          if(ret.size() > 1) {
            bool si;
            if(ret[1].first == ret[0].first) {
              si = 1;
            } else if(ret[1].second == ret[0].second) {
              si = 0;
            } else {
              valid = 0;
            }
            if(si) {
              for(int i = 1; i < ret.size(); i++) {
                if(ret[i].first != ret[i - 1].first || ret[i].second != ret[i - 1].second + 1) {
                  valid = 0;
                  break;
                }
              }
            } else {
              for(int i = 1; i < ret.size(); i++) {
                if(ret[i].second != ret[i - 1].second || ret[i].first != ret[i - 1].first + 1) {
                  valid = 0;
                  break;
                }
              }
            }
            if(valid) {
              all.push_back(ret.size());
            }
          } else {
            all.push_back(ret.size());
          }
        }
      }
    }
    sort(all.begin(), all.end());
    if(all.size() != source.size()) {
      valid = 0;
    } else {
      for(int i = 0; i < all.size(); i++) {
        if(all[i] != source[i]) {
          valid = 0;
        }
      }
    }
    puts(valid? "YES" : "NO");
  }

  return 0;
}
