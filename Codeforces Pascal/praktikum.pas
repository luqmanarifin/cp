// Nama / NIM	: Luqman A. Siswanto / 16513376
// Tanggal		: 2 April 2014
// Tema			: Rekursif, Loop, dan Pengulangan REVIEW
// Deskripsi	: Membuat program seperti yang diminta soal

function gcd(m, n : integer): integer;
begin
	if(b = 0) gcd := a
	else gcd := gcd(b, a mod b);
end;

var
	a, b, c : integer;
begin
	readln(a,b,c);
	if(0 <= a)and(a <= 23)and(0 <= b)and(b <= 59)and(0 <= c)and(c <= 59) then begin
		writeln('Jam : ',a);
		writeln('Menit : ',b);
		writeln('Detik : ',c);
	end else
		writeln('Masukan Tidak Valid');
end.