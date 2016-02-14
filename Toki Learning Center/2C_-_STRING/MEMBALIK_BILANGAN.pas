    var
    n,i,j,p,x:longint;
    a,s:ansistring;
     
     
     
    begin
    readln(n);
    for i:=1 to n do begin
    a:='';
    readln(s);
    if s= '0' then writeln ('0')
    else begin
    p:=length(s);
    for j:=p downto 1 do begin
    a:=a+s[j];
    end;
    val(a,x);
    writeln(x);
    end;
    end;
    end.