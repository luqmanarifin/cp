#include <bits/stdc++.h>

using namespace std;

struct tree{
  int val;
  tree *l;
  tree *r;
  tree() : val(-1){l = NULL, r = NULL;}
  tree(int _val) : val(_val){l = NULL, r = NULL;}
  
};

void insert(tree *node, int _val){
  if(node->val == -1) {
    node->val = _val;
    return;
  }
  if(node->val > _val){
    //insert kiri
    if(node->l == NULL) node->l = new tree(_val);
    else insert(node->l, _val);
  }
  else if(node->val < _val){
    //insert kanan
    if(node->r == NULL) node->r = new tree(_val);
    else insert(node->r, _val);
  }
}

void make_str(tree *node, string& s){
  if(node->l != NULL){
    s += 'L';
    make_str(node->l, s);
    s += 'U';
  }
  if(node->r != NULL){
    s += 'R';
    make_str(node->r, s);
    s += 'U';
  }
}

vector<string> v;

int main() {
  
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i = 0;i < n; ++i){
    tree *root = new tree();
    for(int j = 0;j < k; ++j){
      int x;
      scanf("%d", &x);
      
      //fprintf(stderr, "MASUK\n");
      insert(root, x);
      
      //fprintf(stderr, "KELUAR\n");
    }
    //fprintf(stderr, "NYAMPE\n");
    string s = "";
    make_str(root, s);
    v.push_back(s);
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  printf("%d\n", (int) v.size());
  return 0;
}
