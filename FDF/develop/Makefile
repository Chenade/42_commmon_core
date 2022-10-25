NAME		=	fdf

RM			=	rm -rf

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra
CFLAGS		+=	-I $(INC_DIR) -I $(LIBFT_DIR) -I ${MLX_DIR}
CFLAGS		+=	-g3 -MMD

LFLAGS		= 	-L . -lmlx_Linux -lX11 -lXext -lm

CLIBS		=	-L . -lft

LIBFT		=	libft.a

LIBMLX		=	libmlx.a

LIBMLX_2	=	libmlx_Linux.a

SRCS_DIR	=	srcs

INC_DIR		=	incs

OBJS_DIR	=	objs

LIBFT_DIR	=	libft

MLX_DIR		=	minilibx-linux/

SRCS		=	main.c

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all:			$(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR) all
				mv $(LIBFT_DIR)/$(LIBFT) .
				$(MAKE) -C $(LIBFT_DIR) fclean
				@echo "\033[92mLibft Compile Successfully\n\033[0m"

$(LIBMLX):
				make -C ${MLX_DIR} all
				mv $(MLX_DIR)/$(LIBMLX) .
				mv $(MLX_DIR)/$(LIBMLX_2) .
				make clean -C ${MLX_DIR}
				@echo "\033[92mLibmlx Compile Successfully\n\033[0m"


$(NAME):		$(LIBFT) $(LIBMLX) $(OBJS)
				${CC} ${OBJS} ${CFLAGS} ${LFLAGS} $(LIBFT) -o $@
				@echo "\033[92mFDF Compile Successfully\033[0m"
				@echo "\033[94mCommand: ./fdf {filename}.fdf\033[0m\n"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS_DIR)

fclean:			clean
				$(RM) $(LIBFT) $(LIBMLX) $(LIBMLX_2)
				@echo "\033[92mLib Clean Successfully\033[0m\n"
				$(RM) $(NAME)
				@echo "\033[92mFDF Clean Successfully\033[0m\n"

re:				fclean all

.PHONY:			all clean fclean re bonus