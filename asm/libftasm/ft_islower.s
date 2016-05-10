# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_islower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <bciss@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/11 00:26:55 by bciss             #+#    #+#              #
#    Updated: 2015/06/11 00:26:58 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


global	_ft_islower

section	.text

_ft_islower:
	cmp	rdi, 97
	jl	false
	cmp	rdi, 122
	jg	false

true:
	mov rax, 1
	ret

false:
	mov	rax, 0
	ret
