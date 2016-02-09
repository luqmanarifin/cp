#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

struct team {
  string name;
  int point;
  int dif;
  int goal;
};

bool operator < (team a, team b) {
  if(a.point != b.point) return a.point > b.point;
  if(a.dif != b.dif) return a.dif > b.dif;
  if(a.goal != b.goal) return a.goal > b.goal;
  return a.name < b.name;
}

map<string, int> id;
map<string, int> done;
vector<team> group;
int num;

int main() {
  int tt = 5;
  while(tt--) {
    char sa[50], sb[50];
    int a, b;
    scanf("%s %s %d:%d", sa, sb, &a, &b);
    string ssa = (string) sa;
    string ssb = (string) sb;
    if(!done[ssa]) {
      id[ssa] = num++;
      team t;
      t.point = 0;
      t.dif = 0;
      t.goal = 0;
      t.name = ssa;
      group.push_back(t);
    }
    if(!done[ssb]) {
      id[ssb] = num++;
      team t;
      t.dif = 0;
      t.point = 0;
      t.goal = 0;
      t.name = ssb;
      group.push_back(t);
    }
    done[ssa]++;
    done[ssb]++;
    
    group[id[ssa]].dif += a - b;
    group[id[ssa]].goal += a;
    group[id[ssb]].dif += b - a;
    group[id[ssb]].goal += b;
    if(a > b) {
      group[id[ssa]].point += 3;
      group[id[ssb]].point += 0;  
    } else if(a < b) {
      group[id[ssa]].point += 0;
      group[id[ssb]].point += 3;
    } else {
      group[id[ssa]].point += 1;
      group[id[ssb]].point += 1;      
    }
  }
  int ber = id["BERLAND"];
  int enemy = -1;
  for(int i = 0; i < 4; i++) {
    if(done[group[i].name] == 2 && group[i].name != "BERLAND") {
      enemy = i;
      break;
    }
  }
  pair<int, int> ans = make_pair(inf, inf);
  for(int i = 1; i <= 54; i++) {
    for(int j = 0; j < i; j++) {
      vector<team> gg = group;
      gg[ber].dif += i - j;
      gg[ber].goal += i;
      gg[ber].point += 3;
      
      gg[enemy].dif += j - i;
      gg[enemy].goal += j;
      sort(gg.begin(), gg.end());
      if(gg[0].name == "BERLAND" || gg[1].name == "BERLAND") {
        ans = min(ans, make_pair(i - j, j));
      }
    }
  }
  if(ans == make_pair(inf, inf)) {
    puts("IMPOSSIBLE");
  } else {
    printf("%d:%d\n", ans.first + ans.second, ans.second);
  }
  return 0;
}