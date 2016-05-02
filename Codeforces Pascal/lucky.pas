Program LuckyNumber;

var
	a,count,n : int64; i : longint;
	kata,temp : string;

begin
	readln(a);
	str(a,kata); count := 0; n:= length(kata);
	for i:=1 to 18 do
	begin
		temp := kata;
		delete(temp,1,i-1); delete(temp,2,n-i);
		if ((temp = '4') or (temp = '7')) then count := count + 1;
	end;
	if((count = 4) or (count = 7)) then writeln('YES')
	else writeln('NO');
end.