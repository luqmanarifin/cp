#include <bits/stdc++.h>

using namespace std;

const int N = 20;

map<string, int> id;
int score[N], beban[N];
vector<int> child[N];

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    cin.ignore();
    id.clear();
    for(int i = 0; i < N; i++) {
      beban[i] = 0;
      score[i] = 0;
      child[i].clear();
    }
    
    for(int i = 0; i < n; i++) {
      string buffer;
      getline(cin, buffer);
      stringstream ss(buffer);
      string bef = "", name = "";
      int awal = 2;
      while(ss >> buffer) {
        awal--;
        if(awal < 0) name += " ";
        name += bef;
        bef = buffer;
        
      }
      id[name] = i;
      score[i] = atoi(bef.c_str());
    }
    while(m--) {
      string buffer;
      getline(cin, buffer);
      stringstream ss(buffer);
      bool awal = 1, lewat = 0;
      string a = "", b = "";
      while(ss >> buffer) {
        if(buffer == "-->") {
          awal = 1;
          lewat = 1;
          continue;
        }
        if(!lewat) {
          if(!awal) a += " ";
          a += buffer;
        } else {
          if(!awal) b += " ";
          b += buffer;
        }
        awal = 0;
      }
      child[id[a]].push_back(id[b]);
      beban[id[b]]++;
    }
    vector<int> seq;
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; i++) {
      if(beban[i] == 0) {
        pq.emplace(-score[i], i);
      }
    }
    while(!pq.empty()) {
      int now;
      tie(ignore, now) = pq.top();
      pq.pop();
      seq.push_back(now);
      for(auto it : child[now]) {
        beban[it]--;
        if(beban[it] == 0) {
          pq.emplace(-score[it], it);
        }
      }
    }
    bool valid = 1;
    for(int i = 0; i < n; i++) {
      if(beban[i]) valid = 0;
    }
    if(!valid) {
      puts("0");
      continue;
    }
    int ans = 0;
    for(int i = 0; i < seq.size(); i++) {
      ans += (i + 1) * score[seq[i]];
    }
    printf("%d\n", ans);
  } 
  
  return 0;
}
