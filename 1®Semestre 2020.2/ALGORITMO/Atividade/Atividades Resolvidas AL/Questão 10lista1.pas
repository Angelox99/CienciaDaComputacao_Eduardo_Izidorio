//programa da questão 10 lista 1
Program Pzim ;
var
    N1: integer;
    N2: integer;
    N3: integer;
    
Begin
	readln(N1);
	readln(N2);
	N3:=N1;
	N1:=N2;
	N2:=N3;
	writeln(N1,'     ',N2);
End.