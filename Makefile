# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmykkane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 14:22:41 by jmykkane          #+#    #+#              #
#    Updated: 2022/10/24 14:22:53 by jmykkane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a

SRC = main.c

SRC_O = $(SRC:.c=.o)

LIBFT = libft/libft.a

MINILIBX = minilibx_macos/libmlx.a

INCLUDES = fdf.h

LIBS = -L. -lft -lmlx

FRAME = -framework OpenGL -framework Appkit

FLAGS = -Wall -Werror -Wextra -I $(INCLUDES)

all: $(NAME)

$(NAME):
	cd libft && $(MAKE)
	mv libft/libft.a libft.a
	cd minilibx_macos && $(MAKE)
	mv minilibx_macos/libmlx.a libmlx.a
	cc $(FLAGS) $(SRC) $(LIBS) $(FRAME)
	
clean:
	rm -f $(SRC_O)
	cd libft && $(MAKE) clean
	cd minilibx_macos && $(MAKE) clean

fclean:
	rm -f libmlx.a
	rm -f libft.a
	cd libft && $(MAKE) clean
	cd minilibx_macos && $(MAKE) clean

re: fclean all

test:
	$(MAKE) fclean
	cd libft && $(MAKE)
	mv libft/libft.a libft.a
	cd minilibx_macos && $(MAKE)
	mv minilibx_macos/libmlx.a libmlx.a
	cc $(INCLUDES) $(SRC) $(LIBS) $(FRAME)
	./a.out "test_maps/42.fdf"