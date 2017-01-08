#include <bits/stdc++.h>

using namespace std;

int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int FRIDAYS_PER_SLOT = 20871;

string str[] = {
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December"
};

bool leap(long long v) {
  if (v % 400 == 0) return 1;
  if (v % 100 == 0) return 0;
  if (v % 4 == 0) return 1;
  return 0;
}

void leaping(long long year) {
  if (leap(year)) day[1] = 29;
  else day[1] = 28;
}


int get_day(long long year) {
  if (leap(year)) return 366;
  return 365;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n;
    scanf("%lld", &n);
    if (n == 1) {
      puts("December 28, 2012");
      continue;
    }
    n -= 2;
    long long slots = n / FRIDAYS_PER_SLOT;
    n %= FRIDAYS_PER_SLOT;
    long long year = 2013 + slots * 400;
    int now = 3;
    while (1) {
      int days = get_day(year);
      int fri = (days - now - 1) / 7 + 1;
      if (n < fri) {
        leaping(year);
        now += n * 7;
        for (int i = 0; i < 12; i++) {
          if (now < day[i]) {
            printf("%s %d, %lld\n", str[i].c_str(), now + 1, year);
            break;
          }
          now -= day[i];
        }
        break;
      }
      n -= fri;
      now = (now + fri * 7) % days;
      year++;
    }

  }

  return 0;
}
