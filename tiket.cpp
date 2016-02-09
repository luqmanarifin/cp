#include <bits/stdc++.h>

using namespace std;

vector<string> code;
vector<long long> noid;

long long get(long long l, long long r) {
  long long num = ((1LL * rand()) << 30) + ((1LL * rand()) << 15) + ((1LL * rand()));
  return num % (r - l + 1) + l;
}

int main() {
  srand(time(NULL));
  string buffer;
  
  for(int i = 0; i < 2000; i++) {
    getline(cin, buffer);
    long long a = atoll(buffer.c_str());
    noid.push_back(a);
  }
  
  while(getline(cin, buffer)) {
    code.push_back(buffer);
  }
  
  int size = 100000;
  for(int i = 0; i < size; i++) {
    int id = get(0, noid.size() - 1);
    int asal = get(0, code.size() - 1);
    int akhir = get(0, code.size() - 1);
    while(asal == akhir) {
      akhir = get(0, code.size() - 1);
    }
    int nokereta = get(114, 225);
    int harga = get(12, 545);
    int tahun = 2015;
    int bulan = get(4, 12);
    int hari = get(1, 28);
    int berangkat = get(0, 3600 * 24 - 1);
    int tiba = get(0, 3600 * 24 - 1);
    while(berangkat == tiba) {
      tiba = get(0, 3600 * 24 - 1);
    }
    if(berangkat > tiba) swap(berangkat, tiba);
    
    puts("INSERT INTO `tiket`");
    puts("(`No_ID`, `Stasiun_Asal`, `Stasiun_Tujuan`, `No_Kereta`, `Harga`, `Waktu_Berangkat`, `Waktu_Tiba`)");
    puts("VALUES");
    
    printf("(%I64d, '%s', '%s', %d, %d, ", noid[id], code[asal].c_str(), code[akhir].c_str(), nokereta, harga * 1000);
    int hh, mm, dd;
    hh = berangkat / 3600;
    mm = (berangkat % 3600) / 60;
    dd = berangkat % 60;
    printf("'%d-%d%d-%d%d %d%d:%d%d:%d%d', ", tahun, bulan/10, bulan%10, hari/10, hari%10, hh/10, hh%10, mm/10, mm%10, dd/10, dd%10);
    hh = tiba / 3600;
    mm = (tiba % 3600) / 60;
    dd = tiba % 60;
    printf("'%d-%d%d-%d%d %d%d:%d%d:%d%d')", tahun, bulan/10, bulan%10, hari/10, hari%10, hh/10, hh%10, mm/10, mm%10, dd/10, dd%10);
    cout << ";" << endl << endl;
  }
  
  return 0;
}
