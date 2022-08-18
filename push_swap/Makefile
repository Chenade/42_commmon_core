
NAME		=	push_swap

NAME_CHECKER=	checker

RM			=	rm -rf

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra
CFLAGS		+=	-I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR)
CFLAGS		+=	-g3 -MMD

CLIBS		=	-L . -lft

LIBFT		=	libft.a

SRCS_DIR	=	srcs

INC_DIR		=	incs

OBJS_DIR	=	objs

LIBFT_DIR	=	libft

SRC_GENERAL	=	general/general.c					\
				general/parsing.c					\
				general/stack.c						\
				general/stack2.c					\
				general/cmd_sp.c					\
				general/cmd_r.c						\
				general/cmd_rr.c

SRCS		=	$(SRC_GENERAL)
SRCS		+=	program/main.c						\
				program/push_swap.c					\
				program/algorithm.c					\
				program/sort_big_move.c				\
				program/sort_big_lis.c

SRCS_CHECKER=	$(SRC_GENERAL)
SRCS_CHECKER+=	checker/main.c						\
				checker/checker.c

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

OBJS_CHECKER=	$(addprefix $(OBJS_DIR)/, $(SRCS_CHECKER:.c=.o))

all:			$(NAME) $(NAME_CHECKER)

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR) all
				mv $(LIBFT_DIR)/$(LIBFT) .
				$(MAKE) -C $(LIBFT_DIR) fclean
				@echo "\033[92mLibft Compile Successfully\n\033[0m"

$(NAME):		$(LIBFT) $(OBJS)
				$(CC) $(OBJS) $(CFLAGS) $(CLIBS) -o $(NAME)
				@echo "\033[92mPush Swap Compile Successfully\n\033[0m"

$(NAME_CHECKER):$(LIBFT) $(OBJS_CHECKER)
				$(CC) $(OBJS_CHECKER) $(CFLAGS) $(CLIBS) -o $(NAME_CHECKER)
				@echo "\033[92mPush Swap Checker Compile Successfully\n\033[0m"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS_DIR)
				@echo ""

fclean:			clean
				$(RM) $(LIBFT)
				@echo "\033[92mLibft Clean Successfully\033[0m"
				$(RM) $(NAME)
				@echo "\033[92mPush Swap Clean Successfully\033[0m"
				$(RM) $(NAME_CHECKER)
				@echo "\033[92mPush Swap Checker Clean Successfully\n\n\033[0m"

re:				fclean all

bonus:			checker

.PHONY:			all clean fclean re bonus