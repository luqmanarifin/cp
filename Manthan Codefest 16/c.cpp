#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

struct node {
  node() {
    for(int i = 0; i < 26; i++) child[i] = NULL;
    num = -1;
  }
  node* child[26];
  int num;
};

node* root;

void add(string s, int v) {
  int n = s.size();
  node* now = root;
  for(int i = 0; i < n; i++) {
    int c = s[i] - 'a';
    if(!now->child[c]) {
      now->child[c] = new node();
    }
    now = now->child[c];
  }
  now->num = v;
}

char s[N];
vector<string> str;
int b[N];

void print(int n) {
  if(n == 0) return;
  print(n - str[b[n]].size());
  printf("%s ", str[b[n]].c_str());
}

int main() {
  ios_base::sync_with_stdio(false);
  root = new node();
  
  int n;
  cin >> n >> s;
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) {
    string buf;
    cin >> buf;
    str.push_back(buf);
    transform(buf.begin(), buf.end(), buf.begin(), ::tolower);
    reverse(buf.begin(), buf.end());
    add(buf, i);
  }
  memset(b, -1, sizeof(b));
  b[0] = 0;
  for(int i = 0; i < n && b[n] == -1; i++) {
    if(b[i] == -1) continue;
    node* now = root;
    for(int j = i; j < n && b[n] == -1; j++) {
      int c = s[j] - 'a';
      if(now->child[c] == NULL) break;
      now = now->child[c];
      if(now->num != -1) {
        b[j + 1] = now->num;
      }
    }
  }
  print(n);
  return 0;
}
