# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlim <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/11 11:32:41 by xlim              #+#    #+#              #
#    Updated: 2018/08/25 21:20:36 by xlim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra -c -I includes/

SRCSDIR = srcs

OBJDIR = obj

SRCS = $(wildcard $(SRCSDIR)/*/*.c)

SRCSFILE = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		   ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		   ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c \
		   ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c \
		   ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c \
		   ft_strstr.c ft_tolower.c ft_toupper.c \
		   ft_itoa.c ft_memalloc.c ft_memdel.c ft_putchar.c ft_putchar_fd.c \
		   ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
		   ft_putstr_fd.c ft_strclr.c ft_strdel.c ft_strequ.c ft_striter.c \
		   ft_striteri.c ft_strjoin.c ft_strmap.c ft_strmapi.c ft_strnequ.c \
		   ft_strnew.c ft_strsplit.c ft_strtrim.c ft_strsub.c\
		   ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
		   ft_lstnew.c \
		   ft_intdigit.c ft_isspace.c ft_lstfold.c ft_mocksb.c ft_strtoupper.c \
		   ft_strsplitlst.c

OBJ = $(SRCSFILE:%.c=%.o)

#OBJ = $(patsubst %.c, %.o, $(notdir $(SRCS)))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRCS)
	gcc $(FLAGS) $(SRCS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
