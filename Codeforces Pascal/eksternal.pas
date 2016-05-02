Program TulisNilai;
	{ Membaca masukan dari keyboard dan simpan ke file }
	{ KAMUS }
var
	fout : file of integer;
{ ALGORITMA }
begin
	assign(fout, 'dataku.dat');
	rewrite(fout);
	write(fout,1);
	write(fout,2);
	write(fout,3);
	write(fout,4);
	write(fout,5);
	write(fout,1);
	write(fout,2);
	write(fout,3);
	close(fout);
end.