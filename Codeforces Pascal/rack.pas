// 368 A

var
	a : array[1..5] of integer;
	i : integer;
	
Procedure BubbleSort(x: array of integer; size:integer);
var i,j,temp: integer;
begin
	for i := size downto 1 do
		for j := 1 to i-1 do
			if x[j] > x[j+1] then
			begin
				{ swapping: x[j]<->x[j+1] }
				temp := x[j];
				x[j] := x[j+1];
				x[j+1] := temp;
			end;
end;

begin
	for i:=1 to 5 do read(a[i]);
	BubbleSort(a,5);
	for i:=1 to 5 do write(a[i],' ');
end.