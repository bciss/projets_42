# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_toupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/21 17:57:22 by bciss             #+#    #+#              #
#    Updated: 2015/05/21 17:57:24 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_toupper

section .text

_ft_toupper:
		mov rax, rdi
		cmp rax, 97
		jl end
		cmp rax, 122
		jg end
		sub rax, 32

end:
		ret
