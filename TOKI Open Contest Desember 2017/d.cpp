#include <bits/stdc++.h>

using namespace std;

vector<string> ori = {
"atom",
"awak",
"bagus",
"balon",
"bisnis",
"cadar",
"copet",
"dahulu",
"dekrit",
"embargo",
"evolusi",
"fasih",
"fizz",
"fogging",
"garing",
"geboy",
"hijab",
"hilang",
"iguana",
"informasi",
"itik",
"jamur",
"kargo",
"kw",
"kwetiauw",
"lahad",
"molotov",
"nafkah",
"nasib",
"organa",
"origami",
"palu",
"pedal",
"penyu",
"quartz",
"query",
"quy",
"radix",
"rajut",
"resep",
"roket",
"rudal",
"sah",
"siluman",
"suq",
"tax",
"terlanjur",
"trap",
"ucap",
"ular",
"unific",
"versi",
"veterbrata",
"voltase",
"waham",
"warga",
"xilem",
"xilografi",
"yamin",
"yudikatif",
"zarc",
"zenit"
};

int to(int i) {
  return ori[i].back() - 'a';
}

map<long long, int> nim[26], timestamp[26];
set<int> edge[26];

// di mana dan kapan
vector<pair<int, int>> change;
int time_now;

int dfs(int at, long long mask) {
  //printf("%d %lld\n", at, mask);
  if (nim[at].count(mask)) {
    bool valid = 1;
    int cache = timestamp[at][mask];
    for (auto it : change) {
      int where = it.first;
      int when = it.second;
      if ((mask & (1LL << where)) && cache < when) {
        valid = 0;
        break;
      }
    }
    if (valid) return nim[at][mask];
  }
  for (auto it : edge[at]) {
    if (mask & (1LL << it)) continue;
    if (dfs(to(it), mask | (1LL << it)) == 0) {
      timestamp[at][mask] = time_now;
      return nim[at][mask] = 1;
    }
  }
  timestamp[at][mask] = time_now;
  return nim[at][mask] = 0;
}

int main() {
  for (int i = 0; i < ori.size(); i++) {
    edge[ori[i][0] - 'a'].insert(i);
  }

  int q;
  cin >> q;
  for (time_now = 0; time_now < q; time_now++) {
    int type;
    string s, t;
    cin >> type;
    if (type == 1) {
      cin >> s;
      for (int i = 0; i < ori.size(); i++) {
        if (ori[i] == s) {
          int ret = dfs(to(i), 1LL << i);
          puts(ret == 0? "Vega dan Mawar" : "Jebret");
          break;
        }
      }
    } else {
      cin >> s >> t;
      int ps = -1;
      for (int i = 0; i < ori.size(); i++) {
        if (ori[i] == s) {
          ps = i;
          break;
        }
      }
      assert(ps != -1);
      edge[s[0] - 'a'].erase(ps);
      edge[t[0] - 'a'].insert(ps);
      change.emplace_back(ps, time_now);
      ori[ps] = t;
    }
  }

  return 0;
}
