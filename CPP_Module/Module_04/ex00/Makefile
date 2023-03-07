
NAME		=	Polymorphism

RM			=	rm -rf

CC			=	c++

CFLAGS		=	-Wall -Werror -Wextra
CFLAGS		+=	-std=c++98
CFLAGS		+=	-g3 -MMD

SRCS		=	Animal.cpp \
				Dog.cpp \
				Cat.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp \
				main.cpp

OBJS_DIR	=	objs

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o:%.cpp
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean
				make all

.PHONY:			all clean fclean re