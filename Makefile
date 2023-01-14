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

NAME = FdF

SRC = main.c fdf_utils.c fdf_draw.c fdf_draw_utils.c fdf_draw_line.c fdf_image.c\
fdf_hook.c fdf_hook_utils.c fdf_color.c fdf_free.c

INCLUDES = -I fdf.h

LIBS = -L. -lft -lmlx

FRAME = -framework OpenGL -framework Appkit

FLAGS = -Wall -Werror -Wextra $(INCLUDES)

all: $(NAME)

$(NAME):
	cd libft && $(MAKE)
	cp libft/libft.a libft.a
	rm -f libft/libft.a
	cd minilibx_macos && $(MAKE)
	cp minilibx_macos/libmlx.a libmlx.a
	rm -f minilibx_macos/libmlx.a
	cc -o $(NAME) $(SRC) $(FLAGS) $(LIBS) $(FRAME)
	
clean:
	cd libft && $(MAKE) clean
	cd minilibx_macos && $(MAKE) clean

fclean:
	rm -f libmlx.a
	rm -f libft.a
	cd libft && $(MAKE) clean
	cd minilibx_macos && $(MAKE) clean
	rm -f FdF

re: fclean all

test: fclean all
	./fdf test_maps/t2.fdf
	$(MAKE) fclean