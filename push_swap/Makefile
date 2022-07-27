NAME =	push_swap
CC =	cc
RM = 	rm -rf

CFLAGS =	-Wall -Wextra -MMD #-Werror
#CFLAGS +=	-O2
CFLAGS +=	-g3
#CFLAGS +=	-fsanitize=address

LIB_DIR	 	= 	libft/
LIBNAME		=	$(LIB_DIR)libft.a
SRCS_DIR	=	srcs/
OBJS_DIR	=	objs/
INCS_DIR	= 	incs/
SRCS 		= 	main.c general.c stack.c cmd_sp.c cmd_r.c cmd_rr.c push_swap.c
OBJS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
DEPS		=	$(addprefix $(OBJS_DIR), $(SRCS:.c=.d))
INCS		=	-I $(INCS_DIR) -I $(LIB_DIR)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBNAME)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCS) $(LIBNAME)

$(LIBNAME):
	make -C $(LIB_DIR)

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean:
	@$(RM) $(OBJS_DIR)
	make clean -C $(LIB_DIR) 

fclean: 
	@$(RM) $(NAME)
	@$(RM) $(OBJS_DIR)
	make fclean -C $(LIB_DIR)  

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re