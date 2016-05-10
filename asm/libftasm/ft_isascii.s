# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isascii.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/21 17:53:28 by bciss             #+#    #+#              #
#    Updated: 2015/05/21 17:53:30 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isascii

section .text

_ft_isascii:
		mov rax, 1
		cmp rdi, 0
		jl no
		cmp rdi, 127
		jle yes

no:
		mov rax, 0
		ret

yes:
		mov rax, 1
		ret
