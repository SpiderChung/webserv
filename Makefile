NAME		=	MutantStack

CC			=	c++

HEADER		= 	${shell find . -name "*.hpp"}

FLAGS		=	-Wall -Werror -Wextra -std=c++98 -pedantic -g

OBJ_DIR		=	obj/

SRC			=	${shell find . -name "*.cpp"}

OBJ_FILES	=	$(patsubst %.cpp,%.o, $(notdir $(SRC)))

OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

$(OBJ_DIR)%.o: %.cpp Makefile $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling [$@]...$(RESET)"
	@$(CC) $(FLAGS) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(GREEN)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Finished [$(NAME)]$(RESET)"

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
			rm -rf $(OBJ_DIR); \
			echo "$(BLUE)Deleting all objects$(RESET)"; else \
			echo "No objects to remove"; \
	fi;

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		rm -f $(NAME); \
		echo "$(BLUE)Deleting $(NAME) $(RESET)"; else \
		echo "No Executable to remove"; \
	fi;

re: fclean all

.PHONY: all clean fclean re


RESET		=	\033[0m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
RED			=	\033[31m
UP			=	\033[A
CUT			=	\033[K