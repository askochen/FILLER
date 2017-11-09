#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: askochen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/26 16:38:20 by askochen          #+#    #+#              #
#    Updated: 2017/07/05 20:07:10 by askochen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = filler

CC = gcc

LIBFT = libft/libft.a

SRC = main.c get_next_line.c\
	map.c mass.c tools.c tools1.c position.c 

OBJ = $(SRC:.c=.o)

HEADERS = libft/libft.h filler.h get_next_line.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

$(LIBFT):
	make -C libft/

libft_clean:
	make -C libft/ clean

libft_fclean:
	make -C libft/ fclean

clean: libft_clean
	rm -f $(OBJ) filler.h.gch get_next_line.h.gch *~

fclean: clean libft_fclean
	rm -f $(NAME)

re: fclean all
