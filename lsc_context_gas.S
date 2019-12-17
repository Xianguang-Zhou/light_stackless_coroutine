/*
 * Copyright (c) 2018, 2019, Xianguang Zhou <xianguang.zhou@outlook.com>. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#if defined(__x86_64__)
	.globl	lsc_start_context
	.type	lsc_start_context, @function
lsc_start_context:
	popq	(%rsi)
	movq	%rbp, 8(%rsi)
	movq	%rsp, 16(%rsi)
	pushq	(%rdi)
	ret
#elif defined(__i386__)
	.globl	lsc_start_context
	.type	lsc_start_context, @function
lsc_start_context:
	movl	8(%esp), %eax
	popl	(%eax)
	movl	%ebp, 4(%eax)
	movl	%esp, 8(%eax)
	movl	(%esp), %eax
	movl	%eax, 4(%esp)
	pushl	(%eax)
	ret
#endif

#if defined(__x86_64__)
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
#elif defined(__i386__)
	.globl	lsc_swap_context
	.type	lsc_swap_context, @function
lsc_swap_context:
	movl	8(%esp), %eax
	popl	(%eax)
	movl	%ebp, 4(%eax)
	movl	%esp, 8(%eax)
	movl	(%esp), %eax
	movl	4(%eax), %ebp
	movl	8(%eax), %esp
	pushl	(%eax)
	ret
#endif
