# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewallner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 18:20:33 by ewallner          #+#    #+#              #
#    Updated: 2017/01/16 12:48:59 by ewallner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SRC=	ft_atoi_base.c \
		ft_converttype.c \
		ft_error_handle.c \
		ft_parser.c \
		ft_printwchar.c \
		ft_chars.c \
		ft_strings.c \
		ft_wstrings.c \
		main.c

OBJ= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC= gcc
RANLIB = ranlib
CFLAGS= -Wall -Wextra -Werror

LIBFT= ./libft/libft.a
LIBINC= -I./libft
LIBLINK= -L./libft -lft

SRCDIR= ./src/
INCDIR= ./includes/
OBJDIR= ./obj/

all: $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

clean: remoblib
	rm -rf $(OBJDIR)

$(LIBFT):
	make -C ./libft

$(NAME): obj libft $(OBJ) 
	ar rc $(NAME) $(LIBFT) $(OBJ)

remlib:
	rm -rf $(LIBFT)

remoblib:
	make fclean -C ./libft/

fclean: clean remlib
	rm -rf $(NAME)

re: fclean all
