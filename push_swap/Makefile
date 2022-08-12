NAME =	push_swap

CC =	cc
RM = 	rm -rf

CFLAGS =	-Wall -Wextra -MMD #-Werror
CFLAGS +=	-g3

LIB_DIR	 	= 	libft/
LIBNAME		=	$(LIB_DIR)libft.a
SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/
INCS_DIR	= 	incs/

SRCS 		= 	main.c general.c push_swap.c
SRCS 		+=  stack.c stack2.c
SRCS 		+= 	cmd_sp.c cmd_r.c cmd_rr.c
SRCS 		+= 	algorithm.c
SRCS 		+= 	sort_big_move.c sort_big_lis.c

OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
DEPS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.d))
INCS		=	-I $(INCS_DIR) -I $(LIB_DIR)

all:		$(NAME)

$(NAME):	$(LIBNAME) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCS) $(LIBNAME)
	@echo "\033[92mPush Swap Compile Successfully\033[0m"


$(LIBNAME):
	@make -C $(LIB_DIR)
	@echo "\033[92mLibft Compile Successfully\n\033[0m"

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
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

-include $(DEPS)

.PHONY: all clean fclean re

# .SILENT:
