uses math;
var
	ans, i, j, k, n, tmp : integer;
	a : array[1..105] of integer;
  
begin
	read(n);
	for i:=1 to n do read(a[i]);
	ans := 0;
	for i:=1 to n do
	begin
		for j:=i to n do
		begin
			for k:=i to j do a[k] := a[k] xor 1;
			tmp := 0;
			for k:=1 to n do
				if(a[k] = 1) then
					inc(tmp);
			if(tmp > ans) then ans := tmp;
			for k:=i to j do a[k] := a[k] xor 1;
		end;
	end;
	writeln(ans);
end.