Program RomaMain;

var
	a,n,k,i,count : longint;

procedure iuh(a: longint; digit : longint; var count : longint);
var
	i,n : longint;

begin
	n := 0;
	for i:=1 to 9 do
	begin
		if((a mod 10 = 7) or (a mod 10 = 4)) then n := n + 1;
		a := (a - a mod 10) div 10;
	end;
	if(n <= digit) then count := count + 1;
end;

begin
	readln(n,k);
	for i:=1 to n do
	begin
		read(a); iuh(a,k,count);
	end; writeln(count);
end.