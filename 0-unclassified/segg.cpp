#include <iostream>
#include <vector>
 
using namespace std;
 
struct SegmentTreeNode {
  int sum, left, right;
  SegmentTreeNode* leftChild;
  SegmentTreeNode* rightChild;
 
  SegmentTreeNode(int sum, int left, int right, SegmentTreeNode* leftChild, SegmentTreeNode* rightChild)
    : sum(sum), left(left), right(right), leftChild(leftChild), rightChild(rightChild) { }
};
 
SegmentTreeNode* buildSegmentTree(vector<int> &data, int l, int r) {
  // ADD YOUR CODE HERE
  if(l == r) {
    SegmentTreeNode* ret = new SegmentTreeNode(data[l], l, r, NULL, NULL);
    return ret;
  }
  int mid = (l + r) >> 1;
  SegmentTreeNode* lef = buildSegmentTree(data, l, mid);
  SegmentTreeNode* rig = buildSegmentTree(data, mid + 1, r);
  SegmentTreeNode* ret = new SegmentTreeNode(lef->sum + rig->sum, l, r, lef, rig);
  return ret;
}
 
void print(SegmentTreeNode* node) {
  if (node == NULL) cout << "-";
  else {
    cout << "[ " << node->sum << ' ' << node->left << ' ' << node->right << ' ';
    print(node->leftChild);
    cout << ' ';
    print(node->rightChild);
    cout << " ]";
  }
}
 
int main() {
  ios_base::sync_with_stdio(false);
  int n; cin >> n;
 
  vector<int> data(n);
  for (int i = 0 ; i < n ; i++) cin >> data[i];
 
  SegmentTreeNode* root = buildSegmentTree(data, 0, (int) data.size() - 1);
  print(root);
}