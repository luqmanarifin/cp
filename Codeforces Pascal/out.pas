// 275 A

var
	x : array[0..4,0..4] of integer;
	n : array[1..3,1..3] of integer;
	i,j : integer;
	
procedure tekan;
begin
	for i:=1 to 3 do
		for j:=1 to 3 do
		begin
			read(n[i,j]);
			x[i,j] := x[i,j] + n[i,j];
			x[i,j+1] := x[i,j+1] + n[i,j];
			x[i+1,j] := x[i+1,j] + n[i,j];
			x[i,j-1] := x[i,j-1] + n[i,j];
			x[i-1,j] := x[i-1,j] + n[i,j];
		end;
	for i:=1 to 3 do
	begin
		for j:=1 to 3 do
			write(x[i,j] mod 2);
		writeln;
	end;
end;
	
begin
	for i:=0 to 4 do
		for j:=0 to 4 do x[i,j] := 1;
	tekan;
end.