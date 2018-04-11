Program p476;
 
var
    bil : longint;
     
function Faktorial(n: integer): longint;
var
    i: integer;
    bil: longint;
begin
    bil := 1;
    for i := 1 to n do
        bil := bil * i;
    Faktorial := bil;
end;
     
begin
    readln(bil);
    if ((bil < 0)or(bil > 10)) then writeln('ditolak')
    else if (bil = 0) then writeln(1)
    else writeln(Faktorial(bil));
end.
     