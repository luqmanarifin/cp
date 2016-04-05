#include <bits/stdc++.h>

using namespace std;

string buffer;

int main() {
  int id = 0;
  while(getline(cin, buffer)) {
    id++;
    int satu = rand() % 43 + 1;
    int dua = rand() % 43 + 1;
    int tiga = rand() % 43 + 1;
    int nilai = rand() % 21 + 70;
    printf("INSERT INTO `calonpegawai`(`id_calon_pegawai`, `nama`, `id_penduduk`, `created_at`, `pilihan_1`, `pilihan_2`, `pilihan_3`, `nilai_tes_bkn`, `id_kebutuhan_pegawai`) VALUES (%d,\'%s\',%d,CURRENT_TIMESTAMP,%d,%d,%d,%d,NULL);\n",
    id, buffer.c_str(), id, satu, dua, tiga, nilai);
  }
  
  return 0;
}
