Program p476;
 
var
    a, b, i: longint;
 
begin
    readln(a, b);
    for i:=1 to a do
    begin
        if (i mod b = 0) then write('*')
        else write(i);
        if(i <> a) then write(' ')
        else writeln;
    end;
end.