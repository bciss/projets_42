# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strncat.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <bciss@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/11 00:44:53 by bciss             #+#    #+#              #
#    Updated: 2015/06/11 00:44:58 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


global _ft_strncat

section .text

_ft_strncat:
	push rdi

loop:
	cmp byte[rdi], 0x0
	je	copy
	inc rdi
	jmp loop

copy:
	cmp	byte[rsi], 0x0
	je end
	cmp rdx, 0
	je end
	movsb
	dec rdx
	jmp	copy

end:
	pop rax
	ret
