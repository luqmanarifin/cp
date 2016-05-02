Program HelpfulMath;

var
	a : string;
	panjang,i, satu, dua, tiga : integer;
	j,k,l : integer;
	
begin
	readln(a);
	panjang := length(a); satu := 0; dua := 0; tiga := 0; i:= panjang-1;
	while(i >=2) do
	begin
		delete(a,i,1); i := i - 2;
	end;
	for i:=1 to ((panjang+1) div 2) do
	begin
		j := pos('1',a); if (j <> 0) then satu := satu + 1; delete(a,j,1);
		k := pos('2',a); if (k <> 0) then dua := dua + 1; delete(a,k,1);
		l := pos ('3',a); if (l <> 0) then tiga := tiga + 1; delete(a,l,1);
	end;
	for i:=1 to satu do
	begin
		if ((i = satu) and (dua = 0) and (tiga = 0)) then writeln('1')
		else write('1+');
	end;
	for i:=1 to dua do
	begin
		if ((i = dua) and (tiga = 0)) then writeln('2')
		else write('2+');
	end;
	for i:=1 to tiga do
	begin
		if (i = tiga) then writeln('3')
		else write('3+')
	end;
end.