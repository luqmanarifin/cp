Program AmusingJoke;

var
	a,b,c,temp: string; n,i : integer;

begin
	readln(a); readln(b); readln(c);
	insert(a,b,1); n := length(b);
	if (n <> length(c)) then writeln('NO')
	else begin
		for i:=1 to n do
		begin
			temp := b;
			delete(temp,1,i-1); delete(temp,2,n-i);
			delete(c,pos(temp,c),1);
		end;
		if(c = '') then writeln('YES')
		else writeln('NO');
	end;
end.