.data
	msg1: .asciiz "Forneça um número positivo "
	msgPar: .asciiz "O número é Par"
	msgImpar: .asciiz "O número é Impar"
	
.text

	la $a0, msg1  #ler a variável msg1
	jal imprimeString  #Imprime o valor de $
	jal lerInteiro  #Ler o número inteiro
	
	move $a0, $v0   #Move o valor de $v0 para $a0
	jal ehImpar   #Chama a função ehImpar
	beq $v0, $zero, imprimePar   #Se o valor que tiver
	la $a0, msgImpar   #Se o valor que tiver em $v0
	jal imprimeString #Função para realizar impressão
	jal encerraPrograma   #Função para encerrar programa
	
	imprimePar:  #Rótulo (Label)
	la $a0, msgPar  #Guarda em $a0 a variável msgPar
	jal imprimeString   #Pede para imprimir (função
	jal encerraPrograma   #Função para encerrar programa
	
	
	ehImpar:   #Rótulo
	li $t0, 2   #Coloca o valor 2 em $t0
	div $a0, $t0   #Divide o que estar em $a0 por 2
	mfhi $v0   #Move o valor de hi para $v0
	jr $ra   #Retorna Função
	
	encerraPrograma:   #Rótulo para encerra programa
	li $v0, 10   #Encerra programa
	syscall
	
	imprimeString:   #Função que recebe uma String
	li $v0,4   #Imprime String
	syscall
	jr $ra   #retorna a função
	
	lerInteiro:   #Função para ler inteiro
	li $v0, 5   #Leitura de inteiro
	syscall
	jr $ra   #Retorna a função