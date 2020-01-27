# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eviana <eviana@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 19:02:32 by plaurent          #+#    #+#              #
#    Updated: 2019/10/18 14:12:49 by eviana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS	= -Wall -Werror -Wextra

SRC = ft_putchar_fd.c ft_putnbr.c ft_putendl.c ft_putstr.c ft_putchar.c	\
	  ft_itoa.c ft_strsplit.c ft_strtrim.c ft_strjoin.c ft_strsub.c		\
	  ft_strnequ.c ft_strequ.c ft_strmapi.c ft_strmap.c ft_striteri.c	\
	  ft_striter.c ft_strclr.c ft_strdel.c ft_strnew.c ft_memdel.c		\
	  ft_memalloc.c ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c	\
	  ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_atoi.c ft_strncmp.c		\
	  ft_strcmp.c ft_strnstr.c ft_strstr.c ft_strrchr.c ft_strlcat.c	\
	  ft_strchr.c ft_strncat.c ft_strcat.c ft_strncpy.c ft_strcpy.c		\
	  ft_memcmp.c ft_memchr.c ft_memmove.c ft_memccpy.c ft_memcpy.c		\
	  ft_bzero.c ft_strlen.c ft_memset.c ft_putnbr_fd.c ft_putendl_fd.c	\
	  ft_putstr_fd.c ft_strdup.c ft_ltoa.c ft_lltoa.c ft_strrev.c 		\
	  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c	\
	  ft_lstmap.c ft_foreach.c ft_factorial.c	ft_strcount.c			\
	  ft_power.c ft_fibonacci.c ft_sqrt.c ft_is_prime.c					\
	  ft_utoa.c ft_ultoa.c ft_ulltoa.c ft_convert_base.c ft_putull.c	\
	  ft_size_long.c get_next_line.c ft_swap.c ft_strallchr.c			\
	  ft_tabrev.c ft_tabcpy.c ft_strnum.c
	  
SRC2 = ft_printf/ft_build_str.c ft_printf/ft_conv_oux.c					\
	  ft_printf/ft_dispatch.c ft_printf/ft_inf_f.c ft_printf/ft_conv_c.c\
	  ft_printf/ft_conv_di.c ft_printf/ft_conv_f.c ft_printf/ft_conv_p.c\
	  ft_printf/ft_conv_percent.c ft_printf/ft_conv_s.c					\
	  ft_printf/ft_fill_buff.c ft_printf/ft_find.c						\
	  ft_printf/ft_formattotab.c ft_printf/ft_noconv.c					\
	  ft_printf/ft_preci_0_f.c ft_printf/ft_print_asset.c				\
	  ft_printf/ft_printf.c ft_printf/ft_set_width.c					\
	  ft_printf/ft_setprint.c ft_printf/ft_special.c ft_printf/ft_width.c

OBJ2 = ft_build_str.o ft_conv_oux.o ft_dispatch.o ft_inf_f.o ft_conv_c.o\
	  ft_conv_di.o ft_conv_f.o ft_conv_p.o ft_conv_percent.o ft_conv_s.o\
	  ft_fill_buff.o ft_find.o ft_formattotab.o ft_noconv.o 			\
	  ft_preci_0_f.o ft_print_asset.o ft_printf.o ft_set_width.o		\
	  ft_setprint.o ft_special.o ft_width.o

HEADER = libft.h ft_printf/ft_printf.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -c $(SRC) $(SRC2) -I $(HEADER)
	@ar rc $(NAME) $(OBJ) $(OBJ2)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

.PHONY: clean fclean

clean:
	@/bin/rm -f $(OBJ) $(OBJ2)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
