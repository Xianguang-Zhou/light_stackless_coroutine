/* vi: set ft=arm64asm: */
/*
 * Copyright (c) 2020, Xianguang Zhou <xianguang.zhou@outlook.com>. All rights reserved.
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

#if defined(__aarch64__)

	.global	lsc_start_context
	.type	lsc_start_context, %function
lsc_start_context:
	str		x30, [x1]
	str		x29, [x1, #8]
	mov		x2, sp
	str		x2, [x1, #16]
	ldr		x30, [x0]
	ret

	.global	lsc_swap_context
	.type	lsc_swap_context, %function
lsc_swap_context:
	str		x30, [x1]
	str		x29, [x1, #8]
	mov		x2, sp
	str		x2, [x1, #16]
	ldr		x29, [x0, #8]
	ldr		x2, [x0, #16]
	mov		sp, x2
	ldr		x30, [x0]
	ret

#endif
