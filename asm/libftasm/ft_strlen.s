# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/21 17:54:44 by bciss             #+#    #+#              #
#    Updated: 2015/05/21 17:54:46 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_strlen

segment .text

_ft_strlen:
		push rdi
		xor rcx, rcx
		not rcx
		xor al, al
		cld
		repne scasb
		not rcx
		dec rcx
		mov rax, rcx
		pop rdi
		ret
