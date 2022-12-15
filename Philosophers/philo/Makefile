###############################################################################
#                                                                             #
#                              Basic Config                                   #
#                                                                             #
###############################################################################

NAME		=	philo

RM			=	rm -rf

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra
CFLAGS		+=	-g3 -MMD -pthread
CFLAGS		+=	-I $(INCS_DIR)

LFLAGS		=	-I $(LIBFT_DIR) -I ${MLX_DIR}
LFLAGS		+= 	-L . -lmlx_Linux -lX11 -lXext -lm

CLIBS		=	-L . -lft

Y			= "\033[33m"
RED			= "\033[31m"
GREEN		= "\033[92m"
BLUE		= "\033[94m"
X			= "\033[0m"
UP			= "\033[A"
CUT			= "\033[K"

###############################################################################
#                                                                             #
#                                  Variable                                   #
#                                                                             #
###############################################################################

SRCS_DIR	=	srcs

INCS_DIR	=	incs

OBJS_DIR	=	objs

SRCS_GEN	=	lib/utils.c		\
				lib/tools.c			\
				parse.c
# 				helper.c		\

SRCS		=	$(SRCS_GEN)
SRCS		+=	main.c			\
				philo.c

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

###############################################################################
#                                                                             #
#                                   COMMAND                                   #
#                                                                             #
###############################################################################

all:			$(NAME)

norminette:
				norminette $(SRCS_DIR) $(INCS_DIR)

$(NAME):		norminette $(OBJS)
				${CC} ${OBJS} ${CFLAGS} $(LIBFT) -o $@
				@echo ${GREEN}"Philo Compile Successfully"${X}
				@echo ${BLUE}"Command: ./philo {number_of_philosophers} {time_to_die} {time_to_eat} {time_to_sleep} [number_of_times_each_philosopher_must_eat] \n"${X}

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME)
				@echo ${GREEN}"Philo Clean Successfully\n"${X}

re:				fclean all

.PHONY:			all clean fclean re project
