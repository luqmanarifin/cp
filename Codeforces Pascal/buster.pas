//382 B

var
	a,b,w,x,c,ans : int64;
	
begin
	ans := 0;
	readln(a,b,w,x,c);
	while(c > a) do
	begin	
		c := c - 1;
		if(b >= x) then b := b - x
		else begin
			a := a - 1;
			b := b + w - x;
		end;
		ans := ans + 1;
		writeln(a,' ',b,' ',w,' ',x,' ',c);
	end;
	writeln(ans);
end.