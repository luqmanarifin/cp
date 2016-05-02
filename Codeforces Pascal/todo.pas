Program TigaEnamEnamB;

var
	n,k,x,min,mini : int64; i: longint;
	a : array[0..100000] of int64;

begin
	readln(n,k); min := 1000 * 100000;
	for i:=0 to 100000 do a[i] := 0;
	for i:=1 to n do
	begin
		read(x);
		a[i mod k] := a[i mod k] + x;
		if (((i div k = n div k - 1) and (i mod k <> 0)) or (i = n)) then
		begin
			if (a[i mod k] < min) then
			begin
				min := a[i mod k];
				mini := i;
			end;
		end;
	end;
	if (mini mod k <> 0) then writeln(mini mod k)
	else writeln(k);
end.	