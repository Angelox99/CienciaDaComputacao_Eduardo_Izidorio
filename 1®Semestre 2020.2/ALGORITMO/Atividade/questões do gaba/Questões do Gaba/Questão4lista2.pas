Program TABUADA ;

var
	cont,num,i:integer;
	
Begin
	readln(num);
	cont:=0;
	for i := 1 to 10 do
		writeln(num,'x',i,'=', num*i);  
End.