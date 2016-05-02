// contest A

var
	s : ansistring;
	berat,a : int64;
	i,n : longint;
	
begin
	readln(s); berat := 0;
	n := pos('^',s);
	for i:=1 to n-1 do
	begin
		if(s[i] <> '=') then
		begin
			val(s[i],a);
			berat := berat + a*(n - i);
		end;
	end;
	for i:=n+1 to length(s) do
	begin
		if(s[i] <> '=') then
		begin
			val(s[i],a);
			berat := berat - a*(i - n);
		end;
	end;
	if (berat > 0) then writeln('left')
	else if (berat = 0) then writeln('balance')
	else writeln('right');
end.