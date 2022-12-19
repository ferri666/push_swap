NAME 			= push_swap

LIBFT_DIR		= libft

LIBFT			= libft.a

INCLUDE			= include/

SRC_DIR			= src/

OBJ_DIR			= obj/

SRC_FILES		= validate program main commands commands_utils mini_sort sort_utils mini_sort_utils\
				  big_sort big_sort_utils sort_utils2 giant_sort

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I$(INCLUDE)
AR				= ar rcs

SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all:				$(LIBFT) $(NAME)    

$(NAME)			:	$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) -o $@ $^
					@echo "Program Created"

$(OBJ_DIR)%.o	: 	$(SRC_DIR)%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) -o $@ -c $^

$(LIBFT):			$(LIBFT_DIR)
					@make -C $(LIBFT_DIR)
					@cp $(LIBFT_DIR)/$(LIBFT) .

clean:				
					@$(RM) $(OBJ)
					@rm -rf $(OBJ_DIR)
					@make -C $(LIBFT_DIR) clean
					@echo "Clean boys Indeed!"

fclean:				
					@make -C $(LIBFT_DIR) fclean
					@$(RM) $(LIBFT)
					@$(RM) $(NAME)
					@echo "Super clean boys Forever!"

re:					fclean $(NAME)

norm:			
					@norminette $(SRC) $(INCLUDE) $(LIBFT_DIR) | grep -v Norme -B1 || true


.PHONY:				all clean fclean re norm