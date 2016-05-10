# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_bzero.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/21 17:50:06 by bciss             #+#    #+#              #
#    Updated: 2015/05/21 23:20:45 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_bzero

section .text

_ft_bzero:
		cmp rdi, 0
		je end
		mov rbx, rdi
		mov rax, rsi

loop:
		cmp rax, 0
		jle end
		mov byte[rbx], 0
		inc rbx
		dec rax
		jmp loop

end:
ret
