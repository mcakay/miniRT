#Name
NAME = ./bin/minirt

#Directories
SRC_DIR = ./src/

INC_DIR = ./include/

LIB_DIR = ./lib/

#Variables1

SRCS = $(wildcard $(SRC_DIR)*.c)

OBJS = $(subst $(SRC_DIR), $(LIB_DIR), $(SRCS:.c=.o))

LIB = $(LIB_DIR)lib.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

RM = rm -f

#Rules
all: $(NAME)

$(LIB):
	@make -C $(LIB_DIR)

$(NAME): $(OBJS) $(LIB)  
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR)

run:
	$(NAME) scenes/scene.rt

clean:
	@make -C $(LIB_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@make -C $(LIB_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all run clean fclean re