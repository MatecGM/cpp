# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gadelbes <gadelbes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 15:23:49 by fparis            #+#    #+#              #
#    Updated: 2025/01/10 17:14:25 by mbico            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -std=c++98 -Wall -Werror -Wextra -g
NAME = BraiiiiiiinnnzzzZ

SRCS = main.cpp\
		Zombie.cpp\
	   newZombie.cpp\
	   randomChump.cpp\

OBJS = $(SRCS:%.cpp=%.o)

RED = \033[0;31m
GREEN = \033[0;34m
YELLOW = \033[1;33m
PURPLE = \033[0;35m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $^ -o $(NAME) -I .
	@echo "$(GREEN)$(NAME) compilation successful !$(NC)"

%.o: %.cpp
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling $(notdir $<)...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I .

clean:
	@echo "$(RED)Removing object...$(NC)"
	@rm *.o

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(NC)"
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all bonus clean fclean re run
