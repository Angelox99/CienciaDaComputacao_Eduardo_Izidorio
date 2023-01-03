.data
	msg1: .asciiz "Digite um numero para contar: "
	espaco: .byte ' '
	
.text
	#leitura do numero
	li $v0, 4 
	la $a0, msg1
	syscall 
	
	li $v0, 5
	syscall
	
	move $t0, $v0 #movendo o $v0 para o resgistrador $t0
	
	move $t1, $zero #movendo o zero para o registrador $t1
	
	loop:
		bgt $t1, $t0, saida
		
		#impressao $t1
		li $v0, 1
		move $a0, $t1
		syscall
		
		#impressao do espaço em branco
		li $v0, 4
		la $a0, espaco
		syscall
		
		addi $t1, $t1, 1 #incremento de 1
		j loop #jump
		
	saida: 
		
		
