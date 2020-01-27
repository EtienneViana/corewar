# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjouffro <mjouffro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 19:43:10 by yabecret          #+#    #+#              #
#    Updated: 2020/01/14 14:44:53 by mjouffro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable
NAME 	= 	libft.a

# Compilation
CC		= 	@cc
CFLAGS	= 	-O3 -Wall -Wextra -Werror
CPPFLAGS = -Iincludes

# Files && Objs

SRC_PATH	= srcs

OBJ_PATH	= objs

PRINTF_PATH = ft_printf

CONV_PATH 	= conv

INC_PATH	= includes

LDFLAGS		= -Llibft
LDLIBS		= -lft

SRC_NAME 	=	ft_atoi_base.c										\
				ft_atoi.c											\
				ft_atoll.c											\
				ft_bzero.c											\
				ft_cntdigit.c										\
				ft_convert_base.c									\
				ft_isalnum.c										\
				ft_isalpha.c										\
				ft_isascii.c										\
				ft_isdigit.c										\
				ft_isprint.c										\
				ft_islower.c										\
				ft_isupper.c										\
				ft_isblank.c										\
				ft_isbase.c											\
				ft_iswhitespace.c									\
				ft_sqrt.c											\
				ft_recursive_factorial.c							\
				ft_itoa.c											\
				ft_itoa_base.c										\
				ft_lltoa_base.c										\
				ft_lstadd.c											\
				ft_lstdel.c											\
				ft_lstdelone.c										\
				ft_lstiter.c										\
				ft_lstmap.c											\
				ft_lstnew.c											\
				ft_memalloc.c										\
				ft_memccpy.c										\
				ft_memchr.c											\
				ft_memcmp.c											\
				ft_memcpy.c											\
				ft_memdel.c											\
				ft_memmove.c										\
				ft_memset.c											\
				ft_putchar_fd.c										\
				ft_putchar.c										\
				ft_putendl_fd.c										\
				ft_putendl.c										\
				ft_puthexa.c										\
				ft_putnbr_fd.c										\
				ft_putnbr.c											\
				ft_putstr_fd.c										\
				ft_putstr.c											\
				ft_putwchar_fd.c									\
				ft_putwchar.c										\
				ft_pow.c											\
				ft_strfind.c										\
				ft_sqrt.c											\
				ft_str_is_alpha.c									\
				ft_str_is_lowercase.c								\
				ft_str_is_uppercase.c								\
				ft_strcapitalize.c									\
				ft_strcat.c											\
				ft_strchr.c											\
				ft_strclr.c											\
				ft_strcmp.c											\
				ft_strcpy.c											\
				ft_strdel.c											\
				ft_strdup.c											\
				ft_strequ.c											\
				ft_striter.c										\
				ft_striteri.c										\
				ft_strjoin.c										\
				ft_strlcat.c										\
				ft_strlen.c											\
				ft_strmap.c											\
				ft_strmapi.c										\
				ft_strncat.c										\
				ft_strncmp.c										\
				ft_strncpy.c										\
				ft_strnequ.c										\
				ft_strnew.c											\
				ft_strnstr.c										\
				ft_strrchr.c										\
				ft_strsplit.c										\
				ft_strstr.c											\
				ft_strsub.c											\
				ft_strtrim.c										\
				ft_str_toupper.c									\
				ft_tolower.c										\
				ft_toupper.c										\
				ft_wchar.c											\
				maths.c												\
				palloc.c											\
				print_bits.c										\
				get_next_line.c										\
				$(PRINTF_PATH)/$(CONV_PATH)/c_arg.c					\
				$(PRINTF_PATH)/$(CONV_PATH)/dou_arg.c				\
				$(PRINTF_PATH)/$(CONV_PATH)/int_arg.c				\
				$(PRINTF_PATH)/$(CONV_PATH)/p_arg.c					\
				$(PRINTF_PATH)/$(CONV_PATH)/f_arg.c					\
				$(PRINTF_PATH)/$(CONV_PATH)/f_conv.c				\
				$(PRINTF_PATH)/$(CONV_PATH)/pct_arg.c				\
				$(PRINTF_PATH)/$(CONV_PATH)/s_arg.c					\
				$(PRINTF_PATH)/$(CONV_PATH)/d_conv.c				\
				$(PRINTF_PATH)/$(CONV_PATH)/u_conv.c				\
				$(PRINTF_PATH)/$(CONV_PATH)/o_conv.c				\
				$(PRINTF_PATH)/$(CONV_PATH)/x_conv.c				\
				$(PRINTF_PATH)/$(CONV_PATH)/not_conv.c				\
				$(PRINTF_PATH)/$(CONV_PATH)/man_arg.c				\
				$(PRINTF_PATH)/$(CONV_PATH)/cast.c					\
				$(PRINTF_PATH)/$(SRC_PATH)/ft_printf.c				\
				$(PRINTF_PATH)/$(SRC_PATH)/handle_buff.c			\
				$(PRINTF_PATH)/$(SRC_PATH)/manage_conv.c			\
				$(PRINTF_PATH)/$(SRC_PATH)/manage_colors.c			\
				$(PRINTF_PATH)/$(SRC_PATH)/options_padding.c		\
				$(PRINTF_PATH)/$(SRC_PATH)/options_check.c			\
				$(PRINTF_PATH)/$(SRC_PATH)/options.c			\
				$(PRINTF_PATH)/$(SRC_PATH)/parse_arg.c				\

#OBJ	   = $(SRCS:.c=.o)
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

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

# Protect

.PHONY:	all clean fclean re

# **************************************************************************** #

# RULES

# Main rules
all				: 	$(OBJ_PATH) $(NAME)

re				: 	fclean all

# Compilation rules
$(OBJ_PATH)		:
					@mkdir $(OBJ_PATH) 2> /dev/null || true
					@mkdir $(OBJ_PATH)/$(PRINTF_PATH) 2> /dev/null || true
					@mkdir $(OBJ_PATH)/$(PRINTF_PATH)/$(CONV_PATH) 2> /dev/null || true
					@mkdir $(OBJ_PATH)/$(PRINTF_PATH)/$(SRC_PATH) 2> /dev/null || true

$(NAME)			:	$(OBJ)
					@ar rc $(NAME) $^
					@ranlib $(NAME)

$(OBJ_PATH)/%.o: 	$(SRC_PATH)/%.c
					$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

# Clean rules
clean			:
					@rm -rf $(OBJ_PATH)

fclean			: 	clean
					@rm -f $(NAME)

norme:
					@norminette $(SRC)
					@norminette $(INC_PATH)/
# **************************************************************************** #
#@echo "make $(NAME)$(LOG_GREEN) ✓ $(LOG_NOCOLOR)"
#@echo "Remove $(NAME)$(LOG_GREEN) ✓ $(LOG_NOCOLOR)"
#@echo "Removes all .o & $(OBJ_PATH)/$(LOG_GREEN) ✓ $(LOG_NOCOLOR)"