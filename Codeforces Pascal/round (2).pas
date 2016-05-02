// B
var
	n,m,i,temp,ans,rem : longint;
	a,b : array[1..1000000] of longint;
begin
	readln(n,m);
	for i:=1 to 2 do begin a[i]:=0;b[i]:=0; end;
	ans :=0; rem := 0;
	for i:=1 to n do begin
		read(temp);
		inc(a[temp]);
	end;
	for i:=1 to m do begin
		read(temp);
		inc(b[temp]);
	end;
	for i:=1000000 downto 1 do begin
		if(a[i] > b[i]) then begin
			if(rem = 0)then  ans := ans + 1
			else rem := rem - 1;
		end else if(a[i] < b[i]) then rem := rem + b[i] - a[i];
	end;
	if(ans < 0) then writeln(0)
	else writeln(ans);
end.