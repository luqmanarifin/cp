Program p476;
 
var
    x, i: longint;
 
begin
    readln(x);
    for i:=x downto 1 do
    begin
        if (x mod i = 0) then writeln(i);
    end;
end.