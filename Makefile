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

MINILIBX = ./lib/minilibx/minilibx/libmlx.a

FRAMEWORK = -framework OpenGL -framework AppKit

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

RM = rm -f

#Rules
all: $(NAME)

$(LIB):
	@make -C $(LIB_DIR)

$(MINILIBX):
	@make -C ./lib/minilibx

$(NAME): $(OBJS) $(LIB) $(MINILIBX) 
	$(CC) $(CFLAGS) $(FRAMEWORK) $(OBJS) $(LIB) $(MINILIBX) -o $(NAME)

$(LIB_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIB_DIR)minilibx/minilibx/mlx.h

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