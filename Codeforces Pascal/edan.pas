// B

var
	n,i,j : integer;
	a : array[1..300] of integer;
	
begin
	readln(n);
	for i:=1 to n do read(a[i]);
	for i:=1 to n do
	begin
		for j:=1 to a[i] do
			if (i = n) then write('LRP')
			else write('RLP');
		if(i <> n) then write('R');
	end;
end.
			