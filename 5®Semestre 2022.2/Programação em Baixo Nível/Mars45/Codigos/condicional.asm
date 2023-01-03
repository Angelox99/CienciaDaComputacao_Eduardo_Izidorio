.data
	msg: .asciiz "Digite um número: "
	par: .asciiz "O número é par"
	impar: .asciiz "O número é ímpar"
	
.text
	#imprimindo msg para o usuário
	li $v0, 4
	la $a0, msg
	syscall
	
	#ler o número
	li $v0, 5
	syscall
	
	li $t0, 2
	div $v0, $t0
	
	mfhi $t1
	
	beq $t1, $zero, imprimePar
	
	li $v0, 4
	la $a0, impar
	syscall
	
	li $v0, 10 #Finaliza o programa
	syscall
	
	#Se o número de entrada for par, o programa...
	imprimePar: #Rótulo criado para responder
	li $v0, 4
	la $a0, par
	syscall
