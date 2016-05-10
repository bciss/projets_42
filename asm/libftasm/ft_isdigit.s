# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isdigit.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/21 17:53:38 by bciss             #+#    #+#              #
#    Updated: 2015/05/21 17:53:41 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_isdigit

segment .text

_ft_isdigit:
		cmp rdi, '0'
		jl false
		cmp rdi, '9'
		jg false
		jmp true


false:
		mov rax, 0
		ret
true:
		mov rax, 1
		ret
