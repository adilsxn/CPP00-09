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


SRCS       = src/main.cpp src/Harl.cpp
OBJS       = ${SRCS:src/%.c=$(OBJ_DIR)/%.o}
OBJ_DIR    = obj
INCS 	   = inc/
NAME       = harlFilter
CC         = g++
CFLAGS     = -g -Wall -Wextra -Werror -Wimplicit-fallthrough=0 -std=c++98
RM         = rm -rf

all: ${NAME}

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS) ${LDFLAGS}

${NAME}: ${OBJS}
	@echo "Compiling harlFilter"
	@${CC} ${CFLAGS}  $^ -o $@  -I ${INCS} ${LDFLAGS}
	@echo "harlFilter created"


${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

clean:
	@${RM} ${OBJ_DIR}

fclean: clean
	@${RM} ${NAME}
	@echo "harlFilter deleted"

re: fclean all

.PHONY: all re clean fclean bonus
