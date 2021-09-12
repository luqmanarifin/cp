#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 8e5 + 5;

char s[N];

struct state {
  long long all, sum, residue, head, airhead, tail, element, last_o, last_x;
  char char_now, char_head;
  bool has_tail;
};

state get_empty() {
  return state{
    all: 0,
    sum: 0,
    residue: 0,
    head: 0,
    airhead: 0,
    tail: 0,
    element: 0,
    last_o: 0,
    last_x: 0,
    char_now: 'F',
    char_head: 'F',
    has_tail: false,
  };
}

state copy(state now) {
  return state{
    all: now.all,
    sum: now.sum,
    residue: now.residue,
    head: now.head,
    airhead: now.airhead,
    tail: now.tail,
    element: now.element,
    last_o: now.last_o,
    last_x: now.last_x,
    char_now: now.char_now,
    char_head: now.char_head,
    has_tail: now.has_tail,
  };
}

state duplicate_no_tail(state now) {
  state fut = copy(now);
  fut.all = (now.all * 2) % mod;
  if (now.element) {
    fut.head = (now.head + now.all) % mod;
    fut.airhead = now.airhead;
  } else {
    fut.head = 0;
    fut.airhead = (now.airhead * 2) % mod;
  }
  if (now.char_now == 'O') {
    fut.last_o = (now.last_o + now.all) % mod;
  }
  if (now.char_now == 'X') {
    fut.last_x = (now.last_x + now.all) % mod;
  }
  return fut;
}

state duplicate_same(state now) {
  state fut = copy(now);
  fut.all = (now.all * 2) % mod;
  fut.sum = (now.sum * 2 % mod + (now.element - 1 + mod) % mod * now.all % mod) % mod;
  long long new_residue = (now.all * now.sum % mod + now.all * now.tail % mod + now.residue) % mod;
  fut.residue = (now.residue + new_residue) % mod;
  long long tail_length = (now.all - now.head - now.airhead + 2 * mod) % mod;
  fut.tail = (now.tail + (now.element - 1 + mod) % mod * (now.head + now.airhead) % mod + now.tail + (now.element - 1 + mod) % mod * tail_length % mod) % mod;
  fut.element = (now.element * 2 - 1 + mod) % mod;
  fut.last_o = (now.last_o + now.all) % mod;
  fut.last_x = (now.last_x + now.all) % mod;
  return fut;
}

long long last(state now) {
  return (now.char_now == 'X'? now.last_x : now.last_o);
}

state duplicate_diff(state now) {
  state fut = copy(now);
  fut.all = (now.all * 2) % mod;
  fut.sum = (now.sum * 2 % mod + (now.element - 1 + mod) % mod * now.all % mod + last(now)) % mod;
  long long new_residue = (now.all * now.sum % mod + (now.all - now.airhead + mod) % mod * last(now) % mod + now.all * now.tail % mod + now.residue) % mod;
  fut.residue = (now.residue + new_residue) % mod;
  long long tail_length = (now.all - now.head - now.airhead + 2 * mod) % mod;
  fut.tail = (now.tail + (now.element - 1 + mod) % mod * now.airhead % mod + now.head * now.element % mod + now.tail + tail_length * now.element % mod) % mod;
  fut.element = now.element * 2 % mod;
  fut.last_o = (now.last_o + now.all) % mod;
  fut.last_x = (now.last_x + now.all) % mod;
  return fut;
}

state duplicate(state now) {
  // no tail merge
  if (!now.has_tail) {
    return duplicate_no_tail(now);
  }
  // same state merge
  if (now.char_now == now.char_head) {
    return duplicate_same(now);
  }
  // different state merge
  if (now.char_now != now.char_head) {
    return duplicate_diff(now);
  }
  assert(0);
}

state add_f(state now) {
  state fut = copy(now);
  fut.all = (now.all + 1) % mod;
  fut.sum = now.sum;
  fut.residue = (now.residue + now.sum) % mod;
  if (now.has_tail) {
    fut.head = now.head;
    fut.airhead = now.airhead;
  } else {
    if (now.element == 0) {
      fut.head = now.head;
      fut.airhead = (now.airhead + 1) % mod;
    } else {
      fut.head = (now.head + 1) % mod;
      fut.airhead = now.airhead;
    }
  }
  if (now.has_tail) {
    fut.tail = (now.tail + now.element - 1 + mod) % mod;
  }
  fut.element = now.element;
  fut.last_o = now.last_o;
  fut.last_x = now.last_x;
  fut.char_now = now.char_now;
  fut.char_head = now.char_head;
  fut.has_tail = now.has_tail;
  return fut;
}

state add_o(state now) {
  state fut = copy(now);
  fut.all = (now.all + 1) % mod;
  if (now.char_now == 'X') {
    fut.sum = (now.sum + now.last_x) % mod;
    fut.has_tail = true;
  } else {
    fut.sum = now.sum;
  }
  fut.residue = (now.residue + fut.sum) % mod;
  if (!fut.has_tail) {
    fut.head = (now.head + 1) % mod;
  }
  if (now.char_now != 'O') {
    fut.element = (now.element + 1) % mod;
  }
  if (fut.has_tail) {
    fut.tail = (now.tail + fut.element - 1 + mod) % mod;
  }
  fut.last_o = fut.all;
  fut.last_x = now.last_x;
  fut.char_now = 'O';
  fut.char_head = (fut.has_tail? now.char_head : 'O');
  return fut;
}

state add_x(state now) {
  state fut = copy(now);
  fut.all = (now.all + 1) % mod;
  if (now.char_now == 'O') {
    fut.sum = (now.sum + now.last_o) % mod;
    fut.has_tail = true;
  } else {
    fut.sum = now.sum;
  }
  fut.residue = (now.residue + fut.sum) % mod;
  if (!fut.has_tail) {
    fut.head = (now.head + 1) % mod;
  }
  if (now.char_now != 'X') {
    fut.element = (now.element + 1) % mod;
  }
  if (fut.has_tail) {
    fut.tail = (now.tail + fut.element - 1 + mod) % mod;
  }
  fut.last_o = now.last_o;
  fut.last_x = fut.all;
  fut.char_now = 'X';
  fut.char_head = (fut.has_tail? now.char_head : 'X');
  return fut;
}

void debug(int i, state now) {
  printf("i=%d,all=%lld,sum=%lld,residue=%lld,head=%lld,airhead=%lld,tail=%lld,element=%lld,last_o=%lld,last_x=%lld,char_now=%c,char_head=%c,has_tail=%d\n",
    i, now.all, now.sum, now.residue, now.head, now.airhead, now.tail, now.element, now.last_o, now.last_x, now.char_now, now.char_head, now.has_tail
  );
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d %s", &n, s + 1);
    state now = get_empty();
    for (int i = 1; i <= n; i++) {
      if (s[i] == '.') {
        now = duplicate(now);
      } else if (s[i] == 'F') {
        now = add_f(now);
      } else if (s[i] == 'O') {
        now = add_o(now);
      } else if (s[i] == 'X') {
        now = add_x(now);
      } else { 
        assert(0);
      }
      // debug(i, now);
    }
    printf("Case #%d: %lld\n", tt, now.residue);
  }

  return 0;
}
