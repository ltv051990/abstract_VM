#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/28 14:01:05 by tlutsyk           #+#    #+#              #
#    Updated: 2018/07/28 14:01:06 by tlutsyk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC			=	clang++

CFLAGS		=	-Wextra -Werror -Wall -std=c++11 -g

NAME		=	abstract_VM

SRC			=	main.cpp Commands.cpp Controller.cpp Exception.cpp Factory.cpp				
				

HDRS		=	Commands.hpp Controller.hpp Exception.hpp Factory.hpp \
				Ioperand.hpp

OBJ			=	$(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

OBJDIR		=	obj

LIBR		=	-I Operands.hpp

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@echo "Creating" $(NAME) "..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBR) -o $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJ): $(OBJDIR)/%.o : %.cpp $(HDRS)
	@echo "Compiling" $< "..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Obj clean"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "Full clean"
	@rm -rf $(NAME)

re: fclean all
