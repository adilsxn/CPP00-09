# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acuva-nu <acuva-nu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 12:35:24 by acuva-nu          #+#    #+#              #
#    Updated: 2023/02/25 16:34:52 by acuva-nu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS       = src/main.cpp src/ClapTrap.cpp src/FragTrap.cpp
OBJS       = ${SRCS:src/%.c=$(OBJ_DIR)/%.o}
OBJ_DIR    = obj
INCS 	   = inc/
NAME       = ex02
CC         = g++
CFLAGS     = -g -Wall -Wextra -Werror -std=c++98
RM         = rm -rf

all: ${NAME}

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS) ${LDFLAGS}

${NAME}: ${OBJS}
	@echo "Compiling ex02"
	@${CC} ${CFLAGS}  $^ -o $@  -I ${INCS} ${LDFLAGS}
	@echo "ex02 created"


${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

clean:
	@${RM} ${OBJ_DIR}

fclean: clean
	@${RM} ${NAME}
	@echo "ex02 deleted"

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine ${INCS}

.PHONY: all re clean fclean bonus
