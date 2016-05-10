# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <bciss@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/11 00:22:06 by bciss             #+#    #+#              #
#    Updated: 2015/06/11 00:22:11 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


global _ft_isupper

section .text

_ft_isupper:
	cmp	rdi, 65
	jl	false
	cmp rdi, 90
	jg	false

true:
	mov	rax, 1
	ret

false:
	mov	rax, 0
	ret
