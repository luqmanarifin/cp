// ngitung IP

var
	sum : real;
	
procedure hitung(a: string; var sum : real);
var
	index : string;
	n : real;
begin
	write('Masukkan indeks ');
	case a of 
		'mat' : write('Kalkulus : ');
		'fis' : write('Fisika Dasar : ');
		'kim' : write('Kimia Dasar : ');
		'prd' : write('Pengantar Rekayasa dan Desain : ');
		'pti' : write('Pengantar Teknologi Informasi : ');
		'olah' : write('Olahraga : ');
		'eng' : write('Bahasa Inggris : ');
	end;
	readln(index);
	case index of
		'A' : n := 4;
		'AB' : n := 3.5;
		'B' : n := 3;
		'BC' : n := 2.5;
		'C' : n := 2;
		'D' : n := 1;
		else n := 0;
	end;
	if (a = 'mat') or (a = 'fis') then sum := sum + n * 4
	else sum := sum + n * 2;
end;
begin
	writeln('**** PENGHITUNG IP STEI 2013/2014 *****'); writeln;
	hitung('mat',sum);
	hitung('fis',sum);
	hitung('kim',sum);
	hitung('prd',sum);
	hitung('pti',sum);
	hitung('olah',sum);
	hitung('eng',sum); writeln;
	writeln('IP anda semester ini adalah :  ',sum/18 :0:2);
end.
	