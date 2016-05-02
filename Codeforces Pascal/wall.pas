Program TheWall;

var
	x,y,a,b,i,start,count : longint;

function gcd(m, n : longint) : longint;
begin
	if n = 0  then
		gcd := m
	else
		gcd := gcd(n, m mod n);
end;

function lcm(m, n:longint):longint;
begin
	lcm:=(m*n) div gcd(m,n);
end;

begin
	readln(x,y,a,b);
	count := 0;
	i := lcm(x,y);
	if (i >= a) then start := i
	else if (a mod i = 0) then start := a
	else start := (a div i + 1) * i;
	
	if (b mod start = 0) then count := (b - a) div i + 1
	else begin
		while(start <= b) do
		begin
			writeln(count,' ',start);
			count := count + 1;
			start := start + i;
		end;
	end;
	writeln(count);
end.