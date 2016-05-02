Program Translation;

var
	a,b : widestring;
	x : array[1..1000] of widestring;
	i,n : integer;

begin
	readln(a);
	n := length(a);
	for i:=1 to n do
	begin
		b := a;
		delete(b,1,i-1); delete(b,2,n-i);
		x[i] := b;
	end; b := '';
	for i:=1 to n do
	begin
		insert(x[i],b,1);
	end;
	writeln(b);
end.		