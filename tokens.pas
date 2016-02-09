var n,a,b,i,j,x,y:longint;
begin
	readln(n,a,b);
	for i:=1 to n do begin
		read(x); y:=x;
		for j:=0 to y do
			if (y*a div b=(y-j)*a div b) then begin
				x:=j;
			end;
		write(x, ' ');
	end;
	writeln;
end.