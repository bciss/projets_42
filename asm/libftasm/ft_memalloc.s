# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memalloc.s                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <bciss@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/11 00:51:11 by bciss             #+#    #+#              #
#    Updated: 2015/06/11 00:51:14 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


global _ft_memalloc
extern _malloc
extern _ft_bzero

section .text

_ft_memalloc:
	push rbp
	lea rbp, [rsp]
	cmp rdi, 0
	je end
	lea r14, [rdi]

	call _malloc
	cmp rax, 0
	je end

	lea rdi, [rax]
	lea rsi, [r14]
	call _ft_bzero
	lea rax, [rdi]
	leave
	ret

end:
	mov rax, -1
	mov rdi, r14
	leave
	ret


