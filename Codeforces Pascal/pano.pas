Program DelapanKosongA;

var
	n,m,i : integer;
	
function CekPrima(a : integer): boolean;
var
	i : integer;
begin
	CekPrima := true;
	for i:=2 to trunc(sqrt(a)) do
	begin
		if (a mod i = 0) then CekPrima := false;
	end;
end;

begin
	readln(n,m);
	for i:=n+1 to m-1 do
	begin
		if(CekPrima(i)) then
		begin
			writeln('NO');
			halt(0);
		end;
	end;
	if(CekPrima(m)) then writeln('YES')
	else writeln('NO');
end.