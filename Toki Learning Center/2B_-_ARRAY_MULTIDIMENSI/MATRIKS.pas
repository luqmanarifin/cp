Program mainan;
 
var
    x : array[1..100, 1..100] of integer;
    i, j, m, n : integer;
     
begin
    readln(m, n);
    for i:=1 to m do
    begin
        for j:=1 to n do
            if (j <> n) then read(x[i,j])
            else readln(x[i,j]);
    end;
     
    for j:=1 to n do
    begin
        for i:=m downto 1 do
        begin
            if (i <> 1) then write(x[i,j], ' ')
            else writeln(x[i,j]);
        end;
    end;
end.
     