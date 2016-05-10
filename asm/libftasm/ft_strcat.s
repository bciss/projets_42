# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcat.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/21 17:54:26 by bciss             #+#    #+#              #
#    Updated: 2015/05/21 17:54:28 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_strcat

extern _ft_strlen

section .text

_ft_strcat:
		call _ft_strlen
		mov rcx, 0

lp:
		cmp byte[rsi+rcx], 0x0
		jz end
		mov r8, [rsi+rcx]
		mov [rdi+rax], r8
		inc rcx
		inc rax
		jmp lp

end:
		mov r8, 0
		mov [rdi+rax], r8
		mov rax, rdi
		ret