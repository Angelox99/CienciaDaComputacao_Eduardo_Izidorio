# Programa: Calculadora
# Descrição primaria: Projecto para UC Microprocessadores e Arquitecturas
#
# Autor: Tiago Conceição n. 11903
# Data: 20-05-2012
#
# Descrição Funcional: Este programa executa a pedido do utilizador 6 funções
#
# Operadores:
# + = Adição
# - = Subtracção
# * = Multiplicação
# / = Divisão
# ^ = Potência
# < = Devolve o número menor
# > = Devolve o número maior
#
#
# $s0 = Guarda o primeiro número	(int)
# $s1 = Guarda o operador	 		(char)
# $s2 = Guarda o segundo número		(int)
# $s3 = Resultado da conta			(int)
#

.data
	szLogo: 			.asciiz "--------------------------------------------------------------------------\nPrograma:\tCalculadora\nDescrição:\tProjecto para UC Microprocessadores e Arquitecturas\nAutor:\tTiago Conceição nº 11903\n--------------------------------------------------------------------------\n"
	szOperadores:		.asciiz "\nOperadores:\n+ = Adição\n- = Subtracção\n* = Multiplicação\n/ = Divisão\n^ = Potência\n< = Devolve o número menor\n> = Devolve o número maior\n-----\nc = Limpa a conta\nESC = Limpa a conta\nq = Sai do programa\n? = Ajuda do programa\n"
	szOperadorInvalido: .asciiz "O operador é invalido! Repita a operação\n"
	szDigiteNumero:		.asciiz "\nDigite um número: "
	szDigiteOperador:	.asciiz "Operador (+, -, *, /, ^, <, >, c, q, ?): "
	szSetaD:			.asciiz "-> "
	szEspaco:			.asciiz " "
	szEnter:			.asciiz "\n"
	szIgual:			.asciiz "="
	szFim:				.asciiz "\n\n############################################\n\tObrigado por usar a Calculadora\n\tFim do programa Calculadora!\n############################################\n"
	
.text

main:
	jal fxAjuda
	b start
	
start:
	addi $s0, $0, 0	# Inicia o $s0 com o valor 0
	
	jal fxDigiteNumero
	move $s0, $s3	# move valor lido para t0
	
	b calc
	
calc:
	jal fxDigiteOperador
	
	# Limpa a conta
	addi $t0, $0, 0x63			# c
	beq $s1, $t0, limpaConta	# if ==
	
	# Limpa a conta
	addi $t0, $0, 0x1b			# ESC
	beq $s1, $t0, limpaConta	# if ==
	
	# Sai do programa
	addi $t0, $0, 0x71			# q
	beq $s1, $t0, exit			# if ==
	
	# Ajuda do programa
	addi $t0, $0, 0x3f			# ?
	beq $s1, $t0, ajuda			# if ==
	
	jal fxDigiteNumero
	move $s2, $s3	
	
	addi $t0, $0, 0x2b			# +
	beq $s1, $t0, somaC			# if ==
	
	addi $t0, $0, 0x2d			# -
	beq $s1, $t0, subC			# if ==
	
	addi $t0, $0, 0x2a			# *
	beq $s1, $t0, multiC		# if ==
	
	addi $t0, $0, 0x2f			# /
	beq $s1, $t0, divC			# if ==
	
	addi $t0, $0, 0x5e			# ^
	beq $s1, $t0, powC			# if ==
	
	addi $t0, $0, 0x3c			# <
	beq $s1, $t0, menorC		# if ==
	
	addi $t0, $0, 0x3e			# >
	beq $s1, $t0, maiorC		# if ==
	
	jal fxLabelOperadorInvalido
	
	b calc
	
#############################################################################
#						Funções da calculadora								#
#############################################################################
# Soma o valor anterior com o novo
somaC:
	add $s3, $s0, $s2
	b resultado

# Subtrai o valor anterior com o novo
subC:
	sub $s3, $s0, $s2
	b resultado

# Multiplica o valor anterior com o novo
multiC:
	mul $s3, $s0, $s2
	b resultado

# Divide o valor anterior com o novo
divC:
	beq	$s3, 0, calc	# Divisão por 0 = Erro, Previne o fim do programa
	div $s3, $s0, $s2
	b resultado
	
# Potência o valor anterior com o novo
powC:
	addi $s5, $0, 1	# Contagem do loop, começa em 1
	move $s3, $s0	# Move o primeiro numero para o resultado
	b powLoop	

# Loop da potencia
powLoop:
	add $s5, $s5, 1			# Incrementa um loop
	
	mul $s3, $s3, $s0		# Multiplica o resultado anterior pelo primeiro numero
	bge	$s5, $s2, resultado # Se o $s5 for maior ou igual ao expoente mostra o resultado e sai
	b powLoop				# Se não continua a fazer a multiplicação
	
# Devolve o numero menor
menorC:
	ble	$s0, $s2, menorOk
	move $s3, $s2
	b resultado

# Se o numero for menor:
menorOk:
	move $s3, $s0
	b resultado
	
# Devolve o número maior
maiorC:
	bge	$s0, $s2, maiorOk
	move $s3, $s2
	b resultado

# Se o número for maior:
maiorOk:
	move $s3, $s0
	b resultado

# Renicia a calculadora, limpando o resultado
limpaConta:
	b start

# Mostra o resultado da ultima conta
resultado:
	jal fxLabelSetaD		# ->
	jal fxLabelCNumero1 	# Numero 1
	jal fxLabelEspaco	
	jal fxLabelCOperador	# Operador (+, -, /, *, ^, <, >)
	jal fxLabelEspaco
	jal fxLabelCNumero2		# Numero 2
	jal fxLabelEspaco
	jal fxLabelIgual		# =
	jal fxLabelEspaco
	jal fxLabelCResultado	# Resultado
	jal fxLabelEnter
	
	move $s0, $s3			# Copia o resultado para $s0
	b calc					# Volta para a calculadora

# Mostra a ajuda
ajuda:
	jal fxLabelEnter
	jal fxLabelEnter
	
	jal fxAjuda
	
	jal fxLabelEnter
	jal fxLabelEnter
	
	b calc
	
# Sai do programa
exit:
	# Fim do programa
	la $a0, szFim
	li $v0, 4
	syscall
	
	li $v0, 10		#10 = exit
	syscall	

#############################################################################
#								Funções										#
#############################################################################
# Pede ao utilizador para digitar um numero e guarda o numero no s3
fxDigiteNumero:
	la $a0,szDigiteNumero
	li $v0, 4		#parametro de escrita string
	syscall 
	
	# Le numero
	li $v0, 5		#parametro de leitura int
	syscall	
	move $s3, $v0	# move valor lido para s3
	
	jr $ra			# Volta a execução
	
# Pede ao utilizador para digitar o operador e guarda no s1
fxDigiteOperador:
	la $a0, szDigiteOperador
	li $v0, 4			#parametro de escrita string
	syscall 
	
	li $v0, 12			#parametro de leitura char
	#la $a0, operador
	syscall 
	move $s1, $v0
	
	jr $ra
	
#############################################################################
#							Mensagens de texto 								#
#############################################################################
fxLabelOperadorInvalido:
	# O operador é invalido, mostra mensagem e volta ao inicio do calc
	la $a0, szOperadorInvalido
	li $v0, 4			#parametro de escrita string
	syscall 
	
	jr $ra
	
fxLabelCNumero1:
	move $a0, $s0
	li $v0, 1			#parametro de escrita int
	syscall 
	
	jr $ra
	
fxLabelCOperador:
	# Operador
	move $a0, $s1
	li $v0, 11			#parametro de escrita char
	syscall 
	
	jr $ra
	
fxLabelCNumero2:
	move $a0, $s2
	li $v0, 1			#parametro de escrita int
	syscall 
	
	jr $ra
	
fxLabelCResultado:
	move $a0, $s3
	li $v0, 1			#parametro de escrita int
	syscall 
	
	jr $ra
	
fxLabelSetaD:
	la $a0, szSetaD
	li $v0, 4			#parametro de escrita string
	syscall 
	
	jr $ra
	
fxLabelEspaco:
	la $a0, szEspaco
	li $v0, 4			#parametro de escrita string
	syscall 
	
	jr $ra
	
fxLabelIgual:
	la $a0, szIgual
	li $v0, 4			#parametro de escrita string
	syscall 
	
	jr $ra
	
fxLabelEnter:
	la $a0, szEnter
	li $v0, 4			#parametro de escrita string
	syscall 
	
	jr $ra

fxAjuda:
	la $a0, szLogo 		# carrega para a0 o endereço de variavel string 
	li $v0, 4 			#parametro de escrita string	
	syscall
	
	la $a0, szOperadores	# carrega para a0 o endereço de variavel string 
	li $v0, 4 			#parametro de escrita string	
	syscall
	
	jr $ra