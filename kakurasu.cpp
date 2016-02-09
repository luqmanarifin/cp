/**
 *
 * @author Luqman A. Siswanto (13513024)
 */
#include <bits/stdc++.h>
 
using namespace std;

const int MAX = 15;

int col[MAX];
int row[MAX];

vector<vector<int>> cacah[MAX * MAX];
bool done[MAX];
bool ans[MAX][MAX];
int terisi;
int n;

void generate(int tobe, int now, int start) {
  if(tobe < now) return;
  if(tobe == now) {
    vector<int> temp;
    for(int i = 1; i <= n; i++) {
      if(done[i]) {
        temp.push_back(i);
      }
    }
    cacah[tobe].push_back(temp);
    return;
  }
  for(int i = start; i <= n; i++) {
    if(!done[i]) {
      done[i] = 1;
      generate(tobe, now + i, i + 1);
      done[i] = 0;
    }
  }
}

void read_input() {
  for(int i = 1; ; i++) {
    int a;
    scanf("%d", &a);
    if(a != i) {
      n = i - 1;
      break;
    }
  } 
  for(int i = 1; i <= n; i++) {
    int junk;
    if(i != 1) {
      scanf("%d", &junk);
      assert(junk == i);
    }
    for(int j = 1; j <= n; j++) {
      scanf("%d", &junk);
    }
    scanf("%d", row + i);
  }
  for(int i = 1; i <= n; i++) {
    scanf("%d", col + i);
  }
}

// menghasilkan semua kemungkinan pembuat angka 1 s.d. sum(1 .. n)
// misal 8 = 1 + 3 + 4, maka 1, 3, 4 adalah pembuat angka 8
void generate_number_maker() {
  int max_sum = 0, pos = 1;
  for(int i = 1; i <= n; i++) {
    max_sum += i;
    for(; pos <= max_sum; pos++) {
      generate(pos, 0, 1);
    }
  }
}

void brute_force_answer() {
  int cur[MAX];
  int sum[MAX];
  memset(cur, -1, sizeof(cur));
  memset(sum, 0, sizeof(sum));
  int ptr = 1, bef = 0;
  while(ptr <= n) {
    int start = cur[ptr] + 1;
    if(bef < ptr) {
      start = 0;
    }
    bool valid = 0;
    for(int i = start; i < cacah[row[ptr]].size(); i++) {
      for(auto j : cacah[row[ptr]][i]) {
        sum[j] += ptr;
      }
      bool ok = 1;
      for(int j = 1; j <= n; j++) {
        if(ptr == n) {
          if(col[j] != sum[j]) {
            ok = 0;
            break;
          }
        } else {
          if(col[j] < sum[j]) {
            ok = 0;
            break;
          }
        }
      }
      if(ok) {
        cur[ptr] = i;
        valid = 1;
        break;
      }
      for(auto j : cacah[row[ptr]][i]) {
        sum[j] -= ptr;
      }
    }
    bef = ptr;
    if(valid) ptr++;
    else {
      if(ptr == 1) {
        cerr << "Kakurasu tidak memiliki solusi." << endl;
        cerr << "Cek kembali input Anda." << endl;
        exit(0);
      }
      ptr--;
      for(auto j : cacah[row[ptr]][cur[ptr]]) {
        sum[j] -= ptr;
      }
    }
  }
  
  for(int i = 1; i <= n; i++) {
    for(auto num : cacah[row[i]][cur[i]]) {
      ans[i][num] = 1;
      terisi++;
    }
  }
}

void output() {
  printf("   ");
  for(int i = 1; i <= n; i++) {
    printf("%2d ", i);
  }
  printf("\n");
  
  for(int i = 1; i <= n; i++) {
    printf("%2d ", i);
    for(int j = 1; j <= n; j++) {
      printf("%2d ", ans[i][j]);
    }
    printf("%2d\n", row[i]);
  }
  printf("   ");
  for(int i = 1; i <= n; i++) {
    printf("%2d ", col[i]);
  }
}

int main() {
  freopen("kakurasu.txt","r", stdin);
  freopen("kakurasu_solution.txt", "w", stdout);
  clock_t t = clock();
  cerr << setprecision(3);
  read_input();
  generate_number_maker();
  brute_force_answer();
  output();
  cerr << "Kakurasu has been solved!" << endl;
  cerr << "Ada " << terisi << " kotak yang terisi" << endl; 
  cerr << "Program berhasil mencari solusi dalam " << (float) (clock() - t)*1000.0/CLOCKS_PER_SEC << " milidetik."<< endl;
  return 0;
}