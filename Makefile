# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: 7arzan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 11:25:31 by 7arzan            #+#    #+#              #
#    Updated: 2023/04/18 11:30:37 by 7arzan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_COMMON = ./philo/utils/init.c\
	     ./philo/utils/functions_needed.c\
	     ./philo/utils/mutex_and_pthread_wait.c\
	     ./philo/utils/connect_philo_with_vars.c\
	     ./philo/utils/functions_needed.c\
	     ./philo/utils/ft_print.c\
	     ./philo/utils/get_time.c\
	     ./philo/utils/is_dead_or_not.c\


OBJ_COMMON = $(SRC_COMMON:.c=.o)

INCLUDE = ./include

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
