// Author: Luka Kalinovcic
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>

using namespace std;

#define MAXT 300000

struct Interval;
struct Edge {
  Interval* left = nullptr;
  Interval* right = nullptr;

  void Schedule();
  void WakeUp();
};

int T = 0;

enum { NONE = 0, A = 1, B = 2, BOTH = 3 };
int cnt[MAXT + 1][4];
vector<Edge*> wake_up[MAXT + 1][4];

struct Interval {
  int i, j;
  int h0, t0;
  int growing_mask;
  Edge* left = nullptr;
  Edge* right = nullptr;

  bool GrowingA() { return left && left->left->GetHeight() > GetHeight(); }
  bool GrowingB() { return right && right->right->GetHeight() > GetHeight(); }
  void ComputeGrowingMask() { growing_mask = GrowingA() | (GrowingB() << 1); }
  int GetHeight() { return h0 + cnt[T][growing_mask] - cnt[t0][growing_mask]; }
};

void Edge::Schedule() {
  int const delta = abs(left->GetHeight() - right->GetHeight());
  int const shrinking_mask = left->growing_mask ^ right->growing_mask;
  if (delta && shrinking_mask) {
    int const c = cnt[T][shrinking_mask] + delta;
    if (c <= MAXT) wake_up[c][shrinking_mask].push_back(this);
  }
}

void Edge::WakeUp() {
  if (left == nullptr || right == nullptr) return;
  int const h = left->GetHeight();
  if (right->GetHeight() != h) return;

  Interval* merged = left;
  merged->i = left->i;
  merged->j = right->j;
  merged->h0 = h;
  merged->t0 = T;
  merged->left = left->left;
  merged->right = right->right;
  if (merged->left) merged->left->right = merged;
  if (merged->right) merged->right->left = merged;
  merged->ComputeGrowingMask();
  if (merged->left) merged->left->Schedule();
  if (merged->right) merged->right->Schedule();
  left = nullptr;
  right = nullptr;
}

Interval* InitIntervals(int n) {
  Interval* first = nullptr;
  Interval* prev = nullptr;
  for (int i = 0; i < n; ++i) {
    int h;
    scanf("%d", &h);
    if (prev && h == prev->h0) {
      prev->j = i;
      continue;
    }
    Interval* curr = new Interval();
    curr->i = i;
    curr->j = i;
    curr->h0 = h;
    curr->t0 = 0;
    if (prev) {
      Edge* edge = new Edge();
      edge->left = prev;
      edge->right = curr;
      prev->right = edge;
      curr->left = edge;
      prev->ComputeGrowingMask();
    } else {
      first = curr;
    }
    prev = curr;
  }
  prev->ComputeGrowingMask();
  return first;
}

void Output(Interval* first) {
  for (Interval* interval = first; interval;
       interval = interval->right ? interval->right->right : nullptr) {
    for (int i = interval->i; i <= interval->j; ++i) {
      if (i > 0) printf(" ");
      printf("%d", interval->GetHeight());
    }
  }
  printf("\n");
}

int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  Interval* first = InitIntervals(N);
  for (Interval* interval = first; interval->right;
       interval = interval->right->right) {
    interval->right->Schedule();
  }
  for (T = 1; T <= M; ++T) {
    char c;
    scanf(" %c", &c);
    cnt[T][A] = cnt[T - 1][A] + (c == 'A');
    cnt[T][B] = cnt[T - 1][B] + (c == 'B');
    cnt[T][BOTH] = cnt[T - 1][BOTH] + 1;

    for (int mask : {A, B, BOTH}) {
      for (Edge* edge : wake_up[cnt[T][mask]][mask]) edge->WakeUp();
    }

    if (T == M) Output(first);
  }
  return 0;
}
