#include<sys/regdef.h>

	.abicalls
	.align 2
	.text
	.extern merge
	.globl merge_sort
	.ent merge_sort

merge_sort:
	
	sll a1,a1,2 # escalo largo en bytes

loop:
		
	.frame fp,32,ra
#	.set noreorder
#	.cpload t9	#si descomento esto tira segmentation fault
#	.set reorder

	#creo stackframe: 4(SRA) + 4(ABA)

	subu sp,sp,32
	.cprestore 24
	sw gp,24(sp)
	sw fp,20(sp)
	sw ra,16(sp)
	move fp,sp
	
	#caso base

	beq a1,4,return
	
	srl t0,a1,3 # largo/8
	sll t0,t0,2 # largo*4
	sub t1,a1,t0 # largo mitad superior
	add t2,a0,t0 # direccion mitad del arreglo

	#persisto en ABA caller

	sw a0,32(fp) #direccion de comienzo
	sw t2,36(fp) #direccion media
	sw t0,40(fp) #largo inferior
	sw t1,44(fp) #largo superior

	#llamada recursiva subarreglo inferior
	add a1,zero,t0
	jal loop

	#llamada recursiva subarreglo superior
	lw a0,36(fp)
	lw a1,44(fp)
	jal loop

	#merge

	lw a0,32(fp)
	lw a1,36(fp)
	lw a2,40(fp)
	lw a3,44(fp)

	jal merge

return:
	lw gp,24(fp)
	lw ra,16(fp)
	lw fp,20(fp)
	add sp,sp,32
	jr ra
	
	.end merge_sort
