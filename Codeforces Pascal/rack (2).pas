// 368 A
var
	n,d,m,ans,i : integer;
	a : array[1..100] of integer;
	
begin
	readln(n,d); ans:=0;
	for i:=1 to 100 do a[i]:=0;
	for i:=1 to n do begin
		read(m);
		inc(a[m]);
	end;
	readln(m); i:=1;
	while(m > 0)and(i<=100) do begin
		if(m >= a[i])then begin
			ans := ans + i*a[i];
		end else
			ans := ans + i*m;
		m := m-a[i];
		inc(i);
	end;
	if(m > 0) then ans := ans - m*d;
	writeln(ans);
end.