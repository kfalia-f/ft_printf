# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/08 16:46:56 by kfalia-f          #+#    #+#              #
#    Updated: 2019/08/17 19:06:54 by kfalia-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

FLAGS = #-Wall -Wextra -Werror

SRC = srcs

SOURCES = $(SRC)/main.c \
		  $(SRC)/printf.c \
		  $(SRC)/parser.c \
		  $(SRC)/valid.c \
		  $(SRC)/helpers.c \
		  $(SRC)/interpretator.c \
		  $(SRC)/write.c \
		  $(SRC)/csp.c \
		  $(SRC)/diou.c \
		  $(SRC)/ft_x.c \
		  $(SRC)/ft_e.c

LIBFT_FOLDER = libft

LIBFT = -L $(LIBFT_FOLDER) -lft

OBJECTS = $(SOURCES:.c=.o)

HEADERS = -I includes -I $(LIBFT_FOLDER)/includes

%.o: %.c $(INCLUDES)
	@gcc $(FLAGS) $(HEADERS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIBFT_FOLDER)
	@make -C $(LIBFT_FOLDER) clean
	@gcc $(FLAGS) -o $(NAME) $(HEADERS) $(OBJECTS) $(LIBFT)

clean:
	@rm -f $(OBJECTS)
	@make -C $(LIBFT_FOLDER) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_FOLDER) fclean

re: fclean all

test:
	@gcc -g $(FLAGS) -o $(NAME) $(HEADERS) $(SOURCES) $(LIBFT)
