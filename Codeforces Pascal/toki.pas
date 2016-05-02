Program mainan;

var
	i,j,kolom,baris : integer;
	apakah : boolean;
	x : array[1..10] of array[1..10] of integer;
	
begin
	apakah := true;
	readln(baris,kolom);
	for i:=1 to baris do
	begin
		for j:=1 to kolom do
		begin
			write('indeks ke [',i,'][',j,'] : '); readln(x[i][j]);
			if ((i = j) and (x[i][j] <> 1)) then apakah := false
			else if ((i <> j) and (x[i][j] <> 0)) then apakah := false;
		end;
	end;
	if(apakah) then writeln('MAtriks identitas')
	else writeln('Matriks bukan identitas');
end.
				
		