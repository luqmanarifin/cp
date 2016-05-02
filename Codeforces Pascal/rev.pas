// rev

var
	n,i,j,w : longint;
	a : array[1..300] of longint;
	b : string;
	
begin
	readln(b);
	readln(w);
	for i:=1 to 300 do a[i] := 0;
	i := 1;
	for j:=1 to length(b) do
	begin
		if(b[j] = 'P') then inc(a[i])
		else if (b[j] = 'R') then inc(i)
		else if (b[j] = 'L') then dec(i);
	end;
	for i:=1 to w do write(a[i],' ');
end.