#include <bits/stdc++.h>

using namespace std;

int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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

int get_day(long long year) {
  if (leap(year)) return 366;
  return 365;
}

int main() {
  for (int st = 0; st < 7; st++) {
    int now = st;
    int fridays = 0;
    for (int year = 2013; year < 2013 + 400; year++) {
      int days = get_day(year);
      int fri = (days - now - 1) / 7 + 1;
      fridays += fri;
      //printf("fri %d %d\n", fri, now);
      now = (now + fri * 7) % days;
    }
    printf("%d to %d: fridays %d\n", st, now, fridays);
  }

  return 0;
}
