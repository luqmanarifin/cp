// 344 B

var
	a,b,c,x,y,z : longint;
	
begin
	readln(a,b,c);
	x := (a + b - c) div 2;
	y := (-a + b + c) div 2;
	z := (a - b + c) div 2;
	if (x < 0) or (y < 0) or (z < 0) or ((a + b + c) mod 2 = 1) then writeln('Impossible')
	else writeln(x,' ',y,' ',z);
end.