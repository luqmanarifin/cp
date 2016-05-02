Program CoklatUntukBebek;

var
	x, i : int64;

begin
	readln(x);
	i := 1;
	repeat
		i := i + 1;
	until (i * (i+1) div 2 > x);
	writeln(i);
end.