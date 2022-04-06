//Questão 12 lista 1
Program Pzim ;
var
    A,B,C,X1,X2: real;
Begin
	readln(A);
	readln(B);
	readln(C);
	X1:= (-B + sqrt((B*B)-4*A*C))/(2*A);
	X2:= (-B - sqrt((B*B)-4*A*C))/(2*A);
	writeln(X1,'   ',X2);
  
End.