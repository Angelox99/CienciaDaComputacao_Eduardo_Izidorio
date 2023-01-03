.data
	msg1: .asciiz "Digite o primeiro numero: "
	msg2: .asciiz "Digite o segundo numero: "
	resultado: .asciiz "Resultado: "

.text
	#leitura do primeiro número
	li $v0, 4 #Codigo para print
	la $a0, msg1#argumento do print
	syscall # solicita que o kernel execute
	
	li $v0, 5 #realiza leitura
	syscall
	
	move $t0, $v0 #mover o valor de V0 para o t0
	
	#leitura do segundo numero
	li $v0, 4 #Codigo para print
	la $a0, msg2#argumento do print
	syscall # solicita que o kernel execute
	
	li $v0, 5 #realiza leitura
	syscall
	
	move $t1, $v0 #mover o valor de V0 para o t1
	
	
	mult $t0, $t1
	
	mflo $s3
	
	li $v0, 4 #Codigo para print
	la $a0, resultado #argumento do print
	syscall
	
	li $v0,1
	move $a0, $s3 #mover o valor de s3 para o a0
	syscall
