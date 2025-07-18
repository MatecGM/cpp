# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 23:42:46 by mbico             #+#    #+#              #
#    Updated: 2025/07/10 00:11:49 by mbico            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -std=c++98 -Wall -Werror -Wextra
NAME = convert

SRCS = $(shell find . -name '*.cpp')
OBJS = $(SRCS:%.cpp=%.o)

RED = \033[0;31m
GREEN = \033[0;34m
YELLOW = \033[1;33m
PURPLE = \033[0;35m
NC = \033[0m

ifeq ($(DEBUG),true)
	CFLAGS += -g -DDEBUG
endif

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $(NAME) -I .
	@echo "$(GREEN)$(NAME) compilation successful !$(NC)"

%.o: %.cpp
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling $(notdir $<)...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I .

clean:
	@echo "$(RED)Removing object...$(NC)"
	@rm -f *.o

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(NC)"
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
