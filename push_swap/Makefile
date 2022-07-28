NAME =	push_swap
NAME_CHECKER = bonus_checker

CC =	cc
RM = 	rm -rf

CFLAGS =	-Wall -Wextra # -MMD #-Werror
CFLAGS +=	-g3

LIB_DIR	 	= 	libft/
LIBNAME		=	$(LIB_DIR)libft.a
SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/
INCS_DIR	= 	incs/
SRCS_CHECKER_DIR	=	srcs/bonus/
OBJS_CHECKER_DIR	=	objs/bonus/

SRCS 		= 	main.c general.c push_swap.c
SRCS 		+=  stack.c stack_tmp.c
SRCS 		+= 	cmd_sp.c cmd_r.c cmd_rr.c
SRCS 		+= 	sort_big.c sort_small.c

OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
DEPS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.d))
INCS		=	-I $(INCS_DIR) -I $(LIB_DIR)

SRCS_CHECKER 		= 	main.c general.c push_swap.c
SRCS_CHECKER 		+=  stack.c stack_tmp.c
SRCS_CHECKER 		+= 	cmd_sp.c cmd_r.c cmd_rr.c
SRCS_CHECKER 		+= 	sort_big.c sort_small.c

OBJS_CHECKER		=	$(addprefix $(OBJS_CHECKER_DIR), $(SRCS_CHECKER:.c=.o))
DEPS_CHECKER		=	$(addprefix $(OBJS_CHECKER_DIR), $(SRCS_CHECKER:.c=.d))
INCS_CHECKER		=	-I $(INCS_DIR) -I $(LIB_DIR)

all:		$(NAME)

$(NAME):	$(LIBNAME) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCS) $(LIBNAME)
	@echo "\033[92mPush Swap Compile Successfully\033[0m"

$(NAME_CHECKER):	$(LIBNAME) $(OBJS_CHECKER) 
	$(CC) $(CFLAGS) $(OBJS_CHECKER) -o $(NAME_CHECKER) $(INCS) $(LIBNAME)
	@echo "\033[92mChecker Compile Successfully\033[0m"

$(LIBNAME):
	@make -C $(LIB_DIR)
	@echo "\033[92mLibft Compile Successfully\n\033[0m"

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJS_CHECKER)%.o:$(SRCS_CHECKER_DIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean:
	$(RM) $(OBJS_DIR)
	make clean -C $(LIB_DIR) 

fclean: 
	@make fclean -C $(LIB_DIR)  
	@echo "\033[92mLibft Clean Successfully\033[0m"
	$(RM) $(OBJS_DIR)
	$(RM) $(NAME)
	@echo "\033[92mPush Swap Clean Successfully\n\n\033[0m"

re: fclean all

bonus: $(NAME_CHECKER)

-include $(DEPS)

.PHONY: all clean fclean re

# .SILENT:
