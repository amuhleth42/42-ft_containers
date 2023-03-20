# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amuhleth <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 17:26:25 by amuhleth          #+#    #+#              #
#    Updated: 2022/11/02 16:12:39 by amuhleth         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= test1
CXX			= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS		= main.cpp			\

OBJS		= $(SRCS:.cpp=.o)


$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)


clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :	fclean all

.PHONY : all clean fclean re
