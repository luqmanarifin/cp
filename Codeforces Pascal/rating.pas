// 379 C

var
	i,j,n : longint;
	a : array[1..300000] of longint;
	b : array[1..1000000000] of boolean;
	
begin
	readln(n);
	for i:=1 to n do
	begin	
		read(j);
		if (b[j] = false) then
		begin
			b[j] := true;
			a[i] := j;
		end else begin
			repeat
				inc(j);
			until(b[j] = false);
			b[j] := true;
			a[i] := j;
		end;
	end;
	for i:=1 to n do write(a[i],' ');
end.