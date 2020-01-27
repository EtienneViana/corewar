# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 11:34:42 by mjouffro          #+#    #+#              #
#    Updated: 2020/01/22 15:42:15 by mjouffro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable
NAME	=	../asm

# Compilation
CC			=	@cc -g #-fsanitize=address
CFLAGS		=	-O3 -Wall -Wextra -Werror
LIBFLAGS	=	-Iincludes

# Files && Objs

SRC_PATH	= srcs

OBJ_PATH	= objs

INC_PATH	= includes
INCLUDES    = /asm.h\
			  /op.h

LIB			= ./libft/
LDFLAGS		= -Llibft
LDLIBS		= -lft

SRC_NAME 	=	main.c 					\
				launcher.c 				\
				process_head.c			\
				magic_header.c			\
				tokens.c				\
				labels.c 				\
				errors.c				\
				operations.c			\
				check_operations.c 		\
				check_types.c 			\
				check_labels.c			\
				free.c					\
				free1.c					\
				size.c					\
				write_bytecode.c 		\
				conversions.c			\
				argument_type_code.c	\
				utils.c					\
				utils2.c				\
				utils3.c				\
				init.c					\


OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

HEADERS = $(addprefix $(INC_PATH), $(INCLUDES))
# **************************************************************************** #

# SPECIAL CHARS

LOG_CLEAR		= \033[2K
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_UNDERLINE	= \033[4m
LOG_BLINKING	= \033[5m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m
LOG_PINK		= \033[95m

EOLCLR		= \033[0K
CHECK		= "\\xE2\\x9C\\x94"
OK			= " $(LOG_CYAN)$(CHECK)$(LOG_NOCOLOR)"

# Protect

.PHONY:	asm all clean fclean re

# **************************************************************************** #

# RULES

# Main rules
all				: $(OBJ_PATH) $(NAME)

re				: 	fclean all

# Compilation rules

$(OBJ_PATH)		:
					@mkdir -p $(OBJ_PATH)

$(NAME)			:	$(OBJ) $(HEADERS)
					@make -C $(LIB)
					@printf "\r$(LOG_NOCOLOR)[$(NAME)] >>>>>>>>>>>>>>\t$(LOG_YELLOW)"
					@printf "$(LOG_BOLD)building asm\t"$(OK)'\n'
					@$(CC) $(CFLAGS) $(LIBFLAGS) -g -o $@ $(OBJ) $(LIB)libft.a
					@printf "\r$(LOG_NOCOLOR)[$(NAME)] >>>>>>>>>>>>>>\t$(LOG_GREEN)$(LOG_BOLD)"
					@printf "build successful"$(OK)'\n'

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
					@printf "\r$(LOG_NOCOLOR)$(EOLCLR)[$(NAME)] compiling\t$(LOG_BOLD)$(LOG_YELLOW)$<"
					$(CC) $(CFLAGS) $(LIBFLAGS) -c $< -o $@
					@printf '\t'$(OK)

# Clean rules
clean			:
					@cd libft && $(MAKE) clean
					@printf "[$(NAME)]     removing\t$(LOG_PINK)all obj files"
					@rm -rf $(OBJ_PATH)
					@printf '\t'$(OK)'\n'

fclean			: 	clean
					@cd libft && $(MAKE) fclean
					@printf "[$(NAME)]     erasing\t$(LOG_PINK)$(NAME)"
					@rm -f $(NAME)
					@printf '\t\t'$(OK)'\n'
norme:
					@norminette $(SRC)
					@norminette $(INC_PATH)/
# **************************************************************************** #
