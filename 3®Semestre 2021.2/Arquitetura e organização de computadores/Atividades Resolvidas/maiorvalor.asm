saida: #zera novamente o valor para se poder andar pelo vetor
	move $t0, $zero

maiorvalor: #para definir o maior número no array
	beq $t0, $t2, exit
	lw $t4, array($t0)
	bgt $s1, $t4, maior
	move $s1, $t4
	addi $t0, St0, 4
	j maiorvalor
	maior:
		addi $t0, $t0, 4
		j maiorvalor