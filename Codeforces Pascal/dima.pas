// 374C

uses math;
const
  fi='';
  fo='';
  maxn=1002;
  dx:array[1..4] of integer=(0,0,1,-1);
  dy:array[1..4] of integer=(1,-1,0,0);
var
  next,prev:array[1..4] of integer;
  a:array[1..maxn,1..maxn] of integer;
  d,mark,xong:array[1..maxn,1..maxn] of boolean;
  f:array[1..maxn,1..maxn] of integer;
  n,m:integer;
  circle:boolean;
  function apakah(i,j:integer):boolean;
    begin
      apakah:=(i>=1) and (i<=n) and (j>=1) and (j<=m);
    end;
  procedure iuh;
    var
      i,j:integer;
      u:char;
    begin
      assign(input,fi);reset(input);
      assign(output,fo);rewrite(output);
      readln(n,m);
      for i:=1 to n do
        begin
          for j:=1 to m do
            begin
              read(u);
              if u='D' then a[i,j]:=1;
              if u='I' then a[i,j]:=2;
              if u='M' then a[i,j]:=3;
              if u='A' then a[i,j]:=4;
            end;
          readln;
        end;
      for i:=1 to 4 do
        begin
          next[i]:=i+1;prev[i]:=i-1;
        end;
      prev[1]:=4;next[4]:=1;
    end;
  procedure dfs(u,v:integer);
    var
      i,xt,yt:integer;
    begin
      d[u,v]:=true;
      for i:=1 to 4 do
        if apakah(u+dx[i],v+dy[i]) then
          begin
            xt:=u+dx[i];yt:=v+dy[i];
            if (a[xt,yt]=next[a[u,v]]) then
              begin
                if d[xt,yt]=false then dfs(xt,yt)
                else
                  if xong[xt,yt]=false then circle:=true;
              end;
          end;
      xong[u,v]:=true;
    end;
  procedure dq(u,v:integer);
    var i:integer;
    begin
      if mark[u,v] then exit;
      mark[u,v]:=true;
      if a[u,v]=1 then f[u,v]:=1;
      for i:=1 to 4 do
        if apakah(u+dx[i],v+dy[i]) then
          if a[u+dx[i],v+dy[i]]=prev[a[u,v]] then
            begin
              dq(u+Dx[i],v+dy[i]);
              f[u,v]:=max(f[u,v],f[u+dx[i],v+dy[i]]+1);
            end;
    end;
  procedure process;
    var
      i,j,kq:integer;
    begin
      circle:=false;
      for i:=1 to n do
        for j:=1 to m do
          if d[i,j]=false then
            if a[i,j]=1 then
              dfs(i,j);
      if circle then
        begin
          writeln('Poor Inna!');
          exit;
        end;
      for i:=1 to n do
        for j:=1 to m do
          dq(i,j);
      kq:=0;
      for i:=1 to n do
        for j:=1 to m do
          kq:=max(kq,f[i,j]);
      if kq div 4=0 then writeln('Poor Dima!')
      else writeln(kq div 4);
    end;
begin
  iuh;
  process;
end.