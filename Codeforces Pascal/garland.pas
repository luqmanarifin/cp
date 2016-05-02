var
	a, b : array['a'..'z'] of longint;
	aa, bb : ansistring;
	ans, i, n : longint;
	c : char;
	
function min(a : longint; b : longint): longint;
begin
	if(a < b) then min := a
	else min := b;
end;
	
begin
	ans := 0;
	for c:='a' to 'z' do begin
		a[c] := 0;
		b[c] := 0;
	end;
	readln(aa); readln(bb);
	
	n := length(aa);
	for i:=1 to n do
		inc(a[aa[i]]);
		
	n := length(bb);
	for i:=1 to n do
		inc(b[bb[i]]);
	
	for c:='a' to 'z' do begin
		if(a[c] >= b[c]) then
			inc(ans, b[c])
		else if(a[c] < b[c]) and (a[c] <> 0) then
			inc(ans, a[c])
		else begin
			writeln(-1);
			halt;
		end;
	end;
	writeln(ans);
end.