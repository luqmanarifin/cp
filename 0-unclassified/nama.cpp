#include <bits/stdc++.h>

using namespace std;

string buffer;
string goldar[] = {"A", "B", "AB", "O"}; 
string agama[] = {"Islam", "Kristen", "Katolik", "Hindu", "Buddha", "Khonghucu"};
string job[] = {"mahasiswa", "profesor", "dokter", "dosen", "astronot", "polisi", "tentara"};
string pendidikan[] = {"SMA", "S1", "S2", "S3"};

int main() {
  int id = 3;
  while(getline(cin, buffer)) {
    int tgl = rand() % 28 + 1;
    int bln = rand() % 12 + 1;
    int th = rand() % 30 + 1970;
    int tempat_lahir = 0;
    int jenis_kelamin = rand() % 2;
    int a = rand() % 6;
    int gol = rand() % 4;
    int wni = rand() % 2;
    int j = rand() % 7;
    int p = rand() % 4;
    printf("INSERT INTO `penduduk`(`id`, `nama`, `tanggal_lahir`, `tempat_lahir`, `jenis_kelamin`, `hubungan_keluarga`, `golongan_darah`, `agama`, `wni`, `status_perkawinan`, `pekerjaan`, `pendidikan`, `id_izin_tetap`, `id_passport`, `created_at`, `status`) VALUES (\'%d\',\'%s\',\'%d-%d-%d\',\'0\',\'%s\',\'Anak\',\'%s\',\'%s\',\'%d\',\'Belum Kawin\',\'%s\',\'%s\',\'%d%d\',\'%d\',CURRENT_TIMESTAMP, 1);\n",
    id, buffer.c_str(), th, bln, tgl, (jenis_kelamin? "L" : "P"), goldar[gol].c_str(), agama[a].c_str(), wni, job[j].c_str(), pendidikan[p].c_str(), id, id, id
    );
    id++;
  }
  
  return 0;
}
