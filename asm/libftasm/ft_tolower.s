# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_tolower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bciss <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/21 17:57:03 by bciss             #+#    #+#              #
#    Updated: 2015/05/21 17:57:06 by bciss            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

global _ft_tolower

section .text

_ft_tolower:
		mov rax, rdi
		cmp rax, 65
		jl  end
		cmp rax, 90
		jg  end
		add rax, 32

end:
		ret
