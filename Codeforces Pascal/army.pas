Program armyontheHell;

var
	n,a,b,i : integer;
	d : array[1..100] of integer;
	tahun : longint;
	
begin
	readln(n); tahun := 0;
	for i:=1 to n-1 do read(d[i]);
	readln(a,b);
	for i:=a to b-1 do tahun := tahun + d[i]; writeln(tahun);
end.