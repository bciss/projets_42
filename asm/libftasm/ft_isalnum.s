# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalnum.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/21 17:52:52 by bciss             #+#    #+#              #
#    Updated: 2015/05/21 17:52:55 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isalnum

section .text

_ft_isalnum:
		cmp rdi, '0'
		jl no
		cmp rdi, '9'
		jle yes
		cmp rdi, 'A'
		jl no
		cmp rdi, 'Z'
		jle yes

min:
		cmp rdi, 'a'
		jl no
		cmp rdi, 'z'
		jle yes

no:
		mov rax, 0
		ret

yes:
		mov rax, 1
		ret
