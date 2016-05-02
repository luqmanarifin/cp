program Project1;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
  tt = record
    s, f, y, z, t: int64;
  end;

var
  a: array[1..1000000] of tt;
  x, y, z, n, k, t, t2: int64;
  i, j: integer;
  l: int64;

function f(q, x: int64): int64;
var
  l: int64;
  j: integer;
begin
  if (a[q].t = 1) then
  begin
    result := a[q].y;
    exit;
  end;
  l := (x - a[q].s + 1) mod a[q].y;
  if (l = 0) then
    l := a[q].y;
  for j := 1 to k do
    if (a[j].s <= l) and (a[j].f >= l) then
    begin
      result := f(j, l);
      exit;
    end;
end;

begin
  readln(k);
  l := 0;
  for i := 1 to k do
  begin
    read(x);
    if (x = 1) then
    begin
      readln(y);
      inc(l);
      a[i].s := l;
      a[i].f := l;
      a[i].y := y;
      a[i].t := x;
    end;
    if (x = 2) then
    begin
      readln(y, z);
      a[i].t := x;
      a[i].s := l+1;
      a[i].y := y;
      a[i].z := z;
      inc(l, y*z);
      a[i].f := l;
    end;
  end;
  readln(n);
  t := 1;
  for i := 1 to n do
  begin
    read(x);
    for j := t to k do
      if (a[j].s <= x) and (a[j].f >= x) then
      begin
        write(f(j, x),' ');
        t2 := j;
        break;
      end;
    t := t2;
  end;
  readln;
  readln;
end.