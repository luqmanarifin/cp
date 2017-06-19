#include <iosfwd>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  Solution(istream& s) {

  }
  class iterator {
  public:
    iterator(const iterator&) {

    }
    iterator operator++() {
      return 0;
    }
    int operator*() const {
      return 0;
    }
  };

  iterator begin() {
    return 0;
  }
  iterator end() {
    return 0;
  }
};

int main() {
  filebuf fb;
  if (fb.open("a.txt", ios::in)) {
    istream stream(&fb);
    Solution sol(stream);
    for (Solution::iterator it = sol.begin(); it != sol.end(); ++it) {
      int x = *it;
      cout << x << endl;
    }
    fb.close();
  }
}