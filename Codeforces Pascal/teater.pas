Program Theatre;

var
	n, m, a, hasil : int64;

begin
	readln(n,m,a);
	if ((n mod a = 0) and (m mod a = 0)) then hasil := (n div a) * (m div a)
	else if (n mod a = 0) then hasil := (n div a) * (m div a + 1)
	else if (m mod a = 0) then hasil := (n div a + 1) * (m div a)
	else hasil := (n div a + 1) * (m div a + 1);
	writeln(hasil);
end.