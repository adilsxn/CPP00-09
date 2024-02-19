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


SRCS       = $(wildcard src/*.cpp) 
OBJS       = ${SRCS:src/%.cpp=$(OBJ_DIR)/%.o}
OBJ_DIR    = obj
INCS 	   = inc/
NAME       = phonebook
CC         = g++
CFLAGS     = -g -Wall -Wextra -Werror -std=c++98
RM         = rm -rf
LDFLAGS    = 

all: ${NAME}

$(OBJ_DIR)/%.o: src/%.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)

${NAME}: ${OBJS}
	@echo "Compiling phonebook"
	@${CC} ${CFLAGS}  $^ -o $@  -I ${INCS}
	@echo "phonebook created"

${OBJ_DIR}:
	@mkdir -p ${OBJ_DIR}

clean:
	@${RM} ${OBJ_DIR}

fclean: clean
	@${RM} ${NAME}
	@echo "phonebook deleted"

re: fclean all

.PHONY: all re clean fclean bonus
