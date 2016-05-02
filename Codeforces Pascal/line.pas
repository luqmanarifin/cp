Program DimaAndLines;

var
	i, j, n : longint;
	x : array[0..1000] of longint;
	cek : boolean;

begin
	readln(n); cek := false;
	for i:=1 to n do
	begin
		if (i <> n) then read(x[i])
		else readln(x[i]);
		x[0] := x[1];
		if (i <> 1) then
		begin
			if(x[i] > x[i-1]) then
			begin
				for j:=i-2 downto 1 do
				begin
					if ((x[j] > x[i-1]) and(x[j] < x[i]) and ((x[j-1] < x[i-1]) or (x[j-1] > x[i]) or (x[j+1] < x[i-1]) or (x[j+1] > x[i]))) then cek := true;
				end;
			end else
			begin
				for j:=i-2 downto 1 do
				begin
					if ((x[j] < x[i-1]) and(x[j] > x[i])and ((x[j-1] > x[i-1]) or (x[j-1] < x[i]) or (x[j+1] > x[i-1]) or (x[j+1] < x[i]))) then cek := true;
				end;
			end;
		end;
	end;
	if(cek) then writeln('yes')
	else writeln('no');
end.