# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalpha.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/21 17:53:02 by bciss             #+#    #+#              #
#    Updated: 2015/05/21 17:53:05 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isalpha

section .text

_ft_isalpha:
		cmp rdi, 'A'
		jl false
		cmp rdi, 'z'
		jg false
		cmp rdi, 'Z'
		jle true
		cmp rdi, 'a'
		jge true

false:
		mov rax, 0
		ret
true:
		mov rax, 1
		ret
