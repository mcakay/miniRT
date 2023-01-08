#Name
NAME = lib.a

#Directories

GNL_DIR = ./get_next_line/

LIBFT_DIR = ./libft/

VECLIB_DIR = ./vec_lib/

LIB_DIR = ./lib/

INCLUDE_DIR = ../include/

#Variables

SRCS = $(wildcard $(LIBFT_DIR)*.c $(GNL_DIR)*.c $(VECLIB_DIR)*.c)

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

#Rules

all: build

build: $(NAME)

$(NAME): $(OBJS) 
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C ./minilibx

re: fclean all

.PHONY: all build clean fclean re
