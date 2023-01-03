#-----------------------------------------------------#
# Discente: Eduardo Henrique de Almeida Izidorio 
# Matricula: 2020000315
# Disciplina: Programacao em Baixo Nivel
# Avaliacao - Programa Calculadora
#-----------------------------------------------------#
.data

	continue: .asciiz "\nPressione <|ENTER|> para continuar\n"
	title:		.asciiz "\nEscolha a opção\n"
	Somar:	.asciiz "|1| {Somar}\n"
	Subtrair:	.asciiz "|2| {Subtrair}\n"
	Multiplicar:	.asciiz "|3| {Multiplicar}\n"
	Dividir: 	.asciiz "|4| {Dividir}\n"
	Potenciar:	.asciiz "|5| {Potencia}\n"
	RaizQuadrada:	.asciiz "|6| {Raiz Quadrada}\n"
	Tabuada:		.asciiz "|7| {Tabuada}\n"
	Sair:		.asciiz "|0| {Sair}\n"
	
	# É uma string para falar caso algum comando seja invalido.
	erro:	.asciiz "Opcao invalida!!\n"
	
	newline:	.asciiz "\n"		#Para pular uma linha

.text

.globl main		#Declara o rotulo listado como global para permitir referência de outros arquivos.

main:		#Rotulo da função
	#impressão do menu
	addi $v0, $zero, 4		#código da syscall (impressão de string)
	
	la $a0, title		#Indica o endereço do title.
	syscall
	
	la $a0, Somar		#Indica o endereço do Somar.
	syscall
	
	la $a0, Subtrair		#Indica o endereço do Subtrair.
	syscall
	
	la $a0, Multiplicar		#Indica o endereço do Multiplicar.
	syscall
	
	la $a0, Dividir			#Indica o endereço do Dividir.
	syscall
	
	la $a0, Potenciar		#Indica o endereço do Potenciar.
	syscall
	
	la $a0, RaizQuadrada		#Indica o endereço da RaizQuadrada..
	syscall
	
	la $a0, Tabuada		#Indica o endereço da Tabuada.
	syscall
	
	la $a0, Sair		#Indica o endereço do Sair.
	syscall
	
ler_op:		#Rotulo da função
	#código p/ ler inteiro
	addi $v0, $zero, 5
	syscall
	
	add $t9, $v0, $zero 	#armazenar operação
	
	beq $t9, $zero, quit #compara se t9 é igual a 0 e executa o quit.
	
	bltz $t9, invalid_op 	#Caso coloque número errado, mostra uma mensagem com erro.
	
	addi $t8, $zero, 11
	ble $t8, $t9, invalid_op   #operação maior que 10
	
ler_arg:		#Rotulo da função
	#leitura do primeiro argumento
	#código para ler inteiro
	addi $v0, $zero, 5
	syscall
	add $t0, $v0, $zero #armazenar primeio argumento
	
	#verificação se a opção é maior que 5
	#opções maiores que 5 só exigem 1 (um) argumento
	addi $t8, $zero, 5
	blt $t8, $t9, exe_op  
	
ler_arg2: 		#Rotulo da função
	#leitura do segundo argumento, se necessário
	addi $v0, $zero, 5 
	syscall
	
	j exe_op		#Jump para a função exe_op.

exe_op:		#Rotulo da função
	#preparação para chamada das funções do menu
	#argumentos dos procedimentos
	add $a1, $v0, $zero
	add $a0, $t0, $zero
	
	addi $t8, $zero, 1
	beq  $t8, $t9, exe_soma # se operação for 1, soma
	
	addi $t8, $zero, 2
	beq  $t8, $t9, exe_subtr #se operação for 2, subtração
	
	addi $t8, $zero,3
	beq $t8, $t9, exe_multi #se operação for 3, multiplica
	
	addi $t8, $zero,4
	beq $t8, $t9, exe_divi #se operação for 4, divide
	
	addi $t8, $zero, 5
	beq $t8, $t9, exe_expo #se operação for 5, potencia
 	
	addi $t8, $zero, 6
	beq  $t8, $t9, exe_raiz # se operação for 6, raiz
	
	addi $t8, $zero, 7
	beq  $t8, $t9, exe_tabuada # se operação for 7, tabuada

#SOMA		
exe_soma:		#Rotulo da função

	jal soma		#Chamar a função soma
	j Resultado		#Jump para a função Resultado.

soma: 		#Rotulo da função
	#soma dois valores
	add $v0, $a0, $a1		# soma de a0 + a1, resultado fica em v0.
	jr $ra		#Voltamos a instrunção anterior da chamada soma.
	
#SUBTRAÇÃO
exe_subtr:		#Rotulo da função
	
	jal subtr		#Chamada para a função subtr.
	j Resultado		#jump para a função Resultado.

subtr: 		#Rotulo da função
	#subtrai 2 valores
	sub $v0, $a0, $a1		#Subtração de a0 - a1, resultado fica em v0.

	jr $ra		#Voltamos a instrunção anterior da chamada subtr.

#MULTIPLICAÇÃO
exe_multi:		#Rotulo da função
	
	jal multi		#Chamada para a função multi.
	j Resultado		#jump para a função Resultado.

multi: 		#Rotulo da função
	#multiplica 2 valores de 16bits
	mult $a0, $a1
	mflo $v0		#move o valor do registrador lo para o registrador v0.

	jr $ra		#Voltamos a instrunção anterior da chamada multi.

#DIVISÃO
exe_divi:		#Rotulo da função
	
	jal divi		#Chamada para a função divi.
	j Resultado		#jump para a função Resultado.

divi: 		#Rotulo da função
	#divide 2 valores 
	div $a0, $a1		#Dividi a0 / a1.
	mflo $v0		#move o valor do registrador lo para o registrador v0.

	jr $ra		#Voltamos a instrunção anterior da chamada divi.

#POTENCIAÇÃO
exe_expo:		#Rotulo da função
	
	add $v0, $a0, $zero			#soma a0 + 0, e o resultado fica em v0.
	addi $v0, $zero, 1				#soma imediata 0 + 1 , e resultado fica em v0.
	addi $s0, $zero, 1				#soma imediata 0 + 1 , e resultado fica em s0.
	
	jal expo_for		#Chamada da função expo_for.
	j Resultado		#jump para a função Resultado.

expo_for:		#Rotulo da função
	
	ble $a1, $zero, expo 	#se a1 for menor ou igual a 0, executa o expo.
	mul $v0, $v0, $a0		#Multiplica v0 * a0, resultado fica em v0.
	sub $a1, $a1, $s0		#Subtrai a1 - s0, resultado fica em a1.

	j expo_for		#jump para a função expo_for.
expo:		#Rotulo da função
	jr $ra		#Voltamos a instrunção anterior da chamada expo_for.

#RAIZ QUADRADA
exe_raiz:		#Rotulo da função

	jal raiz		#Chamar a funcao raiz.
	j Resultado		#Jump para a função Resultado.

raiz:			#Rotulo da função
	li	$v0, 0			# x = 0

raiz_loop:		#Rotulo da função
	mul	$t0, $v0, $v0		# t0 = x*x
	bgt	$t0, $a0, raiz_end	# if (x*x > n) vai para raiz_end
	addi	$v0, $v0, 1		# x = x + 1
	j	raiz_loop		#Jump para açãuncao raiz_loop.
		
raiz_end:		#Rotulo da função
	addi	$v0, $v0, -1		# x = x - 1
	jr	$ra		#Voltamos a instrunção anterior da chamada raiz_end.

#TABUADA
exe_tabuada:		#Rotulo da função
	
	jal tabuada		#Chamar a funcao tabuada.
	j Continuar		#jump para a função Continuar.

tabuada:		#Rotulo da função
	move	$t0, $a0	# salva x em t0
	li	$t1, 1		# i = 1
	li 	$t2, 10		# maxValue = 10
	
	# imprime uma nova linha
	la	$a0, newline		#Indica o endereço da newline.
	li	$v0, 4		#Imprime a string.
	syscall

tabuada_loop:		#Rotulo da função
	
	bgt	$t1, $t2, tabuada_end	# se contador for maior que 10, vai para tabuada_end
	
	mul	$a0, $t0, $t1	# n = i * x
	addi	$t1, $t1, 1 	# i = i + 1
	
	li	$v0, 1		# imprime n
	syscall
	
	# imprime uma nova linha
	la	$a0, newline		#Indica o endereço da newline.
	li	$v0, 4		#Imprime a string.
	syscall
	
	j tabuada_loop	# jump para a função tabuada_loop.
	
tabuada_end:		#Rotulo da função
	jr	$ra		#Voltamos a instrunção anterior da chamada tabuada_end.
	
Resultado:		#Rotulo da função
	#impressão do resultado de uma função
	add $a0, $v0, $zero	#soma v0 + 0, e resultado fica em a0.
	addi $v0, $zero, 1		#soma imediata de 0 + 1, e resultado ficado em v0.
	syscall

Continuar:		#Rotulo da função
	#impressão para continuar uma função
	la $a0, continue		#Indica o endereço do continue.
	addi $v0, $zero, 4		#soma imediata de 0 + 4, e resultado fica em v0.
	syscall
	
	addi $v0, $zero, 12	#soma imediata de 0 + 12, e resultado fica em v0.
	syscall
	
	j main		#jump para a função main.

invalid_op:		#Rotulo da função
	#tratamento de opções inválidas
	la $a0, erro		#Indica o endereço do erro.
	addi $v0, $zero, 4		#soma imediata de 0 + 4, e resultado fica em v0.
	syscall
	
	j Continuar		#jump para a função Continuar.
		
quit:		#Rotulo da função
	#fim do programa
	addi $v0, $zero, 10	#soma imediata de 0 + 10, e resultado fica em v0.
	syscall
