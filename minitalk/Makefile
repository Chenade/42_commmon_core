NAME		= minitalk

SERVER 		= server
CLIENT 		= client

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

SRC_SERVER	=	server.c
OBJS_SERVER	=	$(addprefix $(OBJS_DIR)/, $(SRC_SERVER:.c=.o))

SRC_CLIENT	=	client.c
OBJS_CLIENT	=	$(addprefix $(OBJS_DIR)/, $(SRC_CLIENT:.c=.o))

$(NAME):		$(CLIENT) $(SERVER)
				@echo "\033[92mMiniTalk Compile Successfully\n\033[0m"

$(LIBFT):
				$(MAKE) -C $(LIBFT_DIR) all
				mv $(LIBFT_DIR)/$(LIBFT) .
				$(MAKE) -C $(LIBFT_DIR) fclean
				@echo "\033[92mLibft Compile Successfully\n\033[0m"

$(CLIENT):		$(LIBFT) $(OBJS_CLIENT)
				$(CC) $(OBJS_CLIENT) $(CFLAGS) $(CLIBS) -o $(CLIENT)
				@echo "\033[92mClient Compile Successfully\n\033[0m"

$(SERVER):		$(LIBFT) $(OBJS_SERVER)
				$(CC) $(OBJS_SERVER) $(CFLAGS) $(CLIBS) -o $(SERVER)
				@echo "\033[92mServer Compile Successfully\n\033[0m"


$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

clean:
				$(RM) $(OBJS_DIR)
				@echo ""

fclean:			clean
				$(RM) $(LIBFT)
				@echo "\033[92mLibft Clean Successfully\033[0m"
				$(RM) $(SERVER)
				@echo "\033[92mServer Clean Successfully\033[0m"
				$(RM) $(CLIENT)
				@echo "\033[92mClient Clean Successfully\n\n\033[0m"

re:				fclean all

.PHONY:			all clean fclean re
