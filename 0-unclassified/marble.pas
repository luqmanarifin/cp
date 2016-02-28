uses math;

var
  n, s, t, i, ans : longint;
  a : array[0..199999] of longint;
  done : array[0..100000] of boolean;
  
begin
  fillchar(done, sizeof(done), false);
  read(n, s, t);
  for i := 1 to n do
  begin
    read(a[i]);
  end;
  ans := 0;
  while(s <> t) do
  begin
    if(done[s]) then
    begin
      writeln(-1);
      halt(0);
    end;
    done[s] := true;
    inc(ans);
    s := a[s];
  end;
  writeln(ans);
end.