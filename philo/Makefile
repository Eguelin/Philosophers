# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/03 18:17:41 by eguelin           #+#    #+#              #
#    Updated: 2023/08/28 18:41:26 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#Standard
OUT_DIR	= build/
SRC_DIR	= src/
INC_DIR	= include/
NAME	= philo
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I $(INC_DIR) -g3 -pthread# -fsanitize=thread -D TSAN_OPTIONS=second_deadlock_stack=1
RM		= rm -rf

#Colors
BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m

#Sentence
COMP_MSG		= "$(GREEN)Compilation $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"
CLEAN_MSG		= "$(RED)Cleaning $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"
FULL_CLEAN_MSG	= "$(PURPLE)Full cleaning $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"

#Sources
ALL_FILES		= main.c

FT_PHILO_DIR = ft_philo/
FT_PHILO_FILES = ft_philo_add.c ft_philo_birth.c ft_philo_end.c ft_philo_new.c
ALL_FILES += $(addprefix $(FT_PHILO_DIR), $(FT_PHILO_FILES))

FT_THREAD_DIR = ft_thread/
FT_THREAD_FILES = ft_thread.c
ALL_FILES += $(addprefix $(FT_THREAD_DIR), $(FT_THREAD_FILES))


UTILS_DIR = utils/
UTILS_FILES = ft_init_data.c ft_input.c ft_perror.c ft_strlen.c ft_time_interval.c
ALL_FILES += $(addprefix $(UTILS_DIR), $(UTILS_FILES))

# ..._DIR = ../
# ..._FILES = ..
# ALL_FILES += $(addprefix $(..._DIR), $(..._FILES))

INC_FILES		= $(NAME).h

OBJS			= $(addprefix $(OUT_DIR), $(ALL_FILES:.c=.o))
HEADERS			= $(addprefix $(INC_DIR), $(INC_FILES))

#Rules
all: $(NAME)

$(NAME): $(OUT_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo $(COMP_MSG)
	@norminette | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'

$(OUT_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OUT_DIR)
	@echo $(CLEAN_MSG)

fclean:
	$(RM) $(NAME) $(OUT_DIR)
	echo $(CLEAN_MSG)
	echo $(FULL_CLEAN_MSG)

force:

$(OUT_DIR): force
	mkdir -p $(shell find $(SRC_DIR) -type d | awk -F "$(SRC_DIR)" '$$NF!="$(SRC_DIR)" {print "$(OUT_DIR)"$$(NF)}')

re: fclean all

exec: all
	./$(NAME)

.PHONY: all clean fclean force re exec
.SILENT:
