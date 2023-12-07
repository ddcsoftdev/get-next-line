# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 11:44:28 by ddemarco          #+#    #+#              #
#    Updated: 2022/05/21 12:22:11 by ddemarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a

CC = gcc

FLAGS = -c -Wall -Wextra -Werror -D BUFFER_SIZE=42

INCLUDES = includes/get_next_line.h

INCLUDES_B = includes/get_next_line_bonus.h

SRCS = 		src/get_next_line.c \
			src/get_next_line_utils.c \

SRCS_B = 		src/get_next_line_bonus.c \
			src/get_next_line_utils_bonus.c \

		
OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

OBJS_R =	get_next_line.o \
			get_next_line_utils.o \
			get_next_line_bonus.o \
			get_next_line_utils_bonus.o \
			includes/get_next_line.h.gch \
			includes/get_next_line_bonus.h.gch \

$(NAME): $(OBJS) $(OBJS_B)
		$(CC) $(FLAGS) $(INCLUDES) $(INCLUDES_B) $(SRCS)$(SRCS_B)
		ar -rcs $(NAME) $(OBJS) $(OBJS_B)


all : $(NAME)

bonus : $(NAME)

clean : 
		rm -rf $(OBJS)
		rm -rf $(OBJS_B)
		rm -rf $(OBJS_R)
fclean : clean
		rm -rf $(NAME)
		rm -rf $(BONUS)
re : fclean all

.PHONY : all bonus clean fclean re