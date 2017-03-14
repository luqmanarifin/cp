#include <bits/stdc++.h>

using namespace std;

const int N = 105;

struct person {
  person() {}
  person(int type, int t, int f, int id) : type(type), t(t), f(f), id(id) {}
  bool operator<(person other) const {
    if (type != other.type) return type < other.type;
    if (t != other.t) return t > other.t;
    return id < other.id;
  }
  int type, t, f, id;
};

priority_queue<person> q;
person a[N];

int trip[N];

int main() {
  int n, w, c, m;
  scanf("%d %d %d %d", &n, &w, &c, &m);
  --m;
  for (int i = 0; i < n; i++) {
    int type, time, f;
    scanf("%d %d %d", &type, &time, &f);
    a[i] = person(type, time, f, i);
  }
  int p = 0;
  int now = 0;
  int num = 0;
  int last = 0;
  while (p < n || !q.empty()) {
    ++num;
    if (q.empty()) {
      now = max(now, a[p].t);
      q.push(a[p]);
      p++;
    }
    //printf("trip %d waktu %d\n", num, now);
    for (; p < n && a[p].t <= now + w; p++) q.push(a[p]);
    now += w;
    int kali = c;
    int longest = 0;
    while (kali-- && !q.empty()) {
      trip[q.top().id] = num;
      //printf("%d\n", q.top().id+1);
      longest = max(longest, q.top().f);
      last = now + q.top().f;
      q.pop();
    }
    now += 2 * longest;
    for (; p < n && a[p].t <= now; p++) q.push(a[p]);
  }
  printf("%d %d\n", trip[m], last);
  return 0;
}
