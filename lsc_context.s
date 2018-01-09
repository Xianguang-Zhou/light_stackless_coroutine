	.globl	lsc_start_context
	.type	lsc_start_context, @function
lsc_start_context:
	movq	%rbp, 8(%rsi)
	movq	%rsp, 16(%rsi)
	popq	(%rsi)
	call	(%rdi)

	.globl	lsc_swap_context
	.type	lsc_swap_context, @function
lsc_swap_context:
	movq	%rbp, 8(%rsi)
	movq	%rsp, 16(%rsi)
	popq	(%rsi)
	movq	8(%rdi), %rbp
	movq	16(%rdi), %rsp
	movq	%rdi, %rax
	call	(%rdi)

