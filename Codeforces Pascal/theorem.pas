// 304 A

var
	a,c,n,ans : longint;
	
begin
	ans := 0;
	readln(n);
		for c:=n downto 5 do
			for a:=3 to c-1 do
				if(frac(sqrt(c*c-a*a))=0) then
					inc(ans);
	writeln(ans div 2);
end.