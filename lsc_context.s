/*
 * Copyright (c) 2018, Xianguang Zhou <xianguang.zhou@outlook.com>. All rights reserved.
 * 
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

	.globl	lsc_start_context
	.type	lsc_start_context, @function
lsc_start_context:
	popq	(%rsi)
	movq	%rbp, 8(%rsi)
	movq	%rsp, 16(%rsi)
	pushq	(%rdi)
	ret

	.globl	lsc_swap_context
	.type	lsc_swap_context, @function
lsc_swap_context:
	popq	(%rsi)
	movq	%rbp, 8(%rsi)
	movq	%rsp, 16(%rsi)
	movq	8(%rdi), %rbp
	movq	16(%rdi), %rsp
	movq	%rdi, %rax
	pushq	(%rdi)
	ret

