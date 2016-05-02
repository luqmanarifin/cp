    program modus;
    var
    a:array [0..1000] of integer;
    i,n, b, max, maxi:integer;
    begin
    // init
    for i:=1 to 1000 do a[i]:=0;
    max:=0;
    // read and processing
    readln(n);
    for i:=1 to n do
    begin
    readln(b);
    inc(a[b]);
    if (max<a[b]) then
    begin
    max:=a[b];
    maxi:=b;
    end;
    end;
    writeln(maxi);
    end.