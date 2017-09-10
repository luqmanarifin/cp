// Author: Luka Kalinovcic
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 20

typedef long long int64;

char in[7][MAX*6];
char out[7][MAX*6];

// .000.
// 1...2
// 1...2
// .333.
// 4...5
// 5...5
// .666.

int codes[10] = {
//  6543210
  0b1110111, // 0
  0b0100100, // 1
  0b1011101, // 2
  0b1101101, // 3
  0b0101110, // 4
  0b1101011, // 5
  0b1111011, // 6
  0b0100101, // 7
  0b1111111, // 8
  0b1101111, // 9
};

int GetCode(int c0) {
  int code = 0;
  if (in[0][c0 + 2] == 'x') code |= 0b0000001;
  if (in[1][c0 + 0] == 'x') code |= 0b0000010;
  if (in[2][c0 + 4] == 'x') code |= 0b0000100;
  if (in[3][c0 + 2] == 'x') code |= 0b0001000;
  if (in[4][c0 + 0] == 'x') code |= 0b0010000;
  if (in[5][c0 + 4] == 'x') code |= 0b0100000;
  if (in[6][c0 + 2] == 'x') code |= 0b1000000;
  return code;
}

int64 Input() {
  static int pos = 0;
  int64 result = 0;
  for (;;) {
    int code = GetCode(pos++ * 6);
    bool is_digit = false;
    for (int digit = 0; digit < 10; ++digit) {
      if (codes[digit] == code) {
        result = result * 10 + digit;
        is_digit = true;
      }
    }
    if (!is_digit) break;
  }
  return result;
}

void Draw(int code, int c0) {
  for (int r = 0; r < 7; ++r) {
    for (int c = 0; c < 5; ++c) {
      out[r][c0 + c] = '.';
    }
  }
  if (code & 0b0000001) for (int c = 0; c < 5; ++c) out[0][c0 + c] = 'x';
  if (code & 0b0000010) for (int r = 0; r < 4; ++r) out[r][c0 + 0] = 'x';
  if (code & 0b0000100) for (int r = 0; r < 4; ++r) out[r][c0 + 4] = 'x';
  if (code & 0b0001000) for (int c = 0; c < 5; ++c) out[3][c0 + c] = 'x';
  if (code & 0b0010000) for (int r = 3; r < 7; ++r) out[r][c0 + 0] = 'x';
  if (code & 0b0100000) for (int r = 3; r < 7; ++r) out[r][c0 + 4] = 'x';
  if (code & 0b1000000) for (int c = 0; c < 5; ++c) out[6][c0 + c] = 'x';
}

void Output(int64 number) {
  vector<int> digits;
  while (number) {
    digits.push_back(number % 10);
    number /= 10;
  }
  reverse(digits.begin(), digits.end());
  for (int i = 0; i < digits.size(); ++i) {
    if (i) {
      for (int r = 0; r < 7; ++r) out[r][i * 6 - 1] = '.';
    }
    Draw(codes[digits[i]], i * 6);
  }
  for (int r = 0; r < 7; ++r) printf("%s\n", out[r]);
}

int main() {
  for (int r = 0; r < 7; ++r) scanf("%s", in[r]);
  int64 a = Input();
  int64 b = Input();
  Output(a + b);
  return 0;
}
