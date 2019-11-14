# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: lumeyer <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/11 16:51:50 by lumeyer      #+#   ##    ##    #+#        #
#    Updated: 2019/10/27 16:56:52 by lumeyer     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME		=	test

CC			=	gcc 
CFLAGS		=	-Wall -Wextra -Werror
HEADER 		=	get_next_line.h
LFLAGS		=	-I $(HEADER)
BUFF		=	-D BUFFER_SIZE
SIZE		=	$$size
ARGS		=	./filetests/t* ./filetests/*.test

SRCS		=	get_next_line.c\
				get_next_line_utils.c\
				main.c\

SRCSBIS		=	get_next_line.c\
				get_next_line_utils.c\
				main_pipe.c\

OBJ			=	$(SRCS:.c=.o)
BIS			=	$(SRCSBIS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) && ./$(NAME) $(ARGS)

pipe: $(BIS)
	@$(CC) $(BIS) -o $(NAME)

%.o : %.c $(HEADER)
	@$(CC) -g $(CFLAGS) $(BUFF)=$(SIZE) $(LFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BIS)

cat:
	@cat -e $(ARGS)

check: $(OBJ)
	@$(CC) $(OBJ) -o $(NAME) && valgrind ./$(NAME) $(ARGS)

fclean: clean
	@rm -rf $(NAME) $(NAME).dSYM

re : fclean all

.PHONY: all fclean clean re cat
