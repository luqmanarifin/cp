var
  n, m, a, p, q : int64;
  
begin
  read(n, m, a);
  p := n div a;
  if(n mod a <> 0) then inc(p);
  q := m div a;
  if(m mod a <> 0) then inc(q);
  writeln(p * q);
end.