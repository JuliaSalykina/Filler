# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannette <mannette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/06 22:06:10 by mannette          #+#    #+#              #
#    Updated: 2020/06/16 01:56:33 by mannette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mannette.filler
LIB_PATH = ./libft/
HEADER = ./includes/
LIB = ./libft/libft.a

SRC_DIR = src
OBJ_DIR = obj

SRC_ALL = filler.c validation.c map_piece.c heat_map.c find_coord.c result.c

SRC = $(addprefix $(SRC_DIR)/,$(SRC_ALL))
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_ALL:.c=.o))

.PHONY: all clean fclean re force norm

all: $(LIB) $(NAME)

$(LIB): force
	make -C $(LIB_PATH)

$(NAME): $(OBJ_DIR) $(OBJ)
	gcc -Wall -Werror -Wextra $(OBJ) -I $(HEADER) -L "libft/" -lft -o $@

$(OBJ_DIR):
	@mkdir -p obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ./includes/filler.h
	gcc -Wall -Wextra -Werror -I $(HEADER) -c $< -o $@

norm:
	norminette .

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_PATH)
	

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_PATH)

re: fclean all
