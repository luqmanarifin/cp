Program PersamaanKuadrat;

var
	a,b,c : integer;
	D : real;
	x1, x2 : real;
	
begin
	writeln('Masukkan a, b, c :');
	readln(a,b,c);
	D := b*b - 4*a*c;
	if (D > 0) then
	begin
		x1 := (-b + sqrt(D))/2*a;
		x2 := (-b - sqrt(D))/2*a;
		writeln('Akar pertama : ', x1:0:2);
		writeln('Akar kedua : ', x2:0:2);
	end else if (D = 0) then
	begin
		x1 := -b/2*a;
		writeln('Akar kembar adalah : ', x1:0:2);
	end else
		writeln('Akar imajiner');
end.