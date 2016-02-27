#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

#define PI acos(-1.0)

// berapa derajat setelah satu putaran full
double pre[N];
// jadi mod berapa setelah satu putaran full
int be[N];
// berapa putaran dibutuhin satu putaran full
int rot[N];

// putaran minimal untuk nyentuh
int l[N];
// putaran maksimal untuk nyentuh
int r[N];

bool done[N][N];

int main() {
  int n, a, p, m, b, q;
  scanf("%d %d %d %d %d %d", &n, &a, &p, &m, &b, &q);
  p--; q--;
  p = (n - p) % n;
  double roll = 360.0 / n;
  double full = 360.0 / n + 360.0 / m;
  double part = 360.0 / m;
  int tot = m * b;
  for(int i = 1; i <= a; i++) {
    int now = i;
    for(int j = 1; j <= m; j++) {
      if(q + 1 == j) {
        l[i] = rot[i];
      }
      
      int til = j * b;
      int num_roll = max(0, (til - 1 + a - now) / a);
      pre[i] += roll * num_roll;
      now += a * num_roll;
      rot[i] += num_roll;
      if(q + 1 == j) {
        r[i] = rot[i];
      }
      if(i == a) {
        //printf("lala %d %d\n", rot[i] - num_roll, rot[i]);
      }
      
      if(now == til) {
        pre[i] += full;
        rot[i]++;
        now += a;
      } else {
        pre[i] += part;
      }
    }
    be[i] = now % tot;
  }
  int side = 0;
  int now = a;
  double ans = 0;
  while(!done[now][side]) {
    done[now][side] = 1;
    //printf("%d %d\n", side, now);
    int lef = side + l[now];
    int rig = side + r[now];
    //printf("lef rig %d %d\n", l[now], r[now]);
    int cnt = rig - lef + 1;
    int golongan = now;
    if(cnt >= n) {
      CARI_JAWAB:;
      for(int j = 1; j <= m; j++) {
        if(q + 1 == j) {
          while(side != p) {
            //puts("taek");
            ans += roll;
            side = (side + 1) % n;
          }
          break;
        }
        int til = j * b;
        int num_roll = max(0, (til - 1 + a - now) / a);
        ans += roll * num_roll;
        now += a * num_roll;
        side = (side + num_roll) % n;
        
        if(now == til) {
          ans += full;
          side = (side + 1) % n;
          now += a;
        } else {
          ans += part;
        }
      }
      printf("%.15f\n", ans);
      return 0;
    } else {
      lef %= n;
      rig %= n;
      if(rig < lef) rig += n;
      if((lef <= p && p <= rig) || (lef <= p + n && p + n <= rig)) {
        goto CARI_JAWAB;
      }
    }
    ans += pre[golongan];
    side = (side + rot[golongan]) % n;
    now = be[golongan];
  }
  puts("-1");
  return 0;
}
