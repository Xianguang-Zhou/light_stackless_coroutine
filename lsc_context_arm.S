/* vi: set ft=arm: */
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

#if defined(__arm__)

	.global	lsc_start_context
	.type	lsc_start_context, %function
lsc_start_context:
	str		lr, [r1]
	str		fp, [r1, #4]
	str		sp, [r1, #8]
	ldr		lr, [r0]
	bx		lr

	.global	lsc_swap_context
	.type	lsc_swap_context, %function
lsc_swap_context:
	str		lr, [r1]
	str		fp, [r1, #4]
	str		sp, [r1, #8]
	ldr		fp, [r0, #4]
	ldr		sp, [r0, #8]
	ldr		lr, [r0]
	bx		lr

#endif
