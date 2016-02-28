#include <bits/stdc++.h>

using namespace std;

const int N = 18;
const int inf = 1e9;

map<string, int> id;
int score[N], n;
int dp[1 << N];
bool can[1 << N];

int solve(int mask) {
  if(dp[mask] != -1) {
    return dp[mask];
  }
  int day = __builtin_popcount(mask) + 1;
  int& ret = dp[mask] = 0;
  for(int i = 0; i < n; i++) {
    if((mask & (1 << i)) == 0) {
      if(can[mask | (1 << i)]) {
        ret = max(ret, solve(mask | (1 << i)) + day * score[i]);
      }
    }
  }
  return ret;
}

pair<string, int> parse(string str) {
  vector<string> token;
  stringstream ss(str);
  while(ss >> str) {
    token.push_back(str);
  }
  string ret = "";
  for(int i = 0; i < (int) token.size() - 1; i++) {
    if(i) ret += " ";
    ret += token[i];
  }
  return make_pair(ret, atoi(token.back().c_str()));
}

pair<string, string> pisah(string str) {
  vector<string> token;
  stringstream ss(str);
  while(ss >> str) {
    token.push_back(str);
  }
  string a = "", b = "";
  int mid = -1;
  for(int i = 0; i < token.size(); i++) {
    if(token[i] == "-->") {
      mid = i;
      break;
    }
  }
  for(int i = 0; i < mid; i++) {
    if(i > 0) a += " ";
    a += token[i];
  }
  for(int i = mid + 1; i < token.size(); i++) {
    if(i > mid + 1) b += " ";
    b += token[i];
  }
  return make_pair(a, b);
}

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    int m;
    cin >> n >> m;
    cin.ignore();
    
    assert(1 <= n && n <= 18);
    id.clear();
    
    for(int i = 0; i < n; i++) {
      string buffer;
      getline(cin, buffer);
      pair<string, int> cok = parse(buffer);
      //cerr << cok.first << ' ' << cok.first.size() << ' ' << cok.second << endl;
      id[cok.first] = i;
      score[i] = cok.second;
    }
    vector<pair<int, int>> lim;
    while(m--) {
      string buffer;
      getline(cin, buffer);
      pair<string, string> cok = pisah(buffer);
      string a = cok.first;
      string b = cok.second;
      //cerr << a << ' ' << a.size() << ' ' << b << ' ' << b.size() << endl;
      lim.emplace_back(id[a], id[b]);
    }
    
    for(int mask = 0; mask < (1 << n); mask++) {
      can[mask] = 1;
      for(auto it : lim) {
        if((mask & (1 << it.first)) == 0 && (mask & (1 << it.second))) {
          can[mask] = 0;
          break;
        }
      }
      dp[mask] = -1;
    }
    dp[(1 << n) - 1] = 0;
    printf("%d\n", solve(0));
  } 
  
  return 0;
}