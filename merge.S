#include<sys/regdef.h>

	.abicalls
	.align 2
	.text
	.extern mymalloc
	.extern myfree
	.globl merge
	.ent merge
	
merge:
	.frame fp,40,ra
	.set noreorder
	.cpload t9
	.set reorder

	#creo stackframe: 4(SRA)+2(LTA)+4(ABA)

	subu sp,sp,40
	.cprestore 24
	sw gp,24(sp)
	sw fp,28(sp)
	sw ra,32(sp)
	move fp,sp
	
	#persisto argumentos

	sw a0,40(fp) # direccion subarreglo 1
	sw a1,44(fp) # direccion subarreglo 2
	sw a2,48(fp) # largo subarreglo 1
	sw a3,52(fp) # largo subarreglo 2

	#creo arreglo auxiliar

	add a0,a2,a3 # largo total
	sw a0,20(fp)
	jal mymalloc
	add t0,zero,v0 # direccion arreglo auxiliar
	sw t0,16(fp)

	#recupero datos

	lw t1,40(fp) # direccion subarreglo 1
	lw t2,44(fp) # direccion subarreglo 2
	lw t3,48(fp) # largo subarreglo 1
	lw t4,52(fp) # largo subarreglo 2

loop:

	beq t3,0,extend_right
	beq t4,0,extend_left

	lw t5,0(t1) #elemento subarreglo 1
	lw t6,0(t2) #elemento subarreglo 2
	
	ble t5,t6,add_element_left
	j add_element_right

add_element_left:

	sw t5,0(t0) # agrego elemento en el arreglo auxiliar
	add t1,t1,4 # sig elemeto subarreglo 1
	add t0,t0,4 # sig posicion arreglo auxiliar
	sub t3,t3,4 # -1 elemento subarreglo 1
	j loop

add_element_right:

	sw t6,0(t0)
	add t2,t2,4
	add t0,t0,4
	sub t4,t4,4
	j loop

extend_left:

	beq t3,0,overwrite
	lw t5,0(t1)
	sw t5,0(t0)
	add t1,t1,4
	add t0,t0,4
	sub t3,t3,4
	j extend_left

extend_right:
	
	beq t4,0,overwrite
	lw t6,0(t2)
	sw t6,0(t0)
	add t2,t2,4
	add t0,t0,4
	sub t4,t4,4
	j extend_right

overwrite:

	lw t1,40(fp) # inicio del arreglo original
	lw t2,16(fp) # inicio del arreglo auxiliar
	
overwriting:
	
	beq t2,t0,return # t0: direccion final+1 del arreglo auxiliar
	lw t3,0(t2)
	sw t3,0(t1)
	add t1,t1,4
	add t2,t2,4
	j overwriting

return:

	lw a0,16(fp)
	jal myfree
	
	lw gp,24(fp)
	lw ra,32(fp)
	lw fp,28(fp)
	add sp,sp,40
	jr ra

	.end merge
