var
	ab, bc, cd : real;
	a,b,c,d,ans : integer;
	
begin
	readln(a,b,c,d);
	ab := a/b; bc := b/c; cd := c/d;
	if(b - a = c - b)and(c - b = d - c) then ans := d + b - a
	else if (ab = bc) and (bc = cd) and (frac(d*b/a)=0) then ans := trunc(d*b/a)
	else ans:=42;
	writeln(ans);
end.