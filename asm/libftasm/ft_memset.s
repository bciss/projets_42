# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memset.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/21 17:54:11 by bciss             #+#    #+#              #
#    Updated: 2015/05/21 17:54:12 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_memset

segment .text

_ft_memset:
		push rdi
		mov rcx, rdx
		mov rax, rsi
		cld
		rep stosb
		pop rax
		ret
