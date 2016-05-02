// 143 A

var
	r1,r2,c1,c2,d1,d2 : integer;
	a,b,c,d : integer;
begin
	readln(r1,r2);
	readln(c1,c2);
	readln(d1,d2);
	a := c1 + r1 - d2;
	b := r1 - c1 + d2;
	c := d2 - r1 + c1;
	d := c2 + r2 - d2;
	if(a mod 2 = 1)or(b mod 2 = 1)or(c mod 2 = 1)or(d mod 2 = 1)or(a>18)or(b>19)or(c>18)or(d>18)or(a<2)or(b<2)or(c<2)or(d<2) then writeln(-1)
	else begin
		writeln(a div 2,' ',b div 2);
		writeln(c div 2,' ',d div 2);
	end;
end.