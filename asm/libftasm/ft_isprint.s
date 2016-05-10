# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isprint.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <bciss@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/11 01:14:55 by bciss             #+#    #+#              #
#    Updated: 2015/06/11 01:15:00 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


global	_ft_isprint

section .text

_ft_isprint:
	cmp rdi, 32
	jl	false
	cmp rdi, 126
	jg	false

true:
	mov rax, 1
	ret

false:
	mov rax, 0
	ret
