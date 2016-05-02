Program Serejand;

var
	n,m,i,j,li : longint;
	jawab : array[1..100000] of longint;
	a : array[1..100000,1..2] of longint;
	cek : boolean;
	
begin	
	readln(n,m);
	for i:=1 to 100000 do
	begin
		jawab[i] := 0;
		a[1,2] := 0;
	end;
	for i:=1 to n do
	begin
		if (i <> n) then read(a[i,1])
		else readln(a[n,1]);
		cek := false; j:= i-1;
		while((j >= 1) and not(cek)) do
		begin
			if (a[j,1] = a[i,1]) then
			begin
				a[i,2] := a[j,1] + 1;
				cek := true;
			end else j := j - 1;
		end;
	end;
	for i:=1 to m do
	begin
		readln(li);
		for j:=li to n do
			if(a[j,2] = 1) then jawab[i] := jawab[i] + 1;
	end;
end.;