#include <bits/stdc++.h>

using namespace std;

struct Waktu {
  int hari, bulan, tahun;
};

struct Kontrak {
  Waktu masuk;
  Waktu keluar;
  int cuti;
};

Kontrak k;

int main() {
  puts("=====================================");
  puts("CV. Sukakarya");
  puts("Desa Sukamaju, Jawa Barat");
  puts("=====================================");
  puts("Program Penghitung Gaji Karyawan");
  puts("=====================================");
  puts("");
  puts("Input data karyawan :");
  puts("-------------------------------------");
  puts("Tanggal masuk :");
  cin >> k.masuk.hari >> k.masuk.bulan >> k.masuk.tahun;
  cin >> k.keluar.hari >> k.keluar.bulan >> k.keluar.tahun;
  cin >> k.cuti;
  int dayMasuk = k.masuk.hari + k.masuk.bulan * 30 + k.masuk.tahun * 30 * 12;
  int dayKeluar = k.keluar.hari + k.keluar.bulan * 30 + k.keluar.tahun * 30 * 12;
  int diff = dayKeluar - dayMasuk;
  int kerja = diff - 2 * (diff / 7);
  int pokok = kerja * 100000;
  double bonus = 0.0;
  if(kerja >= 20) bonus += (kerja / 20) * 0.02;
  if(kerja >= 5) bonus += (kerja / 5) * 0.01;
  printf("Pokok %d\n", pokok);
  printf("Bonus %d\n", (int) (bonus * pokok));
  printf("Potongan %d\n", (int) (0.008 * k.cuti * pokok));
  printf("Total %d\n", (int) (pokok + bonus * pokok - 0.008 * k.cuti * pokok));
  return 0;
}