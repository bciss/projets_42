# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strdup.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/21 17:54:37 by bciss             #+#    #+#              #
#    Updated: 2015/06/10 23:16:01 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_strdup

extern _ft_strlen
extern _malloc
extern _ft_memcpy

segment .text

_ft_strdup:
		push rbp
		lea  rbp, [rsp]
		call _ft_strlen
		push rdi
		push rax
		mov  rdi, rax
		call _malloc
		cmp  rax, 0
		je   nop
		mov  rdi, rax
		pop  rdx
		pop  rsi
		call _ft_memcpy
		leave
		ret
nop:
		mov  rax, 0
		leave
		ret
