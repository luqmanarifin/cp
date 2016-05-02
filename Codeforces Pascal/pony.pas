Program Contest;

var
	n,m,i,j,a,b,ans,temp : longint;
	
function min(a,b : longint) : longint;
begin
	if (a < b) then min := a
	else min := b;
end;

function max(a,b : longint) : longint;
begin
	if (a > b) then max := a
	else max := b;
end;
	
procedure find(n,m,i,j,a,b : longint ; var ans : longint);
var
	c,d,e,f,x : longint;
begin
	c := -1; d := -1; e := -1; f := -1;
	if ((((n - i) div b = (m - j) div a)) and ((n - i) mod b = 0) and ((m - j) mod a = 0)) then c := (m - j) div a
	else if (((n - i) mod b = 0) and ((m - j) mod a = 0)) then
		if (abs((n - i) div b - (m - j) div a) mod 2 = 0) then c := max((n - i) div b,(m - j) div a);
	
	if ((((i - 1) div b = (m - j) div a)) and ((i - 1) mod b = 0) and ((m - j) mod a = 0)) then d := (m - j) div a
	else if (((i - 1) mod b = 0) and ((m - j) mod a = 0)) then
		if (abs((i - 1) div b - (m - j) div a) mod 2 = 0) then d := max((i - 1) div b,(m - j) div a);
	
	if ((((n - i) div b = (j - 1) div a)) and ((n - i) mod b = 0) and ((j - 1) mod a = 0)) then e := (j - 1) div a
	else if (((n - i) mod b = 0) and ((j - 1) mod a = 0)) then
		if (abs((n - i) div b - (j - 1) div a) mod 2 = 0) then e := max((n - i) div b,(j - 1) div a);
	
	if ((((i - 1) div b = (j - 1) div a)) and ((i - 1) mod b = 0) and ((j - 1) mod a = 0)) then f := (j - 1) div a
	else if (((i - 1) mod b = 0) and ((j - 1) mod a = 0)) then
		if (abs((i - 1) div b - (j - 1) div a) mod 2 = 0) then f := max((i - 1) div b,(j - 1) div a);
	
	x := min(c,min(d,min(e,f)));
	ans := 1000000;
	if ((c = -1) and (d = -1) and (e = -1) and (f = -1)) then ans := -1
	else if (((n = b) or (m = a)) and (((i <> 1) and (i <> n)) or ((j <> 1) and (j <> m)))) then ans := -1
	else if (x <> -1) then ans := x
	else begin
		if ((c <> -1) and (c < ans)) then ans := c;
		if ((d <> -1) and (d < ans)) then ans := d;
		if ((e <> -1) and (e < ans)) then ans := e;
		if ((f <> -1) and (f < ans)) then ans := f;
	end;
	if ((ans > 0) and ((b > n) or (a > m))) then ans := -1;
end;
	
begin
	readln(n,m,i,j,a,b);
	temp := a; a := b; b := temp;
	find(n,m,i,j,a,b,ans);
	if (ans = -1) then writeln('Poor Inna and pony!')
	else writeln(ans);
end.