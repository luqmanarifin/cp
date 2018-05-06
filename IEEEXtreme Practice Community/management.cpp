
#include <bits/stdc++.h>

using namespace std;

const int N = 605;

int a[N];
int p, s, n;

int fifo() {
  set<int> st;
  queue<int> q;
  int ret = 0;
  for (int i = 0; i < n; i++) {
    if (st.count(a[i])) continue;
    if (q.size() == p) {
      ret++;
      st.erase(q.front());
      q.pop();
    }
    st.insert(a[i]);
    q.push(a[i]);
  }
  return ret;
}

int lru() {
  set<int> st;
  deque<int> v;
  int ret = 0;
  for (int i = 0; i < n; i++) {
    if (st.count(a[i])) {
      v.erase(remove(v.begin(), v.end(), a[i]), v.end());
      v.push_front(a[i]);
    } else {
      if (v.size() == p) {
        ret++;
        st.erase(v.back());
        v.pop_back();
      }
      st.insert(a[i]);
      v.push_front(a[i]);
    }
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &p, &s, &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      a[i] /= s;
    }
    int ret_fifo = fifo();
    int ret_lru = lru();
    printf("%s %d %d\n", ret_lru < ret_fifo? "yes" : "no", ret_fifo, ret_lru);
  }
  return 0;
}
