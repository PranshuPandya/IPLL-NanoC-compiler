	.file	"input.c"

#	function variables and temp are allocated on the stack:

#	printStr
#	ch: -8
#	printInt
#	n: -4
#	readInt
#	eP: -8
#	main
#	i: -4
#	t0: -8
#	t1: -12
#	t2: -16
#	t3: -24
#	t4: -28
#	t5: -32
#	t6: -36
#	t7: -40

	.section	.rodata
.LC0:
	.string	"\n"
# main : 
	.text
	.globl  main
	.type   main, @function
main:
.LFB0:
	.cfi_startproc
	pushq   %rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq    %rsp, %rbp
	.cfi_def_cfa_register 6
	subq    $40, %rsp
# 		t0 = 0
	movl    $0, -8(%rbp)
# 		i = t0
	movl    -8(%rbp), %eax
	movl    %eax, -4(%rbp)
# 		t1 = 5
.L3:
	movl    $5, -12(%rbp)
# 		if i < t1 goto 6
	movl    -12(%rbp), %eax
	cmpl    %eax, -4(%rbp)
	jl      .L1
# 		goto 15
	jmp     .L2
# 		param i
.L1:
# 		t2 = call printInt, 1
	movl    -4(%rbp), %edi
	call    printInt
	movl    %eax, -16(%rbp)
# 		t3 = "\n"
	movq    $.LC0, -24(%rbp)
# 		param t3
# 		t4 = call printStr, 1
	movq    -24(%rbp), %rdi
	call    printStr
	movl    %eax, -28(%rbp)
# 		t5 = 1
	movl    $1, -32(%rbp)
# 		t6 = i + t5
	movl    -4(%rbp), %eax
	addl    -32(%rbp), %eax
	movl    %eax, -36(%rbp)
# 		i = t6
	movl    -36(%rbp), %eax
	movl    %eax, -4(%rbp)
# 		goto 3
	jmp     .L3
# 		t7 = 0
.L2:
	movl    $0, -40(%rbp)
# 		return t7
	movl    -40(%rbp), %eax
	jmp     .LFE0
# main : 
.LFE0:
	movq    %rbp, %rsp
	popq    %rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
	.size   main, .-main
