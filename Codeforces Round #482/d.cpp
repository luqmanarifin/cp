#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;
const int BIT = 20;

struct trie {
  trie() {
    c[0] = NULL;
    c[1] = NULL;
    t = inf;
  }
  trie(int time) {
    c[0] = NULL;
    c[1] = NULL;
    t = time;
  }
  int t;
  trie* c[2];
};

trie* null;

trie* insert(trie* root, int num, int bit, int time) {
  
}

int main() {
  null = new trie();
  null->c[0] = null;
  null->c[1] = null;
  
  
 
  return 0;
}
