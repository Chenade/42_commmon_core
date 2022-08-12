
NAME		=	push_swap

NAME_CHECKER=	checker

RM			=	rm -rf

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra -I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR)
CFLAGS		+=	-g3 -MMD

CLIBS		=	-L . -lft

LIBFT		=	libft.a

SRCS_DIR	=	srcs

INC_DIR		=	incs

OBJS_DIR	=	objs

LIBFT_DIR	=	libft

SRCS		=	program/main.c						\
				program/general.c					\
				program/push_swap.c					\
				program/stack.c						\
				program/stack2.c					\
				program/cmd_sp.c					\
				program/cmd_r.c						\
				program/cmd_rr.c					\
				program/algorithm.c					\
				program/sort_big_move.c				\
				program/sort_big_lis.c

SRCS_CHECKER=	checker/main.c						\
				program/parsing.c					\
				program/stack.c						\
				checker/operations/rotate.c			\
				checker/operations/reverse_rotate.c	\
				checker/operations/push.c			\
				checker/operations/swap.c

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

OBJS_CHECKER=	$(addprefix $(OBJS_DIR)/, $(SRCS_CHECKER:.c=.o))

$(NAME):		$(LIBFT) $(OBJS)
				$(CC) $(OBJS) $(CFLAGS) $(CLIBS) -o $(NAME)
				@echo "\033[92mPush Swap Compile Successfully\033[0m"

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR) all
				mv $(LIBFT_DIR)/$(LIBFT) .
				$(MAKE) -C $(LIBFT_DIR) fclean
				@echo "\033[92mLibft Compile Successfully\n\033[0m"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

clean:
				$(RM) $(OBJS_DIR)

fclean:			clean
				$(RM) $(LIBFT)
				@echo "\033[92mLibft Clean Successfully\033[0m"
				$(RM) $(NAME)
				$(RM) $(NAME_CHECKER)
				@echo "\033[92mPush Swap Clean Successfully\n\n\033[0m"

re:				fclean all

$(NAME_CHECKER):$(LIBFT) $(OBJS_CHECKER)
				$(CC) $(OBJS_CHECKER) $(CFLAGS) $(CLIBS) -o $(NAME_CHECKER)

bonus:			checker

.PHONY:			all clean fclean re bonus