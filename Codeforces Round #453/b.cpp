
#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;

int n;

bool bad;

vector<double> mod(vector<double> a, vector<double> b) {
  /*
  puts("A");
  for (auto it : a) printf("%.2f ", it); printf("\n");
  for (auto it : b) printf("%.2f ", it); printf("\n\n");
  */
  double tb = a.back() / b.back();
  for (int i = 0; i < b.size(); i++) a[i+1] -= tb * b[i];
  /*
  puts("B");
  for (auto it : a) printf("%.2f ", it); printf("\n");
  for (auto it : b) printf("%.2f ", it); printf("\n\n");
  */
  tb = a[a.size() - 2] / b.back();
  for (int i = 0; i < b.size(); i++) a[i] -= tb * b[i];
  assert(fabs(a.back()) < eps && fabs(a[a.size() - 2]) < eps);
  vector<double> ret;
  for (int i = 0; i < (int) a.size() - 2; i++) ret.push_back(a[i]);
  if (ret.size() && fabs(ret.back()) < eps) bad = 1;
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  srand(time(0));
  while (1) {
    vector<int> oa, ob;
    for (int i = 0; i < n; i++) oa.push_back(rand() % 3 - 1);
    for (int i = 0; i < n - 1; i++) ob.push_back(rand() % 3 - 1);
    oa.push_back(1);
    ob.push_back(1);
    vector<double> a, b;
    for (auto it : oa) a.push_back(it);
    for (auto it : ob) b.push_back(it);
    for (int i = 0; i < n; i++) {
      bad = 0;
      vector<double> be = mod(a, b);
      a = b;
      b = be;
      if (bad) {
        goto NEXT;
      }
    }
    printf("%d\n", n);
    for (auto it : oa) printf("%d ", it); printf("\n");
    printf("%d\n", n - 1);
    for (auto it : ob) printf("%d ", it); printf("\n");
    return 0;
    NEXT:;
  }

  return 0;
}
