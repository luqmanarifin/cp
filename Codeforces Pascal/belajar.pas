Program Latihan7;

var
	T1 : array[1..100] of integer;
	T2 : array[1..100] of integer;
	i, j, neff1, neff2 : integer;

begin
	i := 1;
	while not eof do
	begin
		readln(T1[i]);
		i := i + 1;
	end;
	neff1 := i - 1;
	
	j := 1;
	for i:=1 to neff1 do
	begin
		if(T1[i] > 0) then
		begin
			T2[j] := T1[i];
			j := j + 1;
		end;
	end;
	neff2 := j - 1;
	
	if(neff2 = 0) then writeln('T2 kosong')
	else
		for i:=1 to neff2 do writeln(T2[i]);
end.