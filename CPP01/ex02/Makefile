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


SRCS       = src/main.c 
B_SRC      = 	
OBJS       = ${SRCS:src/%.c=$(OBJ_DIR)/%.o}
B_OBJS     = ${B_SRC:src/%.c=$(OBJ_DIR)/%.o}
OBJ_DIR    = obj
INCS 	   = inc/
NAME       = CPP
B_NAME     = b_CPP
CC         = g++
CFLAGS     = -g -Wall -Wextra -Werror -std=c++98
RM         = rm -rf

all: ${NAME}

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS) ${LDFLAGS}

${NAME}: ${OBJS}
	@echo "Compiling CPP"
	@make -s -C libft
	@${CC} ${CFLAGS}  $^ -o $@  -I ${INCS} ${LDFLAGS}
	@echo "CPP created"

$(B_OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@

bonus: ${B_NAME}

${B_NAME}: $(OBJ_DIR)
	@echo "Compiling b_CPP"
	@make -s -C libft
	@${CC} ${CFLAGS}  $^ -o ${B_NAME} -I ${INCS} ${LDFLAGS}
	@echo "b_CPP created"

${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

clean:
	@${RM} ${OBJ_DIR}

fclean: clean
	@${RM} ${B_NAME}
	@${RM} ${NAME}
	@make fclean -s -C libft
	@echo "CPP deleted"

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine ${INCS}

.PHONY: all re clean fclean bonus
