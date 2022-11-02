###############################################################################
#                                                                             #
#                              Basic Config                                   #
#                                                                             #
###############################################################################

NAME		=	fdf

RM			=	rm -rf

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra
CFLAGS		+=	-I $(INCS_DIR) -I $(LIBFT_DIR) -I ${MLX_DIR}
CFLAGS		+=	-g3 -MMD

LFLAGS		= 	-L . -lmlx_Linux -lX11 -lXext -lm

CLIBS		=	-L . -lft

###############################################################################
#                                                                             #
#                                  Variable                                   #
#                                                                             #
###############################################################################

LIBFT		=	libft.a

LIBMLX		=	libmlx.a

LIBMLX_2	=	libmlx_Linux.a

LIBS_DIR	=	libs

LIBFT_DIR	=	$(LIBS_DIR)/libft

MLX_DIR		=	$(LIBS_DIR)/minilibx-linux

SRCS_DIR	=	srcs

INCS_DIR	=	incs

OBJS_DIR	=	objs

SRCS_GEN	=	general.c		\
				tools.c			\
				helper.c		\

SRCS		=	$(SRCS_GEN)
SRCS		+=	main.c			\
				init.c			\
				parse.c			\
				mlx_setup.c		\
				matrix.c		\
				draw.c

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

###############################################################################
#                                                                             #
#                                   COMMAND                                   #
#                                                                             #
###############################################################################

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

project:		clean $(OBJS)
				${CC} ${OBJS} ${CFLAGS} ${LFLAGS} $(LIBFT) -o $(NAME)
				@echo "\033[92mFDF Compile Successfully\033[0m"
				@echo "\033[94mCommand: ./fdf {filename}.fdf\033[0m\n"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) ${LFLAGS} -c $< -o $@

clean:
				$(RM) $(OBJS_DIR)

fclean:			clean
				$(RM) $(LIBFT) $(LIBMLX) $(LIBMLX_2)
				@echo "\033[92mLib Clean Successfully\033[0m\n"
				$(RM) $(NAME)
				@echo "\033[92mFDF Clean Successfully\033[0m\n"

re:				fclean all

.PHONY:			all clean fclean re project