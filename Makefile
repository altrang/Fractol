# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrang <atrang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/18 10:55:25 by atrang            #+#    #+#              #
#    Updated: 2016/04/20 12:00:40 by atrang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c hook.c ft_mandelbrot.c suite1.c color.c ft_julia.c ft_burning.c util.c error.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		 make -C libft
		 gcc $(OBJ) -o $(NAME) -lft -L ./libft -framework OpenGl -lmlx -framework AppKit $(FLAGS)

%.o:%.c
		gcc -c $< -o $@ -Iincludes $(FLAGS)

clean:
		make -C libft/ clean
		rm -rf $(OBJ)

fclean: clean
		make -C libft/ fclean
		rm -rf $(NAME)

re: fclean all
