# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrzepec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 18:48:32 by anrzepec          #+#    #+#              #
#    Updated: 2020/01/10 17:49:32 by mjouffro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: 			virtual_machine asm

virtual_machine:
			@make -C virtual_machine/

asm:	
			@make -C assembly/

clean_asm: 
			@make clean -C assembly/

clean_virtual_machine:
			@make clean -C virtual_machine/

fclean_asm:		clean_asm
			@make fclean -C assembly/
			
fclean_virtual_machine:	clean_virtual_machine
			@make fclean -C virtual_machine/

clean:			clean_asm clean_virtual_machine

fclean:			fclean_asm fclean_virtual_machine

re:			fclean all

.PHONY: 		re all fclean clean virtual_machine asm clean_asm clean_virtual_machine fclean_asm fclean_virtual_machine
