#include <bits/stdc++.h>

using namespace std;

int px, py, qx, qy;
int found;

int ask(int x1, int y1, int x2, int y2) {
  printf("? %d %d %d %d\n", x1 + 1, y1 + 1, x2 + 1, y2 + 1);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans;
}

bool inside(int x1, int y1, int x2, int y2, int ret) {
  if (found == 0) {
    return ret % 2;
  }
  int dalam = (x1 <= px && px <= x2 && y1 <= py && py <= y2);
  return (ret + dalam) % 2; 
}

bool inside(int x1, int y1, int x2, int y2) {
  int ret = ask(x1, y1, x2, y2);
  return inside(x1, y1, x2, y2, ret);
}

void solve(int x1, int y1, int x2, int y2) {
  while (x1 < x2) {
    int mid = (x1 + x2) >> 1;
    if (inside(x1, y1, mid, y2)) {
      x2 = mid;
    } else {
      x1 = mid + 1;
    }
  }
  while (y1 < y2) {
    int mid = (y1 + y2) >> 1;
    if (inside(x1, y1, x2, mid)) {
      y2 = mid;
    } else {
      y1 = mid + 1;
    }
  }
  if (!inside(x1, y1, x2, y2)) return;
  if (found == 0) {
    px = x1;
    py = y1;
  } else {
    qx = x1;
    qy = y2;
  }
  found++;
}

int main() {
  int n;
  scanf("%d", &n);
  srand(time(0));
  int found = 0;
  vector<int> num;
  for (int i = 0; i < n; i++) num.push_back(i);
  random_shuffle(num.begin(), num.end());
  for (auto i : num) {
    if (inside(i, 0, i, n - 1)) {
      solve(i, 0, i, n - 1);
      if (found == 2) break;
    }
    if (inside(0, i, n - 1, i)) {
      solve(0, i, n - 1, i);
      if (found == 2) break;
    }
  }
  printf("! %d %d %d %d\n", px + 1, py + 1, qx + 1, qy + 1);
  fflush(stdout);
  return 0;
}
