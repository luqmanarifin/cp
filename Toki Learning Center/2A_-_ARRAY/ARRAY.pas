Program mainan;
 
var
    x: array[1..25000] of integer;
    i, count : integer;
begin
    i := 1;
    while not eof do
    begin
        readln(x[i]);
        i := i + 1;
    end;
    count := i-1;
    for i:=count downto 1 do
    begin
        writeln(x[i]);
    end;
end.