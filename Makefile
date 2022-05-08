# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manu <manu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 18:26:06 by manu              #+#    #+#              #
#    Updated: 2022/05/08 20:35:00 by manu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
LIBFT			=	libft
SRC_DIR			=	src
MANDATORY_SRC 	:= 	$(shell find ./$(SRC_DIR) \( -name '*.c' \))
MANDATORY_OBJ 	= 	$(MANDATORY_SRC:.c=.o)
CFLAGS 			= 	-Wall -Wextra -Werror
CC 				= 	gcc

all: $(NAME)
		
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	echo $@ $^
	$(CC) -c $(FLAGS) -o $@ $^

$(NAME): $(MANDATORY_OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(MANDATORY_OBJ)

re: fclean $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

norminette:
	norminette -R CheckForbiddenSourceHeader | grep Error

testme:
	rm -f .a.out
	rm -f $(ALL_OBJ)
	rm -f $(NAME)
	gcc -g $(ALL_SRC)

.PHONY: all clean fclean re bonus

