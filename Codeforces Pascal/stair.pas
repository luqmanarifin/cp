// B

var
	n,i,a,min,max,naik,turun : longint;
	b : array[1..5000] of longint;
	
begin
	readln(n);
	for i:=1 to 5000 do b[i] := 0;
	for i:=1 to n do
	begin
		read(a);
		inc(b[a]);
	end;
	i := 1;
	while(i <= 5000) do
		if (b[i] <> 0) then
		begin
			min := i;
			break;
		end else inc(i);
	i := 5000;
	while(i >= 1) do
		if (b[i] <> 0) then
		begin
			max := i;
			break
		end else dec(i);
	naik := 0; turun := 0;
	for i:=min to max do
	begin
		if(b[i] >= 2) and (i <> max) then inc(naik);
		if(b[i] <> 0) and (i <> max) then inc(turun);
	end;
	writeln(naik+turun+1);
	for i:=min to max-1 do
		if(b[i] >= 2) then write(i,' ');
	write(max,' ');
	for i:=max-1 downto min do
		if(b[i] <> 0) then write(i,' ');
end.