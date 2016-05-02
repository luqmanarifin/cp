const maxnum = 10000000000;
var
	n, t, l, r, m, max: int64;
	cek : boolean;
	i : longint;
	is : array[1..1293847] of int64;
begin
	is[1] := 0;
	is[2] := 1;
	i := 2;
	while(is[i] <= maxnum) do begin
		inc(i);
		is[i] := is[i-1] + is[i-2];
	end;
	max := i;
	
	read(t);
	for i:=1 to t do begin
		cek := false;
		read(n);
		l := 1; r := max;
		while(l <= r) do begin
			m := (l + r) div 2;
			if(is[m] <= n) then begin
				l := m + 1;
				if(is[m] = n) then cek := true;
			end else
				r := m - 1;
		end;
		if(cek) then writeln('IsFibo')
		else writeln('IsNotFibo');
	end; 
end.