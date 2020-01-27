# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eviana <eviana@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/21 15:01:58 by eviana            #+#    #+#              #
#    Updated: 2020/01/14 15:00:06 by mjouffro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= ../corewar
DEBUG		= 0
SRC_PATH	= srcs/
OBJ_PATH	= objs/
H_PATH		= includes/
LIB			= libft/libft.a
FLAGS		= -Wall -Werror -Wextra -g
DEBUG_FLAG 	= -g3 -fsanitize=address

ifeq ($(DEBUG), 0)
	CC = gcc $(FLAGS)
else
	CC = gcc $(FLAGS) $(DEBUG_FLAG)
endif

SRC_SUFFIX	= .c
H_SUFFIX	= .h
COMMON		= main \
			init \
			parse_option \
			parse_player \
			load_process \
			exec_virtual_machine \
			process_review \
			life_check \
			print_machine \
			print_pannel \
			tools \
			tools2 \
			error \
			op \
			operations1 \
			operations2 \
			operations3 \
			operations4 \
			params \
			code_check \
			debug
INCLUDES	= virtual_machine \
			op \
			libft \
			get_next_line \
			ft_printf \

SRC_FILES = $(addsuffix $(SRC_SUFFIX),$(COMMON))
OBJ_FILES = $(SRC_FILES:.c=.o)
H_FILES   = $(addsuffix $(H_SUFFIX), $(INCLUDES))
SRC		= $(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ		= $(addprefix $(OBJ_PATH),$(OBJ_FILES))
HEADERS = $(addprefix $(H_PATH), $(H_FILES))

#color
YELLOW		= "\\033[33m"
BLUE		= "\\033[34m"
RED			= "\\033[31m"
WHITE		= "\\033[0m"
CYAN		= "\\033[36m"
GREEN		= "\\033[32m"
BOLD		= "\\033[1m"
PINK		= "\\033[95m"

#command
EOLCLR		= "\\033[0K"
#unicode
CHECK		= "\\xE2\\x9C\\x94"
OK			= " $(CYAN)$(CHECK)$(WHITE)"

all : $(NAME)

$(NAME) : $(OBJ) $(HEADERS)
	@make -s -C libft
	@printf "\r$(EOLCLR)[$(NAME)] >>>>>>>>>>\t$(YELLOW)$(BOLD)"\
	"building corewar"$(OK)'\n'
	@ $(CC) -I $(H_PATH) $(OBJ) $(LIB) -o $@
	@printf "\r$(EOLCLR)[$(NAME)] >>>>>>>>>>\t$(GREEN)$(BOLD)"\
	"build successful"$(OK)'\n'

$(OBJ) : | $(OBJ_PATH)

$(OBJ_PATH) : 
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "\r$(EOLCLR)[$(NAME)] compiling\t$(BOLD)$(YELLOW)$<$(WHITE)"
	@$(CC) -I $(H_PATH) -o $@ -c $<
	@printf '\t'$(OK)

clean :
	@make clean -C libft
	@printf "[$(NAME)] removing\t$(PINK)all obj files$(WHITE)"
	@rm -rf $(OBJ_PATH)
	@printf '\t'$(OK)'\n'

fclean : clean
	@make fclean -C libft
	@printf "[$(NAME)] erasing\t$(PINK)$(NAME)$(WHITE)"
	@rm -f $(NAME)
	@rm -rf corewar.dSYM
	@printf '\t'$(OK)'\n'

re : fclean all

norm :
	@norminette $(SRC_PATH) $(H_PATH)

.PHONY: all clean fclean re norm
