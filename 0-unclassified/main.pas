var
	menu : string
	
procedure P1-load;
var
begin
	// kodenya disini
end;

procedure P2-save;
var
begin
	//ngerjain disininya
end;

begin
	read(menu)
	while(true)
		switch (menu) :
			case 'load' : P1-load
			case 'save' : P2-save
			...
			case 'exit' : P15-exit
		end;
	end;
end.