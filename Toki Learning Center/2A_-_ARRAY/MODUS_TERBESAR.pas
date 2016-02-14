Program mainan;
 
var
    x : array[1..100000] of longint;
    y : array[1..100000] of longint;
    n, i, j, frek, modus : longint;
    cek : boolean;
     
begin
    readln(n); frek := 0; modus := 0;
    for i:=1 to n do
    begin
        readln(x[i]);
        y[i] := 1;
        j := i-1;
        cek := false;
        while ((not cek) and (j >= 1)) do
        begin
            if (x[i] = x[j]) then
            begin
                y[i] := y[i] + y[j];
                cek := true;
            end else j := j - 1;
        end;
        if (y[i] > frek) then frek := y[i];
    end;
    for i:=1 to n do
    begin
        if ((y[i] = frek) and (x[i] > modus)) then modus := x[i];
    end;
    writeln(modus);
end.