Program Pzim ;
var
		a,num:integer;
		
Begin
	num:=random(10);
	write('O n�mero imaginado �: ',num);
	a:=0;
	repeat
		a:=random(10);
		writeln(a);
	until(a=num);
	writeln(a);	
  
End.