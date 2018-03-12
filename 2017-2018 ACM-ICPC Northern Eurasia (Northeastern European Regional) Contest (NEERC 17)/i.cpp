#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int ev[N], od[N];
int n;
vector<int> el[N];

void answer() {
  printf("!");
  for (int i = 1; i <= n / 2; i++) printf(" %d", ev[i]);
  for (int i = 1; i <= n / 2 + n % 2; i++) printf(" %d", od[i]);
  printf("\n");
  fflush(stdout);
  exit(0);
}

char ask(int i, int j) {
  printf("? %d %d\n", i, j);
  fflush(stdout);
  char c;
  scanf(" %c", &c);
  return c;
}

int main() {
  scanf("%d", &n);
  if (n == 1) {
    od[1] = 1;
    answer();
  }
  for (int i = 1; i <= n / 2 + n % 2; i++) {
    el[0].push_back(i);
  }
  set<pair<int, int>> s;
  s.insert(make_pair(0, 0));

  int pt = 1;
  for (int i = 1; i <= n / 2; i++) {
    int l = 1, r = n / 2;
    while (l < r) {
      int mid = (l + r) >> 1;
      auto p = s.lower_bound(make_pair(mid + 1, -1));
      if (p != s.end() && p->first < r) {   // ambil dua
        auto q = p;
        p--;
        char ca = ask(i, el[p->second][0]);
        char cb = ask(i, el[q->second][0]);
        if (ca == '>' && cb == '>') {
          l = q->first;
        } else if (ca == '<' && cb == '<') {
          r = q->first;
        } else {
          vector<int> b_a, k_a, b_b, k_b;
          for (auto it : el[p->second]) {
            char c = ask(i, it);
            if (c == '>') {
              b_a.push_back(it);
            } else {
              k_a.push_back(it);
            }
          }
          for (auto it : el[q->second]) {
            char c = ask(i, it);
            if (c == '>') {
              b_b.push_back(it);
            } else {
              k_b.push_back(it);
            }
          }
          if (b_a.size() < el[p->second].size()) {
            l = r = p->first + b_a.size();
            if (0 < b_a.size() && b_a.size() < el[p->second].size()) {
              el[pt++] = b_a;
              el[pt++] = k_a;
              s.insert(make_pair(p->first, pt - 2));
              s.insert(make_pair(p->first + b_a.size(), pt - 1));
              s.erase(p);
            }
          } else {
            l = r = q->first + b_b.size();
            if (0 < b_b.size() && b_b.size() < el[q->second].size()) {
              el[pt++] = b_b;
              el[pt++] = k_b;
              s.insert(make_pair(q->first, pt - 2));
              s.insert(make_pair(q->first + b_b.size(), pt - 1));
              s.erase(q);
            }
          }
          break;
        }
      } else {                              // ambil satu
        p--;
        vector<int> b, k;
        for (auto it : el[p->second]) {
          char c = ask(i, it);
          if (c == '>') {
            b.push_back(it);
          } else {
            k.push_back(it);
          }
        }
        if (b.size() == 0) {
          r = p->first;
        } else if (b.size() == el[p->second].size()) {
          l = p->first + el[p->second].size();
        } else {
          l = r = p->first + b.size();
          el[pt++] = b;
          el[pt++] = k;
          s.insert(make_pair(p->first, pt - 2));
          s.insert(make_pair(p->first + b.size(), pt - 1));
          s.erase(p);
          break;
        }
      }
    } 
    ev[i] = l * 2;
  }
  int now = 1;
  for (auto it : s) {
    for (auto j : el[it.second]) {
      od[j] = now;
      now += 2;
    }
  }
  answer();
  return 0;
}
