#include <bits/stdc++.h>

using namespace std;

struct Op {
  char op;  // F, L, C
  long long x;
};

struct State {
  State(int _len = 0, long long _a = 0) {
    len = _len;
    on = _len;
    sum = _len * _a;
    sum_unlock = sum;
  }
  void apply() {
    for (auto it : push) {
      if (it.op == 'F') {
        sum += it.x * on - sum_unlock;
        sum_unlock = it.x * on;
      } else if (it.op == 'L') {
        on = 0;
        sum_unlock = 0;
      } else {
        on = len;
        sum_unlock = sum;
      }
    } 
    push.clear();
  }
  void add_op(const Op& op) {
    if (push.size() == 3) {
      if (op.op == 'F') {
        if (push.back().op != 'L') {
          Op last = push.back();
          push = {last, op};
        }
      } else {
        push.back() = op;
      }
    } else if (push.size() == 2) {
      if (push.back().op == 'F') {
        if (op.op == 'F') {
          push.back() = op;
        } else {
          push.push_back(op);
        }
      } else {
        if (op.op != 'F') {
          push.back() = op;
        } else if (push.back().op == 'C') {
          Op last = push.back();
          push = {last, op};
        }
      }
    } else if (push.size() == 1) {
      if (push.back().op == 'F') {
        if (op.op == 'F') {
          push.back() = op;
        } else {
          push.push_back(op);
        }
      } else if (push.back().op == 'L') {
        if (op.op == 'C') {
          push.back() = op;
        }
      } else {  // 'C'
        if (op.op == 'F') {
          push.push_back(op);
        } else if (op.op == 'L') {
          push.back() = op;
        }
      }
    } else {
      assert(push.empty());
      push.push_back(op);
    }
  }
  void add_state(const State& s) {
    for (int i = 0; i < s.push.size(); i++) {
      add_op(s.push[i]);
    }
  }
  int len, on;
  long long sum, sum_unlock;
  vector<Op> push;
};

State combine(State a, State b) {
  State res(a.len + b.len, 0);
  res.on = a.on + b.on;
  res.sum = a.sum + b.sum;
  res.sum_unlock = a.sum_unlock + b.sum_unlock;
  return res;
}

struct segtree {
  segtree(vector<long long> _a, int _n) : a(_a), n(_n) {
    num.resize((n + 1) << 2);
    build(1, 1, n);
  }
  void build(int p, int l, int r) {
    // printf("build %d %d %d\n", p, l, r);
    if (l == r) {
      num[p] = State(1, l < a.size()? a[l] : 0);
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    num[p] = combine(num[p + p], num[p + p + 1]);
  }
  void lazy(int p, int l, int r) {
    if (num[p].push.size()) {
      if (l < r) {
        num[p + p].add_state(num[p]);
        num[p + p + 1].add_state(num[p]);
      }
      num[p].apply();
    }
  }
  void update(int l, int r, Op op) {
    update(1, 1, n, l, r, op);
  }
  void update(int p, int l, int r, int ll, int rr, Op op) {
    lazy(p, l, r);
    if (ll <= l && r <= rr) {
      num[p].add_op(op);
      lazy(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    update(p + p, l, mid, ll, rr, op);
    update(p + p + 1, mid + 1, r, ll, rr, op);
    num[p] = combine(num[p + p], num[p + p + 1]);
  }
  long long find(int l, int r) {
    return find(1, 1, n, l, r);
  }
  long long find(int p, int l, int r, int ll, int rr) {
    lazy(p, l, r);
    if (ll <= l && r <= rr) {
      return num[p].sum;
    }
    if (r < ll || rr < l) return 0;
    int mid = (l + r) >> 1; long long ret = 0;
    ret += find(p + p, l, mid, ll, rr);
    ret += find(p + p + 1, mid + 1, r, ll, rr);
    num[p] = combine(num[p + p], num[p + p + 1]);
    return ret;
  }
  vector<State> num;
  vector<long long> a;
  int n;
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<long long> a(1, 0);
  for (int i = 1; i <= n; i++) {
    int v;
    scanf("%d", &v);
    a.push_back(v);
  }
  segtree seg(a, n + q);
  // puts("build done");
  int len = n;
  while (q--) {
    char c; int l, r, v;
    scanf(" %c", &c);
    if (c == 'F') {
      scanf("%d %d %d", &l, &r, &v);
      seg.update(l, r, Op{'F', v});
    } else if (c == 'I') {
      scanf("%d", &v);
      ++len;
      seg.update(len, len, Op{'F', v});
    } else if (c == 'L') {
      scanf("%d %d", &l, &r);
      seg.update(l, r, Op{'L', 0});
    } else if (c == 'C') {
      scanf("%d %d", &l, &r);
      seg.update(l, r, Op{'C', 0});
    } else if (c == 'O') {
      scanf("%d %d", &l, &r);
      printf("%lld\n", seg.find(l, r));
    } else {
      assert(0);
    }
  }

  return 0;
}
