// 303 A
var
	n,i : longint;
begin
	readln(n);
	if(n mod 2 = 0) then begin
		writeln(-1); halt;
	end;
	for i:=0 to n-1 do write(i,' '); writeln;
	for i:=0 to n-1 do write(i,' '); writeln;
	for i:=0 to n-1 do write((i*2) mod n,' '); writeln;
end.