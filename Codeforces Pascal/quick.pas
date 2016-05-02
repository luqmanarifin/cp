var
	i,n : longint;
	a,b : array[1..10] of longint;

procedure swap(var a,b : longint);
var
	temp : longint;
begin
	temp := a;
	a := b;
	b := temp;
end;

procedure Quick
    ( var b : array of longint (* in out - list to be sorted *) ;
			a : array of longint										 ;
         First : longint (* in - first item in sublist *) ;
         Last : longint (* in - last item in sublist *) ) ;
 
 var
     Pivot : longint ;
     i : longint ;
     j : longint ;

    begin (* procedure *)
         if First>=Last then begin
             (* do nothing it is sorted *)
         end else begin
              i := First ;
              J := Last + 1 ;
              Pivot := a[First] ;

              repeat
                  repeat
                    i := i + 1;
                  until a[i] >= Pivot ;
                  repeat
                    j := j - 1;
                  until a[j] <=Pivot ;
                  if i < j then begin
                     Swap (b[i], b[j]) ;
							swap (a[i], a[j]) ;
                  end ;
              until i>=j ;
					swap (a[first], a[j]);
              Swap (b[First],b[j]);
              Quick(b,a, First, j - 1);
              Quick(b,a, j+1, Last) ;
         end  (* if *) ;
    end  (* Quick *) ; 
	 
begin
	readln(n);
	for i:=1 to n do
	begin
		read(a[i]);
		b[i] := i;
	end;
	quick(b,a,0,n-1);
	for i:=1 to n do write(b[i],' ');
end.