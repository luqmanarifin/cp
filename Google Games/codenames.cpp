#include <bits/stdc++.h>

using namespace std;

string b[] = {"airplane", "basket", "plastic", "spirit", "meltdown", "festival", "quarter", "pink", "earth"};
string t[] = {"pilot", "zoo", "battery", "mortgage", "water", "egg", "vacation", "officer", "judge", "fate", "truck", "cross", "kilometer", "radio", "cargo", "diamond"};

// {"pilot", "zoo", "battery", "mortgage", "water", "egg", "vacation", "officer", "judge", "fate", "truck", "cross", "kilometer", "radio", "cargo", "diamond"};

template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

map<string, int> id;
vector<string> apa;
int pt;

int get(string s) {
  if (!id.count(s)) {
    id[s] = pt++;
    apa.push_back(s); 
  }
  return id[s];
}

const int N = 8000;
const int inf = 1e9;

vector<int> edge[N];
int db[9][N];
int dt[16][N];

void bfs(int now, int* dist) {
  for (int i = 0; i < N; i++) dist[i] = inf;
  dist[now] = 0;
  queue<int> q;
  q.push(now);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto it : edge[now]) {
      if (dist[it] > dist[now] + 1) {
        dist[it] = dist[now] + 1;
        q.push(it);
      }
    }
  }
}

int main() {
  string str;
  while (getline(cin, str)) {
    vector<string> p = split(str, ':');
    vector<string> q = split(p[1], ',');
    int from = get(p[0]);
    for (auto it : q) {
      int to = get(it);
      edge[to].push_back(from);
      //cout << p[0] << ' ' << it << endl;
    }
  }
  for (int j = 0; j < 9; j++) {
    bfs(get(b[j]), db[j]);
  }
  for (int j = 0; j < 16; j++) {
    bfs(get(t[j]), dt[j]);
  }
  for (int i = 0; i < N; i++) {
    int farthest = -inf, nearest = inf;
    for (int j = 0; j < 9; j++) farthest = max(farthest, db[j][i]);
    for (int j = 0; j < 16; j++) nearest = min(nearest, dt[j][i]);
    if (farthest < nearest) {
      cout << apa[i] << endl;
      cerr << apa[i] << endl;
    }
  }
  return 0;
}
