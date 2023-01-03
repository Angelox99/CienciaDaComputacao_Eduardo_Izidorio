.data
	msg1: .asciiz "Digite o primeiro numero: "
	msg2: .asciiz "Digite o segundo numero: "
	resultado: .asciiz "Resultado: "

.text
	li $v0, 4 #Codigo para print
	la $a0, msg1#argumento do print
	syscall # solicita que o kernel execute
	
	li $v0, 5 #realiza leitura
	syscall
	
	move $s0, $v0 #mover o valor de V0 para o s0
	
	#leitura do segundo numero
	
	li $v0, 4 #Codigo para print
	la $a0, msg2#argumento do print
	syscall # solicita que o kernel execute
	
	li $v0, 5 #realiza leitura
	syscall
	
	move $s1, $v0 #mover o valor de V0 para o s0
	
	mulo $s2, $s0, $s1
	li $v0, 4
	la $a0, resultado
	
	syscall
	
	li $v0, 1 
	move $a0, $s2
	syscall
