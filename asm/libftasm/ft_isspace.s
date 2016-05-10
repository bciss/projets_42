# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isspace.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <bciss@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/11 00:31:40 by bciss             #+#    #+#              #
#    Updated: 2015/06/11 00:31:45 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


global	_ft_isspace

section .text

_ft_isspace:
	cmp rdi, ' '
	je true
	cmp rdi, 9
	jl false
	cmp rdi, 13
	jg false

true:
	mov rax, 1
	ret

false:
	mov rax, 0
	ret
