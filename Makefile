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

NAME1		= ft
NAME2		= std

CXX			= c++
CXXFLAGS	= -I./incs -Wall -Werror -Wextra -std=c++98 -g

SRCS1		= test/ft.cpp
SRCS2		= test/std.cpp

SRCS3	= test/subject_ft.cpp
SRCS4	= test/subject_std.cpp

OBJS1		= $(SRCS1:.cpp=.o)
OBJS2		= $(SRCS2:.cpp=.o)
OBJS3		= $(SRCS3:.cpp=.o)
OBJS4		= $(SRCS4:.cpp=.o)


all : $(NAME2) $(NAME1)

$(NAME1)	: $(OBJS1)
	$(CXX) $(INCL) $(CXXFLAGS) $(OBJS1) -o $(NAME1)

$(NAME2)	: $(OBJS2)
	$(CXX) $(INCL) $(CXXFLAGS) $(OBJS2) -o $(NAME2)

subject : $(OBJS3) $(OBJS4)
	$(CXX) $(INCL) $(CXXFLAGS) $(OBJS3) -o subject_ft
	$(CXX) $(INCL) $(CXXFLAGS) $(OBJS4) -o subject_std

clean :
	rm -f $(OBJS1) $(OBJS2) $(OBJS4) $(OBJS5)

fclean : clean
	rm -f $(NAME1) $(NAME2) subject_ft subject_std

re :	fclean all

.PHONY : all clean fclean re
