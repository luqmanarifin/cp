Program MainTaxi;

var
	n, satu, dua, tiga, empat, i, x, a : longint;

begin
	readln(n); satu := 0; dua := 0; tiga := 0; empat := 0;
	for i:=1 to n do
	begin
		read(x);
		if (x = 1) then satu := satu + 1
		else if (x = 2) then dua := dua + 1
		else if (x = 3) then tiga := tiga + 1
		else empat := empat + 1;
	end;
	if ((tiga >= satu) and (dua mod 2 = 0)) then a := empat + tiga + dua div 2
	else if ((tiga >= satu) and (dua mod 2 <> 0)) then a := empat + tiga + dua div 2 + 1
	else if ((tiga <= satu) and (dua mod 2 = 0) and ((satu - tiga) mod 4 = 0)) then a := empat + tiga + (satu - tiga) div 4 + dua div 2
	else if ((tiga <= satu) and (dua mod 2 = 0) and ((satu - tiga) mod 4 <> 0)) then a := empat + tiga + (satu - tiga) div 4 + dua div 2 + 1
	else if ((tiga <= satu) and (dua mod 2 <> 0) and (satu - tiga <= 2)) then a := empat + tiga + dua div 2 + 1
	else if ((tiga <= satu) and (dua mod 2 <> 0) and (satu - tiga > 2) and ((satu - tiga - 2) mod 4 = 0)) then a := empat + tiga + dua div 2 + 1 + (satu - tiga - 2) div 4
	else a := empat + tiga + dua div 2 + 1 + (satu - tiga - 2) div 4 + 1;
	writeln(a);
end.