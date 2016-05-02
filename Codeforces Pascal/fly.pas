// 386 B

var
	n,m,i,temp,ans,j : integer;
	t : array[1..2000] of integer;
	
begin
	readln(n);
	for i:=1 to 2000 do t[i] := 0;
	for i:=1 to n do begin
		read(temp);
		inc(t[temp]);
	end;
	readln(m); ans := 0;
	for i:=1 to 1000 do begin
		temp := 0;
		for j:=0 to m do
			temp := temp + t[i+j];
		if temp > ans then ans := temp;
	end;
	writeln(ans);
end.