# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/08 16:46:56 by kfalia-f          #+#    #+#              #
#    Updated: 2019/08/28 16:52:20 by kfalia-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = srcs

LIB = libft

SOURCES = $(SRC)/printf.c \
		  $(SRC)/parser.c \
		  $(SRC)/valid.c \
		  $(SRC)/helpers.c \
		  $(SRC)/interpretator.c \
		  $(SRC)/write.c \
		  $(SRC)/csp.c \
		  $(SRC)/diou.c \
		  $(SRC)/ft_x.c \
		  $(SRC)/flags.c \
		  $(SRC)/f.c \
		  $(LIB)/ft_lstnew.c $(LIB)/ft_lstdelone.c $(LIB)/ft_lstdel.c $(LIB)/ft_lstadd.c \
		  $(LIB)/ft_lstiter.c $(LIB)/ft_lstmap.c $(LIB)/ft_listsize.c $(LIB)/ft_lstpush_back.c \
		  $(LIB)/ft_lstback.c $(LIB)/ft_lstat.c $(LIB)/ft_lstinsert_at.c $(LIB)/ft_lstfree_node.c \
		  $(LIB)/ft_memset.c $(LIB)/ft_bzero.c $(LIB)/ft_memcpy.c $(LIB)/ft_memccpy.c \
		  $(LIB)/ft_memmove.c $(LIB)/ft_memchr.c $(LIB)/ft_memcmp.c $(LIB)/ft_strlen.c \
		  $(LIB)/ft_2d_strlen.c $(LIB)/ft_strdup.c $(LIB)/ft_strcpy.c $(LIB)/ft_strncpy.c \
		  $(LIB)/ft_strcat.c $(LIB)/ft_strncat.c $(LIB)/ft_strlcat.c $(LIB)/ft_strchr.c \
		  $(LIB)/ft_strrchr.c $(LIB)/ft_strnchr.c $(LIB)/ft_strstr.c $(LIB)/ft_strnstr.c \
		  $(LIB)/ft_strcmp.c $(LIB)/ft_strncmp.c $(LIB)/ft_atoi.c $(LIB)/ft_isalpha.c \
		  $(LIB)/ft_isdigit.c $(LIB)/ft_isalnum.c $(LIB)/ft_isascii.c $(LIB)/ft_isprint.c \
		  $(LIB)/ft_toupper.c $(LIB)/ft_tolower.c $(LIB)/ft_putchar_base.c $(LIB)/ft_putstr_base.c \
		  $(LIB)/ft_putnbr_base.c $(LIB)/ft_strrev.c $(LIB)/ft_memcpy_backwards.c $(LIB)/ft_memalloc.c\
		  $(LIB)/ft_memalloc_2d_clean.c $(LIB)/ft_memdel.c $(LIB)/ft_strnew.c $(LIB)/ft_strdel.c \
		  $(LIB)/ft_strclr.c $(LIB)/ft_striter.c $(LIB)/ft_striteri.c $(LIB)/ft_strmap.c \
		  $(LIB)/ft_strmapi.c $(LIB)/ft_strequ.c $(LIB)/ft_strnequ.c $(LIB)/ft_strsub.c \
		  $(LIB)/ft_strjoin.c $(LIB)/ft_strjoinre.c $(LIB)/ft_strtrim.c $(LIB)/ft_strsplit.c \
		  $(LIB)/ft_itoa.c $(LIB)/ft_putchar.c $(LIB)/ft_putstr.c $(LIB)/ft_putendl.c \
		  $(LIB)/ft_putnbr.c $(LIB)/ft_putchar_fd.c $(LIB)/ft_putstr_fd.c $(LIB)/ft_putendl_fd.c \
		  $(LIB)/ft_putnbr_fd.c  $(LIB)/get_next_line.c $(LIB)/ft_itoa_unsig.c $(LIB)/ft_str_path.c \
		  $(LIB)/ft_ls_path_to_file.c $(LIB)/ft_del.c $(LIB)/ft_first_word.c $(LIB)/ft_mass2del.c

OBJECTS = $(SOURCES:.c=.o)

HEADERS = -I includes -I $(LIB)/includes

all: $(NAME)

%.o: %.c $(INCLUDES)
	@gcc $(FLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
