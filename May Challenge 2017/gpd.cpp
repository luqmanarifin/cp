#include <bits/stdc++.h>

using namespace std;

int n, q, r, key;
map<int, int> par;
map<int, int> val;

int main() {
  scanf("%d %d %d %d", &n, &q, &r, &key);

  val[r] = key;
  for (int i = 0; i < n - 1; i++) {
    int u, v, k;
    scanf("%d %d %d", &u, &v, &k);
    val[u] = k;
    par[u] = v;
  }

  int last_answer = 0;

  for (int i = 0; i < q; i++) {
    //printf("query %d\n", i + 1);
    int t, u, v, k;
    scanf("%d", &t);
    // find real value of t
    t ^= last_answer;

    if (t == 0) {
      scanf("%d %d %d", &v, &u, &k);
      // find real values for u, v, and k
      u ^= last_answer;
      v ^= last_answer;
      k ^= last_answer;
      
      val[u] = k;
      par[u] = v;
      
    } else {
      scanf("%d %d", &v, &k);

      // find real values for v, and k
      v ^= last_answer;  
      k ^= last_answer;

      // compute the requested values
      int c = val[v];
      int min_answer = c ^ k;
      int max_answer = c ^ k;
      while (v != r) {
        v = par[v];
        int c = val[v];
        min_answer = min(min_answer, c ^ k);
        max_answer = max(max_answer, c ^ k);
      }
      
      printf("%d %d\n", min_answer, max_answer);

      // update last_answer
      last_answer = min_answer ^ max_answer;  
    }
  }
}