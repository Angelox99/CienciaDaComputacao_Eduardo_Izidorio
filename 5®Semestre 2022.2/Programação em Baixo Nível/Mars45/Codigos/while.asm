.data
	espaco: .byte ' '
.text
	#ler o número
	li $v0, 5
	syscall
	
	move $t0,  $v0 #valor lido. v0 ira mover para o t0
	
	move $t1, $zero #valor de zero vai mover para t1
	
	laco:
		bgt $t1, $t0, sair
		
		#imprimir $t1
		li $v0, 1
		move $a0, $t1
		syscall
		
		#imprimir um espaço em branco entre os números
		li $v0, 4
		la $a0, espaco
		syscall
		
		addi $t1, $t1, 1
		j laco
	sair: