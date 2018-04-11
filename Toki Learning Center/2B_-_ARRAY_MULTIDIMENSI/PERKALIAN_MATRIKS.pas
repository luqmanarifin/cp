Program mainan;
 
var
    x : array[1..75, 1..75] of integer;
    y : array[1..75, 1..75] of integer;
    c : array[1..75, 1..75] of integer;
    i, j, k, m, n, p : integer;
     
begin
    readln(m, n);
    for i:=1 to m do
    begin
        for j:= 1 to n do
        begin
            if (j<>n) then read(x[i,j])
            else readln(x[i,j]);
        end;
    end;
     
    readln(n, p);
    for i:=1 to n do
    begin
        for j:=1 to p do
        begin
            if (j<>p) then read(y[i,j])
            else readln(y[i,j]);
        end;
    end;
     
    for i:=1 to m do
    begin
        for j:=1 to p do
        begin
            c[i,j] := 0;
            for k:= 1 to n do
            begin
                c[i,j] := c[i,j] + x[i,k] * y[k,j];
            end;
            if (j <> p) then write(c[i,j], ' ')
            else writeln(c[i,j]);
        end;
    end;
end.