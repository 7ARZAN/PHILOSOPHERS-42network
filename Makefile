# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 11:25:31 by 7arzan            #+#    #+#              #
#    Updated: 2023/04/25 19:53:00 by elakhfif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_COMMON = ./src/actions.c\
	     ./src/checker.c\
	     ./src/create_mutex_and_thread.c\
	     ./src/functions_needed.c\
	     ./src/get_time.c\
	     ./src/init.c\
	     ./src/routine.c\
	     ./philo.c\

OBJ_COMMON = $(SRC_COMMON:.c=.o)

INCLUDE = ./include/philo/philo.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -pthread

NAME = philo

RM = rm -f

all: $(NAME)


CLR_RMV:= \033[0m
RED:= \033[1;31m
GREEN:= \033[1;32m
YELLOW:= \033[1;33m
BLUE:= \033[1;34m
CYAN:= \033[1;36m

.c.o:
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ_COMMON)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -o $(NAME) $(OBJ_COMMON)
	@echo "$(BLUE)Compilation of ${YELLOW}$(NAME) $(RED)BY 7ARZAN ..."
	@echo "$(GREEN)HAK HAHOWA $(YELLOW)$(NAME) $(GREEN)M9AD  ✔️"

clean:
	@$(RM) $(OBJ_COMMON)

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)7ARZAN $(CYAN)GALIK MSA7 $(GREEN)L7ZA9 ✔️"

re : fclean all
