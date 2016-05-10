# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_cat.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/21 17:50:38 by bciss             #+#    #+#              #
#    Updated: 2015/05/21 17:50:45 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_cat

extern _ft_strlen

section .data

buffer times 255 db 0
bufsize equ $ - buffer

section .text

_ft_cat:
		push rbp
		mov rbp, rsp

read:
		mov rax, 0x2000003
		push rdi
		lea rsi, [rel buffer]
		mov rdx, bufsize
		syscall
		jc err
		cmp rax, 0
		je end
		mov rdi, 1
		mov rdx, rax
		mov rax, 0x2000004
		syscall
		jc err
		pop rdi
		jmp read

err:
		pop rdi
		mov rax, 1

end:
		mov rsp, rbp
		pop rbp
		ret
