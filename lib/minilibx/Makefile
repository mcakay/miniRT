LINK		=		https://projects.intra.42.fr/uploads/document/document/9956/minilibx_opengl.tgz
ARCHIEVE	=		minilibx_opengl.tgz
FOLDER		=		minilibx_opengl_20191021

RM				= rm -rf
DIR				= $(shell echo $(PWD))
NAME			= minilibx

LIB = ./.$(NAME)

# Rules

all : $(LIB)

$(LIB):
	@curl -O $(LINK)
	@gunzip -c $(ARCHIEVE) | tar xopf -
	@mv $(FOLDER) $(NAME)
	make -C $(NAME)
	@$(RM) *.tgz
	@mkdir $(LIB)

fclean:
	@$(RM) $(LIB) $(NAME)

.PHONY: all  fclean re