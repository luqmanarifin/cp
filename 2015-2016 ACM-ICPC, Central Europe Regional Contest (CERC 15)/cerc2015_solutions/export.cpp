// Author: Goran Zuzic
#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

enum { I, Q };

struct Event {
  int type;
  int x;
  int a, b;
  int qidx;
};

const int MAXN = 1e6 + 123;
const int MAXQ = 1e6 + 123;

vector<int> ans[MAXQ];
int deg[MAXN];

int cd0 = 0;  // count deg 0
int cd2 = 0;  // count deg 2
int ccyc = 0; // count cycles
int sdeg = 0; // sum of degs

int uf_cv[MAXN]; // (union find) parent count vertices
int uf_cd2[MAXN];  // (union find) parent count deg 2

int dad[MAXN];
int find_dad(int x) {
  if (dad[x] == -1) return x;
  return dad[x] = find_dad(dad[x]);
}

void merge(int a, int b) {
  ccyc -= (uf_cv[a] == uf_cd2[a]);
  ccyc -= (uf_cv[b] == uf_cd2[b]);

  dad[a] = b;
  uf_cv[b] += uf_cv[a];
  uf_cd2[b] += uf_cd2[a];

  ccyc += (uf_cv[b] == uf_cd2[b]);
}

void ins(int v, int cnt) {
  cd0 += cnt*(deg[v] == 0);
  cd2 += cnt*(deg[v] == 2);
  sdeg += cnt*deg[v];

  int d = find_dad(v);
  ccyc -= (uf_cv[d] == uf_cd2[d]);

  uf_cv[d] += cnt;
  uf_cd2[d] += cnt*(deg[v] == 2);

  ccyc += (uf_cv[d] == uf_cd2[d]);
}

int main(void) {
  int n, e; scanf("%d %d", &n, &e);
  vector<Event> es;
  REP(i, e) {
    int a, b, w; scanf("%d %d %d", &a, &b, &w); --a, --b;
    es.push_back({I, w, a, b, -1});
  }
  int cq; scanf("%d", &cq);
  REP(iq, cq) {
    int w; scanf("%d", &w);
    es.push_back({Q, w, -1, -1, iq});
  }

  sort(es.begin(), es.end(), [](Event a, Event b) {
      if (a.x != b.x) return a.x > b.x;
      return a.type < b.type;
    });

  memset(deg, 0, sizeof deg);
  memset(dad, -1, sizeof dad);

  ccyc = n; // trivially, all comps have all deg2
  REP(i, n) ins(i, +1);

  for (auto e : es) {
    if (e.type == I) {
      ins(e.a, -1);
      if (e.b != e.a) ins(e.b, -1);

      ++deg[e.a]; ++deg[e.b];
      int A = find_dad(e.a);
      int B = find_dad(e.b);
      if (A != B) merge(A, B);

      ins(e.a, +1);
      if (e.b != e.a) ins(e.b, +1);
    } else if (e.type == Q) {
      int av = n - cd0 - cd2 + ccyc;      
      int ae = (sdeg - 2*cd2) / 2 + ccyc;
      ans[e.qidx] = {av, ae};
    } else assert(false);
  }

  REP(i, cq) printf("%d %d\n", ans[i][0], ans[i][1]);
  return 0;
}   
